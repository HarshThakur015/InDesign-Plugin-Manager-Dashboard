#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <openssl/sha.h>

class User {
private:
    std::string username;
    std::string hashedPassword;

public:
    User(const std::string& username, const std::string& password) 
        : username(username) {
        this->hashedPassword = hashPassword(password);
    }

    User(const std::string& username, const std::string& hashedPassword, bool isHashed)
        : username(username), hashedPassword(hashedPassword) {}

    std::string getUsername() const { return username; }
    std::string getHashedPassword() const { return hashedPassword; }

    static std::string hashPassword(const std::string& password) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, password.c_str(), password.length());
        SHA256_Final(hash, &sha256);

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return ss.str();
    }

    bool verifyPassword(const std::string& password) const {
        return hashedPassword == hashPassword(password);
    }
};

class AuthSystem {
private:
    std::string filename;
    std::vector<User> users;

    void loadUsers() {
        users.clear();
        std::ifstream file(filename);
        if (!file.is_open()) {
            return; // File doesn't exist yet, which is fine
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string username, hashedPassword;
            if (iss >> username >> hashedPassword) {
                users.emplace_back(username, hashedPassword, true);
            }
        }
        file.close();
    }

    void saveUsers() {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file for writing: " + filename);
        }

        for (const auto& user : users) {
            file << user.getUsername() << " " << user.getHashedPassword() << std::endl;
        }
        file.close();
    }

    bool userExists(const std::string& username) const {
        return std::any_of(users.begin(), users.end(),
            [&username](const User& user) {
                return user.getUsername() == username;
            });
    }

public:
    AuthSystem(const std::string& filename = "users.txt") : filename(filename) {
        loadUsers();
    }

    bool registerUser(const std::string& username, const std::string& password) {
        if (userExists(username)) {
            return false; // Username already exists
        }

        users.emplace_back(username, password);
        saveUsers();
        return true;
    }

    bool loginUser(const std::string& username, const std::string& password) {
        auto it = std::find_if(users.begin(), users.end(),
            [&username](const User& user) {
                return user.getUsername() == username;
            });

        if (it != users.end()) {
            return it->verifyPassword(password);
        }
        return false;
    }

    void displayUsers() const {
        std::cout << "\nRegistered users:" << std::endl;
        for (const auto& user : users) {
            std::cout << "Username: " << user.getUsername() 
                      << ", Hashed Password: " << user.getHashedPassword() << std::endl;
        }
    }
};

void displayMenu() {
    std::cout << "\n=== Login & Registration System ===" << std::endl;
    std::cout << "1. Register" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Display Users (Debug)" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    try {
        AuthSystem authSystem;

        int choice;
        std::string username, password;

        while (true) {
            displayMenu();
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    std::cout << "Enter username: ";
                    std::cin >> username;
                    std::cout << "Enter password: ";
                    std::cin >> password;

                    if (authSystem.registerUser(username, password)) {
                        std::cout << "Registration successful!" << std::endl;
                    } else {
                        std::cout << "Registration failed! Username already exists." << std::endl;
                    }
                    break;
                }
                case 2: {
                    std::cout << "Enter username: ";
                    std::cin >> username;
                    std::cout << "Enter password: ";
                    std::cin >> password;

                    if (authSystem.loginUser(username, password)) {
                        std::cout << "Login successful!" << std::endl;
                    } else {
                        std::cout << "Invalid credentials!" << std::endl;
                    }
                    break;
                }
                case 3: {
                    authSystem.displayUsers();
                    break;
                }
                case 4: {
                    std::cout << "Goodbye!" << std::endl;
                    return 0;
                }
                default: {
                    std::cout << "Invalid choice! Please try again." << std::endl;
                    break;
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

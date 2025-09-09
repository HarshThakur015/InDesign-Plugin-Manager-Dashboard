# 🚀 C++ Login & Registration System (Future Plugin-Based App)

A secure, object-oriented C++ console application for user registration and login with file-based storage and SHA256 password hashing.
This project starts small but is designed to **scale into a plugin-driven, cross-platform application** with a modern **UI/UX**.

---

## ✨ Current Features

* **Object-Oriented Design**: Uses `User` and `AuthSystem` classes
* **Secure Password Storage**: Passwords are hashed using SHA256 before storage
* **File-Based Storage**: User data stored in `users.txt`
* **Cross-Platform**: Works on Windows, Linux, and macOS
* **Duplicate Prevention**: Stops registration with existing usernames
* **Modern C++**: Written with C++17 best practices

---

## 📈 Future Roadmap

This project is **not just a console app** — it’s the foundation for a **scalable C++ software system**.

### 🔹 Phase 1 (✅ Done)

* Console-based login & registration
* File-based storage
* SHA256 password hashing

### 🔹 Phase 2 (In Progress)

* **Refactor into modular plugin architecture** (similar to InDesign plugins)
* Each feature (auth, storage, UI) will be a **separate module**
* Allow dynamic loading/unloading of features at runtime

### 🔹 Phase 3

* **Database Integration**

  * Move from flat files to **SQLite/MySQL/PostgreSQL**
  * Add migration support

### 🔹 Phase 4

* **UI/UX Layer**

  * Replace console with a GUI (Qt / ImGui / Electron bridge)
  * Responsive, cross-platform design
  * Intuitive authentication screens

### 🔹 Phase 5

* **Advanced Plugin System**

  * Extendable with 3rd-party plugins
  * Example plugins:

    * User analytics
    * Role-based access control
    * Activity logging

---

## 🛠️ Tech Stack

* **Core:** Modern C++ (C++17+)
* **Security:** OpenSSL (SHA256 hashing)
* **Build System:** CMake
* **Planned UI:** Qt (C++) or Dear ImGui
* **Planned Plugins:** C++ dynamic libraries (DLL/.so)

---

## 🚦 Setup & Build

### Dependencies

* C++17 compiler (GCC 7+, Clang 5+, MSVC 2017+)
* CMake 3.10+
* OpenSSL (for hashing)

### Install Dependencies

#### Windows

```bash
vcpkg install openssl
```

#### Ubuntu/Debian

```bash
sudo apt-get install libssl-dev
```

#### macOS

```bash
brew install openssl
```

### Build

```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

### Run

* **Windows:** `build\bin\login_system.exe`
* **Linux/macOS:** `build/bin/login_system`

---

## 📂 Project Structure

```
📦 C++ Login System
 ┣ 📜 main.cpp         # Entry point (console UI)
 ┣ 📜 User.h/.cpp      # User data + hashing
 ┣ 📜 AuthSystem.h/.cpp# Auth logic + file I/O
 ┣ 📜 CMakeLists.txt   # Build config
 ┗ 📜 users.txt        # Stored user data (auto-generated)
```

---

## 🔒 Security Highlights

* SHA256 password hashing
* No plain-text password storage
* Input validation to prevent invalid entries
* Roadmap includes **salting & stronger encryption**

---

## 🌟 Why This Project?

This project is a **learning + showcase project** that:

* Demonstrates **C++ OOP, file handling, and security practices**
* Evolves into a **cross-platform plugin system** (aligning with professional SDK/plugin development like Adobe InDesign)
* Adds **UI/UX** to move from console → GUI software
* Shows a clear path of **escalation from simple to enterprise-level project**

---

## 📌 Next Steps

* [ ] Refactor into plugin-based architecture
* [ ] Integrate database storage
* [ ] Build Qt GUI
* [ ] Add plugin examples (analytics, roles, logs)

---

🔗 **Long-term vision**: A full-featured **C++ authentication framework with plugin support**, bridging **systems programming** and **UI/UX application development**.

---

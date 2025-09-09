cmake_minimum_required(VERSION 3.10)
project(LoginSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Add executable
add_executable(login_system main.cpp)

# Link OpenSSL libraries
target_link_libraries(login_system OpenSSL::SSL OpenSSL::Crypto)

# Set output directory
set_target_properties(login_system PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Platform-specific settings
if(WIN32)
    # Windows specific settings
    target_compile_definitions(login_system PRIVATE _CRT_SECURE_NO_WARNINGS)
elseif(UNIX)
    # Linux/Unix specific settings
    target_compile_definitions(login_system PRIVATE _POSIX_C_SOURCE=200809L)
endif()

# Compiler-specific settings
if(MSVC)
    target_compile_options(login_system PRIVATE /W4)
else()
    target_compile_options(login_system PRIVATE -Wall -Wextra -Wpedantic)
endif()

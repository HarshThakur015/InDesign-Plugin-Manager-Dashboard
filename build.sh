#!/bin/bash

# Build script for Login System
echo "Building Login System..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build . --config Release

echo "Build completed! Executable is in build/bin/"

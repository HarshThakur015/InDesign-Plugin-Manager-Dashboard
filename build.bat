@echo off

REM Build script for Login System (Windows)

echo Building Login System...

REM Create build directory
if not exist build mkdir build
cd build

REM Configure with CMake
cmake ..

REM Build the project
cmake --build . --config Release

echo Build completed! Executable is in build\bin\
pause

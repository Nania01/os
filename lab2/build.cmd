@echo off
echo --- Updating sources ---
git pull origin main

echo --- Configuring CMake ---
if not exist build mkdir build
cd build
cmake -G "MinGW Makefiles" ..

echo --- Compiling project ---
cmake --build .

echo --- Running ---
TestUtility.exe
cd ..
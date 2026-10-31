#!/bin/bash
echo "--- Updating sources ---"
git pull origin main

echo "--- Configuring CMake ---"
mkdir -p build
cd build
cmake ..

echo "--- Compiling project ---"
make

echo "--- Running ---"
./TestUtility
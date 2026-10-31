#!/bin/bash
echo "--- Обновление исходников ---"
git pull origin main

echo "--- Настройка CMake ---"
mkdir -p build
cd build
cmake ..

echo "--- Компиляция проекта ---"
make

echo "--- Запуск ---"
./HelloWorld

#!/usr/bin/env bash

clang++ -std=c++20 $@ -o main.out
echo ""
./main.out
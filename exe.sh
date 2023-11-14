#!/usr/bin/env bash

clang++ -std=c++20 $@ -o ./main
echo ""
./main
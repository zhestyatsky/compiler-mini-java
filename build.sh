#!/usr/bin/env bash

cmake . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build -j 2 -t compiler-mini-java

#!/bin/bash

code="$PWD"
opts="-Wpedantic -Wall -std=c99"
cd . > /dev/null
clang $opts $code/main.c -o brainstruck
cd $code > /dev/null

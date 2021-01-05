#!/bin/bash

code="$PWD"
opts="-Wpedantic -Wall -std=c99"
cd . > /dev/null
clang $opts $code/main.c -o brainstruck
clang $opts -s -Os -fno-ident -ffunction-sections -fdata-sections -Wl,--gc-sections -fno-unwind-tables -fno-asynchronous-unwind-tables -Wl,-z,norelro  $code/minimal_binary.c -o brainstruck_minimal
strip -S --strip-unneeded --remove-section=.note.gnu.gold-version --remove-section=.comment --remove-section=.note --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag brainstruck_minimal
cd $code > /dev/null

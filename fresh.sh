#!/bin/bash
clear

make clean >/dev/null 2>&1
make >/dev/null && ./bin/output

echo

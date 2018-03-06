#!/bin/sh
../bin/rshell << 'EOF'
test
test temp
[temp]
test -f ../src/shell.cpp
[-d ../bin]
[ -d ../bin ]
test -e ../src/base.cpp
test -e ../src/Base.h
[-f ../src/Base.cpp]
test -d ../bin && echo A
[-f ../src] && echo A
[-e blah] || echo B
[blah]; [-d ../tests]; [-f ../src/shell.cpp]; test; exit
EOF

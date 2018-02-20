#!/bin/sh
../bin/rshell << 'EOF'
ls -a; echo it worked
ls || echo work || echo nope
ls || echo work && echo nope
echo A && echo bin
ls && echo this is || echo dont
exit
EOF
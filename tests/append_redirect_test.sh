#!/bin/sh

../bin/rshell << 'EOF'
echo hello world > tempA
echo riverside > tempB
ls
cat < tempA && cat < tempB
echo hola >> tempA && cat < tempA
echo command >> tempC; cat < tempC
(echo A >> tempB || echo nope) && cat < tempB
fakeCommand >> tempA || echo nice try kid
exit
EOF

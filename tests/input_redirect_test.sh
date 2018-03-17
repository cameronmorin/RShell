#!/bin/sh

../bin/rshell << 'EOF'
echo hello world > tempA
echo riverside > tempB
ls
cat < tempA
cat < tempB && echo A
echo A && cat < tempA
echo ME || cat < tempC
echo nope && cat < tempC
cat < tempB; echo C && cat < tempA
(echo Hi && cat < tempB) && echo Goodbye
fake < tempA
cat < fakeFile
cat < fakeFIle && echo B; echo did it work
rm tempA
rm tempB
exit
EOF

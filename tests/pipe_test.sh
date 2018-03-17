#!/bin/sh
../bin/rshell << 'EOF'
echo test me > tempA
echo no test me > tempB
cat < tempA | tr a-z A-Z | tee newOut | tr A-Z a-z > newerOut
ls | grep temp
rm tempB | ls
echo A || ls | grep A
echo A && ls | grep A
(ls | grep temp) && echo hey it works
echo test > tempB;cat < tempB | tr a-z A-Z > newOut
cat < newOut
cat < tempA
cat < tempB
cat < newerOut
exit
EOF

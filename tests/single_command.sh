#!/bin/sh
../bin/rshell << 'EOF'
echo hello world
echo we are testing rshell
echo let the testing begin
echo
touch testfile01
ls
mkdir testDir01
ls
rm testfile01
ls
rmdir testDir01
ls
echo now we are going to test some failures
who
what
1
lb
gut status
diff
-0
ls -jj
cat penut
exit
EOF
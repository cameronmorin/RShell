#!/bin/sh
../bin/rshell << 'EOF'
echo the slash in bash script will output but disregard
echo A \#echo bin
echo A \#echo DD
echo tru && echo blue \#echo no
echo A \#### echo hi
ls \# echo hi
echo \#kkkkk
exit
EOF
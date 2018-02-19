#!/bin/sh

../bin/rshell << "EOF"
echo exiting0
exit
EOF

../bin/rshell << 'EOF1'
ls
ls -a
echo exiting1
exit
EOF1

../bin/rshell << "EOF2"
l
echo exiting3
exit
EOF2

../bin/rshell << "EOF3"
cat penut
echo wait
echo exiting4
exit
EOF3
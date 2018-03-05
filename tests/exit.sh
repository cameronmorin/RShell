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
cal
echo wait
echo exiting4
exit
EOF3

../bin/rshell << "EOF4"
echo try; exit
EOF4

../bin/rshell << "EOF5"
echo penut && exit
EOF5

../bin/rshell << "EOF6"
exit #just exit
EOF6

../bin/rshell << 'EOF'
echo A || exit \#A
exit
EOF


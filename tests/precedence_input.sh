#!/bin/sh
../bin/rshell << 'EOF'
echo A && echo B || echo C && echo D
(echo A && echo B) || (echo C && echo D)
((echo A && echo B) || echo C
(echo A && echo B)) || echo C
(echo A; echo B) || (echo C; (echo D && echo E) || echo F)
echo A && (echo B || echo C) && echo D
exit
EOF

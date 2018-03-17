#!/bin/sh

../bin/rshell << 'EOF'
cat < tempA; cat < tempB
echo hello world > tempA && cat < tempA
echo riverside > tempB;cat < tempB && echo told you it works
echo hello || echo yeet > tempA
cat < tempA
echo this && echo that > tempA
cat < tempA
fake < tempA; cat < tempA
(echo A && echo B) < tempB
cat < tempB
(echo A && fake) < tempA; cat < tempA
exit
EOF

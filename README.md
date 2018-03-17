# assignment3

In this assignment, I implemented piping and redirection (both output and input).

Piping allows for the user to string together different inputs to serve their result as
the input for the following function.

The input redirection allows for the input of an action to be redirected into a desired
file.

The output redirection allows for output to be redirected into a given file.
When using single output redirection, the input overrides any data that was 
held in the file before redirection. In comparison, double output redirection 
appends the new input to the data previously stored in the file.


In my code, I found a few minor bugs:

1) If the user inputs a test function style input, but does
   not give appropriate syntax, there may be some error 
   depending on the exact input due to very strict
   string parsing.

2) In assignment 2, my previous partner designed our parsing. 
   since then I have been able to add the new connectors to 
   the parsing but I am unable to fix an issue where it breaks
   up a string of commands when a number or special character
   is introduced. That being said, when testing, please use file
   names that do not have numbers in the name. If files without numbers
   are used, then the algorithm works completely (to my knowledge).

3) My scripts sometime malfunction when I call them, but
   all of the individual cases within the scripts have been
   tested and all work to my correctness.

My partner withdrew from the class in the middle of week 8, so the 
remainder of the assignments will be completed by myself only.

## Cameron Morin

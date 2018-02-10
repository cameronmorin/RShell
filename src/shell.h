#ifndef __SHELL_H__
#define __SHELL_H__
#include<iostream>
using namespace std;

class shell {
    private:

        // user string for list of commands
        string UserInput;

    public:

        // constructor
        shell() : UserInput() { }

        // run() will contain the loop for running the command prompt 
        //  and using all other functionality from other classes
        void run();

        // infixToPostfix() parses the userinput to the correct notation.
        // Allows the input to be built into a tree
        string infixToPostfix(string usrCommands);

        // buildTree() builds the arithemtic tree using the composite class
        // called connectors and leafs beign the command class which will all
        // be under the umbrella of the Base class
        void buildTree(string postUsrCommands);

};

#endif // __SHELL_H__

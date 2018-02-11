#ifndef __SHELL_H__
#define __SHELL_H__
#include<iostream>
#include "Base.h"
#include <vector>
using namespace std;

class shell {
    private:

        // user string for list of commands
        string UserInput;

        // vector containing infix order of commands and operators
        vector<Base*> inputVector;

    public:

        // constructor
        shell() : UserInput(), inputVector() { }

        // run() will contain the loop for running the command prompt 
        //  and using all other functionality from other classes
        void run();

        // takes user input and parses individual commands and operators
        // creates base pointers from them and places them into a vector
        void convertInput(string UserInput, vector<Base*>& inputVector);

        // converts a infix notation vector of Base* into postfix notation
        void convertToPostfix(vector<Base*>& inputVector);

        // uses Base* vector to implement an arithematic style tree
        // returns pointer to root of the tree
        Base* buildTree(vector<Base*> inputVector);
		
		//used in the convertToPostfix function in order to determine 
		//the "priority" of the current connector
		int priority(Base* connector);
};

#endif // __SHELL_H__

#include "shell.h"
#include <stack>
#include <iostream>
#include <string>
#include <regex>
#include <stack>
#include <iterator>
#include <boost/regex.hpp>

using namespace std;


shell::~shell() {

    if (inputVector.empty()) {
        return;
    }

    for (unsigned i = 0; i < inputVector.size(); ++i) {
        Base* ptr = inputVector.at(i);
        delete ptr;
        ptr = 0;
    }
}

void shell::run() {

    while (true) {
        Base* root = 0;
        cout << "$ ";
        getline(cin, UserInput);

        convertInput(UserInput, commands, inputVector);

        root = buildTree(inputVector);

        if (root->evaluate() == -1) {
            cout << "exiting shell" << endl;
            return;
        }
        delete this;
    }

    return;
}

void shell::convertInput(string UserInput, vector<string>& commands, 
                            vector<Base*>& inputVector) {

    vector<string> v;
    // regular expression to parse through the user input
    regex reg1("(;|\\|{2}|&{2}|#)|([^\\s][^;|\\|{2}|&{2}|]+)");
    regex_token_iterator<string::iterator> it{UserInput.begin(), UserInput.end(), reg1};
    regex_token_iterator<string::iterator> rit;

    // pushes back parsed info
    while (it != rit) {
        v.push_back(*it);
        ++it;
    }

    // reads through vector to eliminate comments from executions
    for (unsigned i = 0; i < v.size(); ++i) {
        if (v.at(i) == "#") {
            break;
        }
        else {
            commands.push_back(v.at(i));
        }
    }

    // go through and convert all inputs into base pointers
    for (unsigned i = 0; i < commands.size(); ++i) {
        if (commands.at(i) == "||") {
            orConnector* Or = new orConnector();
            inputVector.push_back(Or);
        }
        else if (commands.at(i) == "&&") {
            ANDConnector* AND = new ANDConnector();
            inputVector.push_back(AND);
        }
        else if (commands.at(i) == ";") {
            semiColonConnector* semi = new semiColonConnector();
            inputVector.push_back(semi);
        }
        else {
            command* cmd = new command(commands.at(i));
            inputVector.push_back(cmd);
        }
    }
}


Base* shell::buildTree(vector<Base*> inputVector) {
	Base* toReturn = 0;
	vector<Base*> reversePolish;
	stack<Base*> connectorStack;	

	//Check for empty vector
	if (inputVector.empty()) {
		return toReturn;
	}


	for (unsigned i = 0; i < inputVector.size(); ++i) {
		//If connector, evaluate. Else, push_back reversePolish
		if (inputVector.at(i)->isConnector()) {
			//Priority nonsense
			while(!connectorStack.empty() && inputVector.at(i)->getPriority() < connectorStack.top()->getPriority()) {
				reversePolish.push_back(connectorStack.top());
				connectorStack.pop();
			}
			connectorStack.push(inputVector.at(i));
		}
		else {
			//Is command
			reversePolish.push_back(inputVector.at(i));
		}
	}
	
	while(!connectorStack.empty()) {
		reversePolish.push_back(connectorStack.top());
		connectorStack.pop();
	}

	//ReversePolishNotation Vector built above
	//Now build the tree
	stack<Base*> Tree;
	
	for (unsigned j = 0; j < reversePolish.size(); ++j) {
		if (reversePolish.at(j)->isConnector()) {
			reversePolish.at(j)->setRightChild(Tree.top());
			Tree.pop();
			reversePolish.at(j)->setLeftChild(Tree.top());
			Tree.pop();
		}
		Tree.push(reversePolish.at(j));
	}	
	return Tree.top();	
}

/*
int shell::priority(Base* connector) {
	//FIXME
	return 0;
}
*/

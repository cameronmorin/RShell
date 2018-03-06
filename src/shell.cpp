#include "shell.h"
#include <stack>
#include <iostream>
#include <string>
#include <regex>
#include <stack>
#include <iterator>
#include <regex>

using namespace std;

void shell::run() {

    Base* root = 0;

    // loopin for shell command prompt
    while (true) {
        cout << "$ ";
        getline(cin, UserInput);

        if (UserInput == "") {
            continue;
        }

        convertInput(UserInput, commands, inputVector);

        root = buildTree(inputVector);
		
		//Check for uneven amount of precedence operators
		if (root == 0) {
			cout << "Entered uneven amount of precedence operators. Please try again" << endl;
		}
        // if -1 command was exit
        else if (root->evaluate() == -1) {
            return;
        }

        // clears vectors to restart loop with clean slate
        inputVector.clear();
        commands.clear();
    }

    return;
}

void shell::convertInput(string UserInput, vector<string>& commands, vector<Base*>& inputVector) {

    vector<string> v;

    // regular expression to parse through the user input
    regex reg1("(;|\\|{2}|&{2}|#|\\)|\\()|([^\\s][^;|\\|{2}|&{2}|#|\\)|\\(]*)"); 
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

	//Convert all test calls to the "test" style
	for (unsigned i = 0; i < commands.size(); ++i) {
		if (commands.at(i).at(0) == '[') {
			commands.at(i).replace(0,1, "test");
			commands.at(i).resize(commands.at(i).size() - 2);
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
		else if (commands.at(i) == "(") {
			leftPrecedence* left = new leftPrecedence();
			inputVector.push_back(left);
		}
		else if (commands.at(i) == ")") {
			rightPrecedence* right = new rightPrecedence();
			inputVector.push_back(right);
		}
        else {
            command* cmd = new command(commands.at(i));
            inputVector.push_back(cmd);
        }
    }
}


Base* shell::buildTree(vector<Base*> inputVector) {
	Base* toReturn = 0;
	int precedenceCount = 0;
	vector<Base*> reversePolish;
	stack<Base*> connectorStack;	

	//Check for empty vector
	if (inputVector.empty()) {
		return toReturn;
	}

	for (unsigned i = 0; i < inputVector.size(); ++i) {
		if (inputVector.at(i)->isConnector()) {
			// checking left precedence
			if (inputVector.at(i)->isLeftP()) {
				connectorStack.push(inputVector.at(i));
				precedenceCount++;
			}
			// checking right precedence
			else if (inputVector.at(i)->isRightP()) {
				while(!connectorStack.top()->isLeftP()) {
					reversePolish.push_back(connectorStack.top());
					connectorStack.pop();
				}
				connectorStack.pop();
				precedenceCount--;
			}
			// Connector is not a precedence operator
			else {
				while(!connectorStack.empty() && inputVector.at(i)->getPriority() <= connectorStack.top()->getPriority()) {
					if (inputVector.at(i)->getPriority() == connectorStack.top()->getPriority() && inputVector.at(i)->getPriority() == 2) {
						//Semicolon connectors
						break;
					}
					else {
						reversePolish.push_back(connectorStack.top());
						connectorStack.pop();
					}
				}
				connectorStack.push(inputVector.at(i));
			}
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

	// ReversePolishNotation Vector built above
	// Now build the tree
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
	
	//Check for odd number of precedence operators
	if (precedenceCount != 0) {
		return 0;
	}

	return Tree.top();	
}

/* for future implementation
int shell::priority(Base* connector) {
	//FIXME
	return 0;
}
*/

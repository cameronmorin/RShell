#include "shell.h"
#include <stack>
#include <iostream>
#include <regex>
#include <stack>

using namespace std;

void shell::run() {

    //Base* root = 0;

    cout << "$ ";
    getline(cin, UserInput);

    convertInput(UserInput, commands);

    //convertToPostfix(inputVector);

    //root = buildTree(inputVector);

    //root->evaluate();

    return;
}

void shell::convertToPostfix(vector<Base*>& inputVector) {
    // FIXME

}

void shell::convertInput(string UserInput, vector<string>& commands) {

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
			while(inputVector.at(i)->getPriority() < connectorStack.top()->getPriority()) {
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

	//ReversePolishNotation Vector built above
	//Now build the tree
	stack<Base*> Tree;
	
	for (unsigned j = 0; j < reversePolish.size(); ++j) {
		if (!reversePolish.at(j)->isConnector()) {
			Tree.push(reversePolish.at(j));
		}
		else {
			reversePolish.at(j)->setRightChild(Tree.top());
			Tree.pop();
			reversePolish.at(j)->setLeftChild(Tree.top());
			Tree.pop();
			Tree.push(reversePolish.at(j));
		}
	}	
	return Tree.top();	
}

/*
int shell::priority(Base* connector) {
	//FIXME
	return 0;
}
*/

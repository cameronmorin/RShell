#include "shell.h"
#include <stack>
#include <iostream>
#include <regex>

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
    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i) == "#") {
            break;
        }
        else {
            commands.push_back(v.at(i));
        }
    }


}


Base* shell::buildTree(vector<Base*> inputVector) {
    Base* rocket = 0;
    return rocket;
}


int shell::priority(Base* connector) {
	//FIXME
	return 0;
}

#include "shell.h"
#include <stack>
#include <iostream>

using namespace std;

void shell::run() {

    Base* root = 0;

    cout << "$ ";
    getline(cin, UserInput);

    convertInput(UserInput, inputVector);

    convertToPostfix(inputVector);

    root = buildTree(inputVector);

    root->evaluate();

    return;
}

void shell::convertToPostfix(vector<Base*>& inputVector) {
    // FIXME

}

void shell::convertInput(string UserInput, vector<Base*>& inputVector) {
    // FIXME

}


Base* shell::buildTree(vector<Base*> inputVector) {
    Base* rocket = 0;
    return rocket;
}

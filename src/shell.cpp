#include "shell.h"
#include <iostream>

using namespace std;

void shell::run() {

    Base* root = 0;

    cout << "$";
    getline(cin, UserInput);

    infixToPostfix(UserInput);

    root = buildTree(UserInput);

    root->evaluate();





    return;
}

void shell::infixToPostfix(string& usrCommands) {

}

Base* shell::buildTree(string PostUsrCommands) {
    Base* rocket = 0;
    return rocket;
}

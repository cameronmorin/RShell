#include "Base.h"
#include <regex>
#include <limits>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

using namespace std;

void command::setLeftChild(Base* left) {
	cout << "ERROR: Tried setting a child to a command" << endl;
	return;
}

void command::setRightChild(Base* right) {
	cout << "ERROR: Tried setting a child to a command" << endl;
	return;
}


void semiColonConnector::setLeftChild(Base* left) {
	this->lhs = left;
	return;
}

void semiColonConnector::setRightChild(Base* right) {
	this->rhs = right;
	return;
}


void orConnector::setLeftChild(Base* left) {
	this->lhs = left;
	return;
}

void orConnector::setRightChild(Base* right) {
	this->rhs = right;
	return;
}


void ANDConnector::setLeftChild(Base* left) {
	this->lhs = left;
	return;
}

void ANDConnector::setRightChild(Base* right) {
	this->rhs = right;
	return;
}



///////////////////////////////////////////////////////////////

int semiColonConnector::evaluate() {
    int temp = lhs->evaluate();

    if (temp == -1) {
        return temp;
    }
    return rhs->evaluate();
}


int orConnector::evaluate() {
    int temp = lhs->evaluate();

    if (temp == -1) {
        return temp;
    }
    else if (temp == 0) {
        return rhs->evaluate();
    }
    else {
        return temp;
    }
}


int ANDConnector::evaluate() {
    int temp = lhs->evaluate();

    if (temp == -1) {
        return temp;
    }
    else if (temp == 1) {
        return rhs->evaluate();
    }
    else {
        return temp;
    }

}

int command::evaluate() {

    vector<string> v = parseCommand(commandString);

    if (commandString == "exit") {
        return -1;
    }

    pid_t pid = fork();
    pid_t w;

    int status;
    // temporary limit value 500 coded till fix comes in
    char* args[500];
    args[v.size()] = 0;
    
    for (unsigned i = 0; i < v.size(); ++i) {
        args[i] = (char*)v.at(i).c_str();
    }

    if (pid < 0) {
        cout << "forking child failed" << endl;
        exit(1);
    }
    else if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            cout << "-bash: " << args[0] << ": command not found" << endl;
            exit(1);
        }
    }
    else {
        w = waitpid(pid, &status, 0);

        if (w == -1) {
            cout << "Issue with waitpid" << endl;
            exit(EXIT_FAILURE);
        }
        if (WEXITSTATUS(status) == 0) {
            return 1;
        }
    }
        return 0;
}

vector<string> command::parseCommand(string s) {
    vector<string> v;
    regex reg1("([^\\s]+)");
    regex_token_iterator<string::iterator> it{s.begin(), s.end(), reg1};
    regex_token_iterator<string::iterator> rit;

    while (it != rit) {
        v.push_back(*it);
        ++it;
    }

    return v;
}


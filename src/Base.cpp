#include "Base.h"
#include <regex>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>

using namespace std;

void command::setLeftChild(Base* left) {
	cout << "ERROR: Tried setting a child to a command" << endl << endl;
	throw invalid_argument("Tried setting child to a command node");
	return;
}

void command::setRightChild(Base* right) {
	cout << "ERROR: Tried setting a child to a command" << endl << endl;
	throw invalid_argument("Tried setting child to a command node");
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

void pipeConnector::setLeftChild(Base* left) {
	this->lhs = left;
	return;
}

void pipeConnector::setRightChild(Base* right) {
	this->rhs = right;
	return;
}

void inputRedirect::setLeftChild(Base* left) {
	this->lhs = left;
	return;
}

void inputRedirect::setRightChild(Base* right) {
	this->rhs = right;
	return;
}

void singleOutput::setLeftChild(Base* left) {
	this->lhs = left;
	return;
}

void singleOutput::setRightChild(Base* right) {
	this->rhs = right;
	return;
}

void doubleOutput::setLeftChild(Base* left) {
	this->lhs = left;
	return;
}

void doubleOutput::setRightChild(Base* right) {
	this->rhs = right;
	return;
}

void leftPrecedence::setLeftChild(Base* left) {
	cout << "ERROR: Tried setting a child to a precedence operator" << endl;
	throw invalid_argument("Tried setting child to a precedence operator");
	return;
}

void leftPrecedence::setRightChild(Base* right) {
	cout << "ERROR: Tried setting a child to a precedence operator" << endl;
	throw invalid_argument("Tried setting child to a precedence operator");
	return;
}

void rightPrecedence::setLeftChild(Base* left) {
	cout << "ERROR: Tried setting a child to a precedence operator";
	throw invalid_argument("Tried setting child to a precedence operator");
	return;
}

void rightPrecedence::setRightChild(Base* right) {
	cout << "ERROR: Tried setting a child to a precedence operator";
	throw invalid_argument("Tried setting child to a precedence operator");
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

int pipeConnector::evaluate() {
	//FIXME
	//Implement dup() and pip() calls here
	return 1;
}

int inputRedirect::evaluate() {
	int in;
	pid_t pid;
	int statVal;
	
	string right = this->rhs->getString();
	const char* chP = right.c_str();
	pid = fork();
	
	if (!pid) {
		in = open(chP, O_RDONLY);
		if (in == -1) {
			perror("open");
			exit(EXIT_FAILURE);
			return 0;	
		}
		if (dup2(in,0) == -1) {
			perror("dup2");
			exit(EXIT_FAILURE);
			return 0;
		}
		if (close(in) == -1) {
			perror("close");
			exit(EXIT_FAILURE);
			return 0;
		}
		if (lhs->evaluate() == 0) {
			exit(EXIT_FAILURE);
			return 0;
		}
		
		exit(EXIT_SUCCESS);	
	} 
	else if (pid < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
		return 0;
	}
	else {
		do {
			waitpid(pid, &statVal, 0);
		} while (!WIFEXITED(statVal));
	}

	if (!WEXITSTATUS(statVal)) {
		return 1;
	}	
	
	return 0;
}

int singleOutput::evaluate() {
	//FIXME
	//Implement dup() and pip() calls here
	return 1;
}

int doubleOutput::evaluate() {
	//FIXME
	//Implement dup() and pip() calls here
	return 1;
}

void command::echoHelp(string& commandString) {
	if (commandString.substr(0,4) == "echo") {
		if (commandString.substr(5,1) == "\"") {
			cout << "Found the quotation marks." << endl;
			cout << "FIXME:: Need to finish echo implementation later." << endl;
		}
	}
}

int command::evaluate() {

    // used for long listed commands spaced out
    vector<string> v = parseCommand(commandString);
	
	echoHelp(commandString);	

    // cases for exiting the shell
    if (commandString == "exit") {
        return -1;
    }
    if (commandString.find("exit") != string::npos) {
        return -1;
    }

		
	//Implement test function call here!!!!!!
	if (commandString.substr(0,4) == "test") {
		if (commandString.at(commandString.size() - 1) == ' ') {
			commandString.pop_back();
		}
		//
		if (test(commandString)) {
			//Evaluates to true
			return 1;
		}
		else {
			//Evaluates to false
			return 0;
		}
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
    // forking test cases
    if (pid < 0) {
        perror("forking child failed");
        exit(1);
    }
    else if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            perror("execution failure");
            exit(1);
        }
    }
    else {
        w = waitpid(pid, &status, 0);

        if (w == -1) {
            perror("issue with waitpid");
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

bool Base::test(const string& cmd) {
	struct stat buf;	
	const char* myPath= 0;

	if (cmd == "test") {
		cout << "(TRUE)" << endl;
		return true;
	}
	
	if (cmd.size() > 5 && cmd.at(5) == '-') {
		//Has flag
		myPath = cmd.substr(8,cmd.size()-1).c_str();
		if (stat(myPath, &buf) == 0) {
			//true
			if (cmd.at(6) == 'e') {
				cout << "(TRUE)" << endl;
				return true;
			}
			else if (cmd.at(6) == 'f') {
				//Check for file
				if (S_ISREG(buf.st_mode)) {
					cout << "(TRUE)" << endl;
					return true;
				}
				else {
					cout << "(FALSE)" << endl;
					return false;
				}
			}
			else {
				//Check for directory
				if (S_ISDIR(buf.st_mode)) {
					cout << "(TRUE)" << endl;
					return true;
				}
				else {
					cout << "(FALSE)" << endl;
					return false;
				}
			}
		}
		else {
			//false
			cout << "(FALSE)" << endl;
			return false;
		}
	}
	else {
		//Doesn't have a flag, assume -e flag
		myPath = cmd.substr(5,cmd.size()-1).c_str();
		if (stat(myPath, &buf) == 0) {
			cout << "(TRUE)" << endl;
			return true;
		}
		else {
			cout << "(FALSE)" << endl;
			return false;
		}
	}
	return true;
}

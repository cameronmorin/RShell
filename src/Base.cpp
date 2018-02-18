#include "Base.h"

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

bool semiColonConnector::evaluate() {
    // FIXME
    lhs->evaluate();
    rhs->evaluate();
    return true;
}


bool orConnector::evaluate() {
    // FIXME
    lhs->evaluate();
    rhs->evaluate();
    return true;
}


bool ANDConnector::evaluate() {
    // FIXME
    lhs->evaluate();
    rhs->evaluate();
    return true;
}

bool command::evaluate() {
    // FIXME
    return true;
}


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
bool semiColonConnector::canExecute() {
    // FIXME
    return true;
}

void semiColonConnector::evaluate() {
    // FIXME
    lhs->evaluate();
    rhs->evaluate();
    return;
}

bool orConnector::canExecute() {
    // FIXME
    return true;
}

void orConnector::evaluate() {
    // FIXME
    lhs->evaluate();
    rhs->evaluate();
    return;
}

bool ANDConnector::canExecute() {
    // FIXME
    return true;
}

void ANDConnector::evaluate() {
    // FIXME
    lhs->evaluate();
    rhs->evaluate();
    return;
}

void command::evaluate() {
    // FIXME
    return;
}

bool command::canExecute() {
    // FIXME
    return true;
}

#include "Base.h"

using namespace std;

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

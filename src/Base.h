#ifndef __BASE_H__
#define __BASE_H__
#include <iostream>
using namespace std;

class Base {
    public:
        /* Constructors */
        Base() {}

        /* Pure Virtual Functions */
        virtual void evaluate() = 0;

        // check if it is an operator
        virtual bool isConnector() = 0;

        // check if it is valid to evaluate
        virtual bool canExecute() = 0;
};

class command : public Base {
    private:
        string commandString;

    public:
    // constructors
    command() : commandString() { }
    command(string cmd) : commandString(cmd) { }

    void evaluate();

    bool isConnector() { return false;}

    bool canExecute();

};

class semiColonConnector : public Base {
    private:
        Base* lhs;
        Base* rhs;

    public:
        void evaluate();

        bool isConnector() { return true;}

        bool canExecute();
};

class orConnector : public Base {
    private:
        Base* lhs;
        Base* rhs;

    public:
        void evaluate();

        bool isConnector() { return true;}

        bool canExecute();
};

class ANDConnector : public Base {
    private:
        Base* lhs;
        Base* rhs;

    public:
        void evaluate();

        bool isConnector() { return true;}

        bool canExecute();
};

#endif // __BASE_H__

#ifndef __BASE_H__
#define __BASE_H__
#include <iostream>
#include <vector>
using namespace std;

class Base {
    public:
        /* Constructors */
        Base() {}

        /* Pure Virtual Functions */
        virtual int evaluate() = 0;

        // check if it is an operator
        virtual bool isConnector() = 0;

		// returns the string inside of each
		// base node e.g. "command", ";", etc.
		virtual int getPriority() = 0;
		
		//Set the right child for certain classes
		virtual void setRightChild(Base* right) = 0;

		//Set the left child for certain classes
		virtual void setLeftChild(Base* left) = 0;

		//Checks if the connector is a '('
		virtual bool isLeftP() = 0;

		//Checks if the connector is a ')'
		virtual bool isRightP() = 0;

		//Universal test function
		bool test(const string &cmd);

		//Output function used for testing purposes
		virtual string getString() = 0;
};

class command : public Base {
    private:
        string commandString;

    public:
    	// constructors
    	command() : commandString() { }
    	command(string cmd) : commandString(cmd) { }

    	int evaluate();

    	bool isConnector() { return false;}

		bool isLeftP() { return false;}

		bool isRightP() { return false;}

		int getPriority() { return 0;}

		void setLeftChild(Base* left);

		void setRightChild(Base* right);

		string getString() { return commandString;}

    	// helper functions
    private:
        vector<string> parseCommand(string s);
		void echoHelp(string&);
};

class semiColonConnector : public Base {
    private:
        Base* lhs;
        Base* rhs;

    public:
        int evaluate();

        bool isConnector() { return true;}

		bool isLeftP() { return false;}

		bool isRightP() { return false;}
		
		int getPriority() { return 2;}

		void setLeftChild(Base* left);

		void setRightChild(Base* right);
		
		string getString() { return ";";}
};

class orConnector : public Base {
    private:
        Base* lhs;
        Base* rhs;

    public:
        int evaluate();

        bool isConnector() { return true;}

		bool isLeftP() { return false;}

		bool isRightP() { return false;}

		int getPriority() { return 3;}
	
		void setRightChild(Base* right);

		void setLeftChild(Base* left);
		
		string getString() { return "||";}
};

class ANDConnector : public Base {
    private:
        Base* lhs;
        Base* rhs;

    public:
        int evaluate();

        bool isConnector() { return true;}	
		
		bool isLeftP() { return false;}

		bool isRightP() { return false;}

		int getPriority() { return 3;}

		void setRightChild(Base* right);

		void setLeftChild(Base* left);
		
		string getString() { return "&&";}
};

class pipeConnector : public Base {
	private:
		Base* lhs;
		Base* rhs;
	
	public:
		int evaluate();

		bool isConnector() { return true;}

		bool isLeftP() { return false;}

		bool isRightP() { return false;}

		int getPriority() { return 4;}

		void setRightChild(Base* right);

		void setLeftChild(Base* left);
		
		string getString() { return "|";}
};

class inputRedirect : public Base {
	private:
		Base* lhs;
		Base* rhs;
	
	public:
		int evaluate();

		bool isConnector() { return true;}

		bool isLeftP() { return false;}

		bool isRightP() { return false;}

		int getPriority() { return 4;}

		void setRightChild(Base* right);

		void setLeftChild(Base* left);
		
		string getString() { return ">";}
};

class singleOutput : public Base {
	private:
		Base* lhs;
		Base* rhs;
	
	public:
		int evaluate();

		bool isConnector() { return true;}

		bool isLeftP() { return false;}

		bool isRightP() { return false;}

		int getPriority() { return 4;}

		void setRightChild(Base* right);

		void setLeftChild(Base* left);
		
		string getString() { return "<";}
};

class doubleOutput : public Base {
	private:
		Base* lhs;
		Base* rhs;
	
	public:
		int evaluate();

		bool isConnector() { return true;}

		bool isLeftP() { return false;}

		bool isRightP() { return false;}

		int getPriority() { return 4;}

		void setRightChild(Base* right);

		void setLeftChild(Base* left);
		
		string getString() { return "<<";}
};

class leftPrecedence : public Base {
	public:
		int evaluate() { return 0;}

		bool isConnector() { return true;}

		bool isLeftP() { return true;}

		bool isRightP() { return false;}

		int getPriority() { return 1;}

		void setRightChild(Base* right);

		void setLeftChild(Base* left);
		
		string getString() { return "(";}
};

class rightPrecedence : public Base {
	public:
		int evaluate() { return 0;}

		bool isConnector() { return true;}

		bool isLeftP() { return false;}

		bool isRightP() { return true;}

		int getPriority() { return 1;}

		void setRightChild(Base* right);

		void setLeftChild(Base* left);
		
		string getString() { return ")";}
};

#endif // __BASE_H__

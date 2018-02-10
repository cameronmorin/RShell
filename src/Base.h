#ifndef __BASE_H__
#define __BASE_H__

class Base {
    public:
        /* Constructors */
        Base() {}

        /* Pure Virtual Functions */
        virtual void evaluate() = 0;
};

class command : public Base {
    public:

    void evaluate() { }

};

class semiColonConnector : public Base {
    public:
        void evaluate() { }
};

class orConnector : public Base {
    public:
        void evaluate() { }
};

class ANDConnector : public Base {
    public:
        void evaluate() { }
};

#endif // __BASE_H__

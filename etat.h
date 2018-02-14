//
// Created by Vincent on 13/02/2018.
//
#pragma  once

#include "automate.h"
#include "expr.h"

class Etat {
public:
    Etat(string name);
    virtual ~Etat();
    void print() const;
    virtual bool transition(Automate & automate, Symbole * s) = 0;
protected:
    string name;
};
/*
class E0 : public Etat {
public:
    E0(string name);
    ~E0();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};

class E3 : public Etat {
public:
    E3(string name);
    ~E3();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};

class E4 : public Etat {
public:
    E4(string name);
    ~E4();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};

class E5 : public Etat {
public:
    E5(string name);
    ~E5();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};

class E6 : public Etat {
public:
    E6(string name);
    ~E6();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};

class E7 : public Etat {
public:
    E7(string name);
    ~E7();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};

class E8 : public Etat {
public:
    E8(string name);
    ~E8();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};

class E9 : public Etat {
public:
    E9(string name);
    ~E9();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};
*/

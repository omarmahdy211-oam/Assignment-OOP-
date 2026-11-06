#ifndef REGISTERBANK_H
#define REGISTERBANK_H

#include <iostream>
using namespace std;

class RegisterBank {
private:
    int registers[16] = {};

public:
    void setRegister(int r, int x);
    int getRegister(int r) const;
    void display() const;
};

#endif // REGISTERBANK_H

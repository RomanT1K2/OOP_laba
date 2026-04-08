#pragma once
#include <string>
using namespace std;

class Customer {
private:
    string name;

public:
    Customer(string n);
    void show() const;
    //
    void printType() const {
        cout << "MenuItem\n";
    }
};
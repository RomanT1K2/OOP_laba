#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(string n) : name(n) {}

void Customer::show() const {
    cout << "Customer: " << name << "\n";
}
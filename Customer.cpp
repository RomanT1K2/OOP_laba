#include "Customer.h"
#include <iostream>

Customer::Customer() : Customer("Гість", "Немає номера") {}

Customer::Customer(const std::string& n, const std::string& p)
    : name(n), phone(p) {
}

Customer::~Customer() {
    std::cout << "[Customer] \"" << name << "\" видалений.\n";
}

void Customer::showInfo() const {
    std::cout << "  Клієнт: " << name
        << " | Телефон: " << phone << "\n";
}
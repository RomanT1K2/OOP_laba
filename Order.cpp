#include "Order.h"
#include <iostream>

using namespace std;

Order::Order(Customer c) : customer(c) {}

void Order::addItem(MenuItem* item) {
    items.push_back(item);
}

void Order::showOrder() const {
    double sum = 0;

    customer.show();

    for (auto item : items) {
        item->showInfo();
        sum += item->getPrice();
    }

    cout << "Total: " << sum << " UAH\n";
}
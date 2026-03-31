#pragma once
#include "Dish.h"
#include "Customer.h"
#include <vector>

class Order {
private:
    std::vector<MenuItem*> items;
    Customer customer;

public:
    Order(Customer c);
    void addItem(MenuItem* item);
    void showOrder() const;
};
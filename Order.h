#pragma once

#include <vector>
#include "Dish.h"
#include "Customer.h"

class Order {
private:
    int orderID;
    Customer customer;
    std::vector<Dish> dishes;
    double discount;

public:
    Order();
    Order(int id, const Customer& c, double d = 0.0);
    ~Order();

    void addDish(const Dish& d);
    double getTotal() const;
    void showOrder() const;
};
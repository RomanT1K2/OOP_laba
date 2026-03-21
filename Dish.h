#pragma once
#include <string>

class Dish {
private:
    std::string name;
    double price;
    int calories;

public:
    Dish();
    Dish(const std::string& n, double p, int c = 0);
    ~Dish();

    double getPrice() const;
    void showInfo() const;
};
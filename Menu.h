#pragma once
#include <vector>
#include "Dish.h"

class Menu {
private:
    std::vector<Dish> dishes;

public:
    ~Menu();

    void addDish(const Dish& d);
    void showMenu() const;
};
#include "Menu.h"
#include <iostream>

Menu::~Menu() {
    std::cout << "[Menu] Меню видалено.\n";
}

void Menu::addDish(const Dish& d) {
    dishes.push_back(d);
}

void Menu::showMenu() const {
    std::cout << "\n======= МЕНЮ =======\n";
    for (size_t i = 0; i < dishes.size(); ++i) {
        std::cout << "[" << (i + 1) << "] ";
        dishes[i].showInfo();
    }
    std::cout << "====================\n";
}

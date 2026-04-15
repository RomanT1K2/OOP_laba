#pragma once
#include <vector>
#include "Dish.h"

class Menu {
private:
    std::vector<Dish> dishes;

public:
    Menu();
    ~Menu();

    void addDish(const Dish& d);
    void showMenu() const;

    // 🔥 ФАЙЛИ
    void saveToFile() const;
    // Завантажити з файлу
    void loadFromFile() {
        ifstream in("menu.txt");

        if (!in) {
            cout << "Error opening file for reading!\n";
            return;
        }

        dishes.clear();

        size_t count;
        in >> count;

        for (size_t i = 0; i < count; i++) {
            Dish d;
            d.loadFromFile(in); // ⚠️ має бути в класі Dish
            dishes.push_back(d);
        }

        in.close();
        cout << "Menu loaded from file.\n";
    }
};

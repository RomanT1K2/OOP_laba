#include "Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

// Конструктор
Menu::Menu() {
    cout << "Menu constructor called\n";
}

// Деструктор
Menu::~Menu() {
    cout << "Menu destructor called\n";
}

// Додати страву
void Menu::addDish(const Dish& d) {
    dishes.push_back(d);
    cout << "Dish added\n";
}

// Показати меню
void Menu::showMenu() const {
    if (dishes.empty()) {
        cout << "Menu is empty.\n";
        return;
    }

    cout << "\n=== MENU ===\n";
    for (size_t i = 0; i < dishes.size(); i++) {
        cout << i + 1 << ". ";
        dishes[i].showInfo();
    }
}

// Зберегти у файл
void Menu::saveToFile() const {
    ofstream out("menu.txt");

    if (!out) {
        cout << "Error opening file for writing!\n";
        return;
    }

    out << dishes.size() << endl;

    for (const auto& d : dishes) {
        d.saveToFile(out); // ⚠️ має бути в класі Dish
    }

    out.close();
    cout << "Menu saved to file.\n";
}


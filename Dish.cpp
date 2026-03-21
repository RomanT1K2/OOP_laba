#include "Dish.h"
#include <iostream>
#include <iomanip>

// Конструктор за замовчуванням
Dish::Dish() : Dish("Невідома страва", 0.0, 0) {}

// Основний конструктор
Dish::Dish(const std::string& n, double p, int c)
    : name(n), price(p), calories(c) {
}

// Деструктор
Dish::~Dish() {
    std::cout << "[Dish] \"" << name << "\" видалена.\n";
}

// Отримати ціну
double Dish::getPrice() const {
    return price;
}

// Вивід інформації
void Dish::showInfo() const {
    std::cout << std::fixed << std::setprecision(2)
        << "  Страва: " << std::left << std::setw(22) << name
        << "| Ціна: " << std::setw(8) << price
        << "| Калорії: " << calories << "\n";
}
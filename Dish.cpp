#include "Dish.h"
#include <iomanip>

// 🔹 Dish
Dish::Dish(string n, double p, int c)
    : name(n), price(p), calories(c) {
    cout << "[Dish constructor]\n";
}

Dish::Dish(const Dish& other)
    : name(other.name), price(other.price), calories(other.calories) {
    cout << "[Dish Copy]\n";
}

Dish::Dish(Dish&& other) noexcept
    : name(move(other.name)), price(other.price), calories(other.calories) {
    cout << "[Dish Move]\n";
}

Dish& Dish::operator=(const Dish& other) {
    if (this != &other) {
        name = other.name;
        price = other.price;
        calories = other.calories;
    }
    cout << "[Dish operator=]\n";
    return *this;
}

Dish::~Dish() {
    cout << "[Dish destructor]\n";
}

void Dish::showInfo() const {
    cout << left << setw(20) << name
        << "| Price: " << price
        << "| Calories: " << calories << "\n";
}

double Dish::getPrice() const {
    return price;
}

// 🔹 MainCourse
MainCourse::MainCourse(string n, double p, int c)
    : Dish(n, p, c) {
    cout << "[MainCourse constructor]\n";
}

void MainCourse::showInfo() const {
    cout << "[Main Course] ";
    Dish::showInfo();
}

// 🔹 Salad
Salad::Salad(string n, double p, int c)
    : Dish(n, p, c) {
    cout << "[Salad constructor]\n";
}

// Copy
Salad::Salad(const Salad& other)
    : Dish(other) {
    cout << "[Salad Copy]\n";
}

// Move
Salad::Salad(Salad&& other) noexcept
    : Dish(move(other)) {
    cout << "[Salad Move]\n";
}

// Operator =
Salad& Salad::operator=(const Salad& other) {
    if (this != &other) {
        Dish::operator=(other);
    }
    cout << "[Salad operator=]\n";
    return *this;
}

void Salad::showInfo() const {
    cout << "[Salad] ";
    Dish::showInfo();
}
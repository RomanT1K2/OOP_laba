#include "Dish.h"
#include <iomanip>
#include <string>

using namespace std;

Dish::Dish(string n, double p, int c)
    : name(n), price(p), calories(c) {
}

Dish::Dish(const Dish& other)
    : name(other.name), price(other.price), calories(other.calories) {
}

Dish::Dish(Dish&& other) noexcept
    : name(move(other.name)), price(other.price), calories(other.calories) {
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
}

void Dish::showInfo() const {
    cout << left << setw(20) << name
        << "| Price: " << price
        << "| Calories: " << calories << "\n";
}

double Dish::getPrice() const {
    return price;
}
int Dish::getCalories() const {
    return calories;
}
string Dish::getName() const {
    return name;
}

void Dish::saveToFile(ofstream& out) const
{
    // Write name on its own line, then price and calories on their own lines
    out << name << '\n';
    out << price << '\n';
    out << calories << '\n';
}

void Dish::loadFromFile(ifstream& in)
{
    // Read name (consume leading whitespace/newlines), then price and calories
    std::getline(in >> std::ws, name);
    in >> price >> calories;
}


MainCourse::MainCourse(string n, double p, int c)
    : Dish(n, p, c) {
}

void MainCourse::showInfo() const {
    cout << "[Main Course] ";
    Dish::showInfo();
}

Salad::Salad(string n, double p, int c)
    : Dish(n, p, c) {
}

Salad::Salad(const Salad& other)
    : Dish(other) {
}


Salad::Salad(Salad&& other) noexcept
    : Dish(move(other)) {
}


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

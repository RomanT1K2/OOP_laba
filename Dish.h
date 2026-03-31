#pragma once
#include <iostream>
#include <string>

using namespace std;

// 🔹 НАЙВЕРХНІЙ КЛАС
class MenuItem {
public:
    virtual void showInfo() const = 0;
    virtual double getPrice() const = 0;
    virtual ~MenuItem() {}
};

// 🔹 БАЗОВИЙ КЛАС
class Dish : public MenuItem {
protected:
    string name;
    double price;
    int calories;

public:
    Dish(string n = "Невідомо", double p = 0, int c = 0);

    // Rule of 5
    Dish(const Dish& other);
    Dish(Dish&& other) noexcept;
    Dish& operator=(const Dish& other);
    virtual ~Dish();

    void showInfo() const override;
    double getPrice() const override;
};

// 🔹 ДОЧІРНІ КЛАСИ
class MainCourse : public Dish {
public:
    MainCourse(string n, double p, int c);
    void showInfo() const override;
};

class Salad : public Dish {
public:
    Salad(string n, double p, int c);

    // ✔ ВИМОГА №6 (реалізовано тут)
    Salad(const Salad& other);
    Salad(Salad&& other) noexcept;
    Salad& operator=(const Salad& other);

    void showInfo() const override;
};
#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class MenuItem {
public:
    virtual void showInfo() const = 0;
    virtual double getPrice() const = 0;
    virtual int getCalories() const = 0;
    virtual string getName() const = 0;

    virtual ~MenuItem() {}

    virtual void printType() const {
        cout << "MenuItem\n";
    }
};
class Dish : public MenuItem {
private:
    string name;
    double price;
    int calories;

public:
    Dish(string n = "Невідомо", double p = 0, int c = 0);
    Dish(const Dish& other);
    Dish(Dish&& other) noexcept;
    Dish& operator=(const Dish& other);
    virtual ~Dish();

    int getCalories() const override;
    void showInfo() const override;
    double getPrice() const override;
    string getName() const override;
    void printType() const override {
        cout << "Dish\n";
    }
    void saveToFile(ofstream& out) const;
    void loadFromFile(ifstream& in);
};

class MainCourse final : public Dish {
public:
    MainCourse(string n, double p, int c);
    void showInfo() const override;
};

class Salad : public Dish {
public:
    Salad(string n, double p, int c);
    Salad(const Salad& other);
    Salad(Salad&& other) noexcept;
    Salad& operator=(const Salad& other);

    void showInfo() const override;
};
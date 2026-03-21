#include <iomanip>
#include <iostream>
#include "Order.h"


Order::Order() : Order(0, Customer()) {}

Order::Order(int id, const Customer& c, double d)
    : orderID(id), customer(c), discount(d) {
}

Order::~Order() {
    setlocale(LC_ALL, "Ukrainian");
    std::cout << "[Order] Замовлення №" << orderID << " закрите.\n";
}

void Order::addDish(const Dish& d) {
    setlocale(LC_ALL, "Ukrainian");
    dishes.push_back(d);
}

double Order::getTotal() const {
    double sum = 0.0;
    for (const auto& d : dishes)
        sum += d.getPrice();

    return sum * (1.0 - discount / 100.0);
}

void Order::showOrder() const {
    std::cout << "\n===== ЗАМОВЛЕННЯ №" << orderID << " =====\n";
    customer.showInfo();

    std::cout << "  Страви:\n";
    for (const auto& d : dishes)
        d.showInfo();

    std::cout << std::fixed << std::setprecision(2);

    if (discount > 0)
        std::cout << "  Знижка: " << discount << "%\n";

    std::cout << "  До сплати: " << getTotal() << " грн\n";
    std::cout << "========================\n";
}

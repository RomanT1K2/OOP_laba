#include <iostream>
#include "Menu.h"
#include "Order.h"
#include "Customer.h"

int main() {

    MainCourse pizza("Margherita Pizza", 150, 800);
    Salad caesar("Caesar Salad", 100, 200);
    Salad greek("Greek Salad", 90, 180);

    MenuItem* item = &pizza;
    item->printType(); // викличе MenuItem (static binding)

    Salad copySalad = caesar;
    Salad movedSalad = std::move(greek);

    Menu menu;
    menu.addItem(&pizza);
    menu.addItem(&caesar);

    menu.showMenu();

    Customer c("Roman");
    Order order(c);

    order.addItem(&pizza);
    order.addItem(&caesar);

    order.showOrder();

    return 0;
}
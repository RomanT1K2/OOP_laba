#include <iostream>
#include "Menu.h"
#include "Order.h"
#include "Customer.h"
#include "лаба_2.3.h"

int main() {
    Menu menu;
	setlocale(LC_ALL, "Ukrainian");
    menu.addDish(Dish("Піцца Маргарита", 180.50, 850));
    menu.addDish(Dish("Борщ Український", 95.00, 320));
    menu.addDish(Dish("Вареники з м'ясом", 120.00, 480));
    menu.addDish(Dish("Салат Цезар", 110.00, 250));
    menu.showMenu();

    Customer roman("Роман", "+380991234567");
    Order order1(1, roman);

    order1.addDish(Dish("Піцца Маргарита", 180.50, 850));
    order1.addDish(Dish("Салат Цезар", 110.00, 250));
    order1.showOrder();

    Customer olena("Олена", "+380671112233");
    Order order2(2, olena, 10.0);

    order2.addDish(Dish("Борщ Український", 95.00, 320));
    order2.addDish(Dish("Вареники з м'ясом", 120.00, 480));
    order2.showOrder();

    double testPrice = -10.0;

    if (testPrice < 0) {
        std::cout << "\nПомилка: ціна не може бути від'ємною!\n";
    }
    else {
        Dish good("Тест", testPrice);
        good.showInfo();
    }

    return 0;
}
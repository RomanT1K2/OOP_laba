#include <iostream>
#include "Menu.h"

using namespace std;

const string ADMIN_PASSWORD = "2322";

// історія
void saveHistory(const string& action) {
    ofstream out("history.txt", ios::app);
    out << action << endl;
}

void adminPanel(Menu& menu) {
    int choice;

    do {
        cout << "\n=== ADMIN PANEL ===\n";
        cout << "1. Add dish\n";
        cout << "2. Show menu\n";
        cout << "3. Save to file\n";
        cout << "4. Load from file\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                string name;
                double price;

                cout << "Enter dish name: ";
                cin >> name;
                cout << "Enter price: ";
                cin >> price;

                Dish d(name, price);
                menu.addDish(d);

                saveHistory("Admin added dish: " + name);
            }
            else if (choice == 2) {
                menu.showMenu();
            }
            else if (choice == 3) {
                menu.saveToFile();
                saveHistory("Admin saved menu");
            }
            else if (choice == 4) {
                menu.loadFromFile();
                saveHistory("Admin loaded menu");
            }
        }
        catch (...) {
            cout << "Something went wrong!\n";
        }

    } while (choice != 0);
}

void userPanel(Menu& menu) {
    int choice;

    do {
        cout << "\n=== USER PANEL ===\n";
        cout << "1. Show menu\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            menu.showMenu();
            saveHistory("User viewed menu");
        }

    } while (choice != 0);
}

int main() {
    Menu menu;
    menu.loadFromFile(); // ✔ автоматичне завантаження

    int choice;

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string pass;
            cout << "Enter password: ";
            cin >> pass;

            if (pass == ADMIN_PASSWORD) {
                adminPanel(menu);
            }
            else {
                cout << "Wrong password!\n";
            }
        }
        else if (choice == 2) {
            userPanel(menu);
        }

    } while (choice != 0);

    return 0;
}
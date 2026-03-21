#pragma once
#include<string>

class Customer {
private:
    std::string name;
    std::string phone;

public:
    Customer();
    Customer(const std::string& n, const std::string& p);
    ~Customer();

    void showInfo() const;
};
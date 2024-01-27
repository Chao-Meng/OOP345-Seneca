/*
    ==================================================
    Workshop 4 Part 2:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :06/12/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include "Toy.h"

namespace sdds {
    Toy::Toy() {
        m_orderId = 0;
        m_name = "";
        m_itemNum = 0;
        m_price = 0.0;
        m_tax = 0.13;
        m_ToyCon = nullptr;
    }

    Toy::Toy(const sdds::Toy& toy) {
        m_orderId = toy.getOrderId();
        m_name = toy.getName();
        m_itemNum = toy.getItemNum();
        m_price = toy.getPrice();
        m_tax = toy.getTax();
        m_ToyCon = nullptr;
    }
    size_t Toy::getOrderId() const {
        return m_orderId;
    }
    string Toy::getName() const {
        return m_name;
    }
    int Toy::getItemNum() const {
        return m_itemNum;
    }
    double Toy::getPrice() const {
        return m_price;
    }
    double Toy::getTax() const {
        return m_tax;
    }
    void Toy::update(int numItems) {
        m_itemNum = numItems;
    }

    Toy::Toy(const std::string& toy) {
        size_t start = 0;
        size_t end = toy.find(":");
        m_orderId = stoi(toy.substr(0, end - start));
        start = end + 1;
        end = toy.find(":",start);
        m_name = toy.substr(start, end - start);
        //remove the trailing space
        m_name.erase(m_name.find_last_not_of(" ") + 1);
        start = end + 1;
        end = toy.find(":", start);
        m_itemNum = stoi(toy.substr(start, end -start)); 
        start = end + 1;
        end = toy.find(":", start);
        m_price = stod(toy.substr(start, end - start));
    }

    std::ostream& operator<<(std::ostream& os, const Toy& t) {
        os << "Toy " << t.m_orderId << ":";
        os.width(18);
        os.setf(std::ios::right);
        int itemNum = t.getItemNum();
        double price = t.getPrice();
        double tax = t.getTax();
        os << t.m_name << setw(3) << itemNum << " items" << setw(8) << price << "/item  subtotal:";
        os << setw(7) << itemNum * price << " tax:" << setw(6) <<fixed<<setprecision(2) << t.getTax() * price * itemNum;
        os << " total:" <<setw(7)<< itemNum * price + tax * price * itemNum << endl;
        return os;
    }
}
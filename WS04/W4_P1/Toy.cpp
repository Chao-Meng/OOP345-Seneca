/*
    ==================================================
    Workshop 4 Part 2:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :06/09/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
//#include <fstream>
//#include <cstring>
#include <string.h>
#include <vector>
#include <sstream>

#include "Toy.h"

namespace sdds {
    Toy::Toy() {
        unsigned int m_orderId = 0;
        string m_name{};
        int m_itemNum = 0;
        double m_price = 0;
        double m_tax = 0.13;
    }

    void Toy::update(int numItems) {
        m_itemNum = numItems;
    }

    

    //split the string with special delim, and store them in vector
    /*vector<string> split(const string& s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }*/

    Toy::Toy(const std::string& toy) {
        size_t start = 0;
        size_t end = toy.find(":");
        m_orderId = stoi(toy.substr(0, end - start));
        start = end + 1;
        end = toy.find(":",start);
        m_name = toy.substr(start, end - start);
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
        os << t.m_name << setw(3) << t.m_itemNum << " items" << setw(8) << t.m_price << "/item subtotal:";
        os << setw(7) << t.m_itemNum * t.m_price << " tax:" << setw(6) <<fixed<<setprecision(2) << t.m_tax * t.m_price;
        os << " total:" <<setw(7)<< t.m_itemNum * t.m_price + t.m_tax * t.m_price << endl;
        return os;
    }
}
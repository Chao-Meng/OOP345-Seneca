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
#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <chrono>
#include <cstddef>
#include <string>
using namespace std;

namespace sdds {

    class Toy {
        size_t m_orderId;
        string m_name{};
        int m_itemNum = 0;
        double m_price = 0;
        double m_tax = 0.13;
    public:
        Toy();
        void update(int numItems);
        Toy(const std::string& toy);
        friend std::ostream& operator<<(std::ostream& os, const Toy& t);


    };
}
#endif
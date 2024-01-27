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
#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <chrono>
#include <cstddef>
#include <string>
using namespace std;

namespace sdds {

    class Toy {
        size_t m_orderId;
        string m_name;
        int m_itemNum;
        double m_price;
        double m_tax=0.13;
        const sdds::Toy** m_ToyCon;
    public:
        Toy();
        Toy(const sdds::Toy& toy);
        size_t getOrderId() const;
        string getName() const;
        int getItemNum() const;
        double getPrice() const;
        double getTax() const;
        void update(int numItems);
        Toy(const std::string& toy);
        friend std::ostream& operator<<(std::ostream& os, const Toy& t);
    };

}
#endif
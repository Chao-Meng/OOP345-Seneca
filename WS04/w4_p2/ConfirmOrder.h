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
#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H
#include <chrono>
#include <cstddef>
#include <string>
#include "Toy.h"
using namespace std;

namespace sdds {
    class ConfirmOrder {
        const sdds::Toy** m_ToyCon;
        size_t m_num = 0;
    public:
        ConfirmOrder();
        ConfirmOrder(const ConfirmOrder& c);
        ~ConfirmOrder();
        size_t size() const;
        const sdds::Toy** getToyCon() const;
        void setSize(size_t size);
        void setToyCon(const sdds::Toy** toy);
        ConfirmOrder& operator=(const ConfirmOrder& c);
        ConfirmOrder& operator+=(const Toy& toy)noexcept;
        ConfirmOrder& operator-=(const Toy& toy);
        ConfirmOrder(ConfirmOrder&& c)noexcept;
        ConfirmOrder& operator = (ConfirmOrder&& c)noexcept;
        friend std::ostream& operator<<(std::ostream& os, ConfirmOrder& c);    
    };

}
#endif

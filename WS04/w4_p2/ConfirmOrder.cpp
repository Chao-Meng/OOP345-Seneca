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
#include <string.h>
#include <vector>
#include <sstream>
#include "ConfirmOrder.h"

namespace sdds {
    ConfirmOrder::ConfirmOrder() {
        m_ToyCon=nullptr;
        m_num = 0;
    }
   
    ConfirmOrder::ConfirmOrder(const ConfirmOrder& c) {
        m_num = c.size();
        m_ToyCon = new const sdds::Toy * [m_num];
        for (size_t i = 0; i < m_num; i++) {
            //m_ToyCon[i] = new Toy(*c.getToyCon()[i]);
            m_ToyCon[i] = c.getToyCon()[i];
        }
    }
    ConfirmOrder::~ConfirmOrder() {
        delete[] m_ToyCon;
        m_ToyCon = nullptr;
        if (m_ToyCon != nullptr) {
            for (size_t i = 0; i < m_num; i++) {
                if (m_ToyCon[i]!=nullptr) {
                    delete m_ToyCon[i];
                    m_ToyCon[i] = nullptr;
                }
            }
            delete [] m_ToyCon;
            m_ToyCon = nullptr;
        }
    }

    size_t ConfirmOrder::size() const {
        return m_num;
    }

    const sdds::Toy** ConfirmOrder::getToyCon() const {
        return m_ToyCon;
    }
    //setter
    void ConfirmOrder::setSize(size_t size) {
        m_num = size;
    }

    void ConfirmOrder::setToyCon(const sdds::Toy** toy) {
        m_ToyCon = toy;
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& c) {
        if (this != &c) {
            if (c.m_ToyCon != nullptr) {
                if (m_ToyCon != nullptr) {
                    for (size_t i = 0; i < m_num; i++) {
                        delete m_ToyCon[i];
                        m_ToyCon[i] = nullptr;
                    }
                    delete[] m_ToyCon;
                }
                size_t num = c.size();
                m_ToyCon = new const sdds::Toy * [num];
                for (size_t i = 0; i < c.m_num; i++) {
                    m_ToyCon[i] = new Toy(*c.getToyCon()[i]);
                }
                m_num = num;
            }
        }

        return *this;
   }

    //determin if toy does exist in the array, store the address of toy
    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)noexcept {
        bool find = false;
        if (m_ToyCon != nullptr) {
            for (size_t i = 0; i < m_num; i++) {
                if (m_ToyCon[i]->getName() == toy.getName() &&
                    m_ToyCon[i]->getItemNum() == toy.getItemNum() &&
                    m_ToyCon[i]->getOrderId() == toy.getOrderId() &&
                    m_ToyCon[i]->getPrice() == toy.getPrice() &&
                    m_ToyCon[i]->getTax() == toy.getTax()) {
                    find = true;
                }
            }
            if (!find) {
                m_ToyCon[m_num] = &toy;
                m_num++;
            }
        }
        else {
            m_ToyCon = new const Toy * [10];
            m_ToyCon[0] = &toy;
            m_num = 1;
        }
        return *this;
        //backup, it does not work for update confirmorder
        /*bool find = false;
        if (m_ToyCon != nullptr) {
            for (size_t i = 0; i<m_num; i++) {
                if (m_ToyCon[i]->getName() == toy.getName() &&
                    m_ToyCon[i]->getItemNum() == toy.getItemNum() &&
                    m_ToyCon[i]->getOrderId() == toy.getOrderId() &&
                    m_ToyCon[i]->getPrice() == toy.getPrice() &&
                    m_ToyCon[i]->getTax() == toy.getTax()) {
                    find = true;
                }
            }
            if (!find) {
                const Toy** temp = new const Toy * [m_num + 1];
                for (size_t i = 0; i < m_num; i++) {
                    temp[i] = new Toy(*m_ToyCon[i]); 
                }
                temp[m_num] = new Toy(toy);
                for (size_t i = 0; i < m_num; i++) {
                    delete m_ToyCon[i];
                    m_ToyCon[i] = nullptr;
                }
                delete [] m_ToyCon;
                m_ToyCon = temp;
                temp = nullptr;
                m_num++;               
            }
        }
        else {
            m_ToyCon = new const Toy*[1];
            m_ToyCon[0] = new Toy(toy);
            m_num = 1;
        }*/
    }

    //When encounter a duplicate, move the pointer forward one position
    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) { 
        if (m_ToyCon != nullptr) {
            bool find = false;
            size_t index = -1;
            for (size_t i = 0; i < m_num; i++) {
                if (m_ToyCon[i] != nullptr) {
                    if (m_ToyCon[i]->getName() == toy.getName() &&
                        m_ToyCon[i]->getItemNum() == toy.getItemNum() &&
                        m_ToyCon[i]->getOrderId() == toy.getOrderId() &&
                        m_ToyCon[i]->getPrice() == toy.getPrice() &&
                        m_ToyCon[i]->getTax() == toy.getTax()) {
                        find = true;
                        index = i;
                        break;
                    }
                }
            }
            if (find) {
                for (; index < m_num; index++) {
                    if (index < m_num - 1) {
                        m_ToyCon[index] = m_ToyCon[index + 1];
                    }
                    else {
                        m_ToyCon[index] = nullptr;
                    }
                }
                m_num--;
            }
        }
        return *this;
    }
    //move constructor
    ConfirmOrder::ConfirmOrder(ConfirmOrder&& c)noexcept {
        if (c.getToyCon() != nullptr) {
            this->m_num = c.size();
            this->m_ToyCon = c.getToyCon();
            /*c.setToyCon(nullptr);
            c.setSize(0);*/
           // Theoretically couldnot use private member variables directly, but not sure why it works 
           c.m_ToyCon = nullptr;
        }
        else {
            this->m_num = 0;
            this->m_ToyCon = nullptr;
        }
    }
    //move assign
    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& c)noexcept {
        if (this != &c) {
            if (c.m_ToyCon != nullptr) {
                this->m_num = c.m_num;
                this->m_ToyCon = c.m_ToyCon;
                c.m_ToyCon = nullptr;
                c.m_num = 0;
            }
            else {
                this->m_num = 0;
                this->m_ToyCon = nullptr;
            }
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, ConfirmOrder& c) {
        if (c.m_ToyCon == nullptr) {
            os << "--------------------------"<<endl;
            os << "Confirmations to Send"<<endl;
            os<< "--------------------------"<<endl;
            os << "There are no confirmations to send!" << endl;
            os<< "--------------------------" << endl;
        }
        else {
            os << "--------------------------"<<endl;
            os << "Confirmations to Send" << endl;
            os << "--------------------------" << endl;
            for (size_t i = 0;i <c.m_num; i++) {
                if (c.getToyCon()[i] != nullptr) {
                    os << "Toy " << c.getToyCon()[i]->getOrderId() << ":";
                    os.width(18);
                    os.setf(std::ios::right);
                    int num = c.getToyCon()[i]->getItemNum();
                    double price = c.getToyCon()[i]->getPrice();
                    double tax = c.getToyCon()[i]->getTax();
                    os << c.getToyCon()[i]->getName() << setw(3) << num << " items" << setw(8) << price << "/item  subtotal:";
                    os << setw(7) << num * price << " tax:" << setw(6) << fixed << setprecision(2) << tax * price * num;
                    os << " total:" << setw(7) << num * price + tax * price * num << endl;
                }
                
            }
            os << "--------------------------" << endl;
        }
        return os;
    }

}
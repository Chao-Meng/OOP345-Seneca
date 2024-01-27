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
#include "Child.h"

namespace sdds {
    Child::Child() {
       m_name={};
       m_age = 0;
       m_toyObj=nullptr;
    }

    Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
        m_name = name;
        m_age = age;
        m_count = count; 
        m_toyObj = new const sdds::Toy*[m_count];
        for (size_t i = 0;i < m_count;i++) {
            m_toyObj[i] = new Toy(*toys[i]);
        }
    }

    Child::~Child() {
        if (m_toyObj!=nullptr) {
            for (size_t i = 0; i < m_count; i++) {
                if (m_toyObj[i] != nullptr){
                    delete m_toyObj[i];
                    m_toyObj[i] = nullptr;
                }
            }
            delete[] m_toyObj;
            m_toyObj = nullptr;
        }
    }
  
    Child::Child(Child& ch) {
        m_name = ch.m_name;
        m_age = ch.m_age;
        m_count = ch.size();
        if (ch.m_toyObj != nullptr) {
            m_toyObj = new const sdds::Toy * [m_count];
            for (size_t i=0; i<m_count; i++) {
                m_toyObj[i] = new Toy(*ch.m_toyObj[i]);
            }
        }
    }

    Child& Child::operator=(Child& ch) {
        if (this != &ch) {
            m_name = ch.m_name;
            m_age = ch.m_age;
            if (ch.m_toyObj != nullptr) {
                if (m_toyObj != nullptr) {
                    for (size_t i = 0; i < m_count; i++) {
                        delete m_toyObj[i];
                        m_toyObj[i] = nullptr;
                    }
                    delete[] m_toyObj;
                }
                m_toyObj = new const sdds::Toy * [ch.m_count];
                for (size_t i = 0; i < ch.m_count; i++) {
                    m_toyObj[i] = new Toy(*ch.m_toyObj[i]);
                }
            }
            m_count = ch.m_count;
        }

        return *this;
    }
    //getter
    size_t Child::size() const {
        return m_count;
    }

    string Child::getName() const {
        return m_name;
    }

    size_t Child::getAge() const {
        return m_age;
    }

    const sdds::Toy** Child::getToyObj() const {
        return m_toyObj;
    }
    //setter
    void Child::setSize(size_t size) {
        m_count = size;
    }

    void Child::setName(string name) {
        m_name = name;
    }

    void Child::setAge(size_t age) {
        m_age = age;
    }

    void Child::setToyObj(const sdds::Toy** toy) {
        m_toyObj = toy;
    }
    //move constructor
    sdds::Child::Child(Child&& c)noexcept {
        if (c.getToyObj() != nullptr) {
            this->m_name = c.getName();
            this->m_age = c.getAge();
            this->m_count = c.size();
            this->m_toyObj = c.getToyObj();
            c.setToyObj(nullptr);
            c.setName("");
            c.setAge(0);
            c.setSize(0);
        }
        else {
            this->m_name = {};
            this->m_age = 0;
            this->m_count = 0;
            this->m_toyObj = nullptr;
        }
   }
    //move assign
    Child& Child::operator=(Child&& c) noexcept {
        if (this != &c) {
            if (c.m_toyObj != nullptr) {
                this->m_name = c.m_name;
                this->m_age = c.m_age;
                this->m_count = c.m_count;
                this->m_toyObj = c.m_toyObj;
                c.m_toyObj = nullptr;
                c.m_name = {};
                c.m_age = 0;
                c.m_count = 0;
            }
            else {
                this->m_name = {};
                this->m_age = 0;
                this->m_count = 0;
                this->m_toyObj = nullptr;
            }
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Child& ch) {
        static int CALL_CNT = 1;
        if (ch.size()==0) {
            os << "--------------------------"<<endl;
            os << "Child "<<CALL_CNT<<": "<<ch.m_name<<" "<< ch.m_age << " years old:" << endl;
            os << "--------------------------"<<endl;
            os << "This child has no toys!"<<endl;
            os << "--------------------------"<<endl;
        }
        else {
            os << "--------------------------"<<endl;
            os << "Child " << CALL_CNT << ": " << ch.m_name << " " << ch.m_age << " years old:"<<endl;
            os << "--------------------------"<<endl;
            for (size_t i = 0;i < ch.m_count;i++) {
                size_t orderId = ch.getToyObj()[i]->getOrderId();
                os << "Toy " << orderId << ":";
                os.width(18);
                os.setf(std::ios::right);
                int itemNum = ch.getToyObj()[i]->getItemNum();
                double price = ch.getToyObj()[i]->getPrice();
                double tax = ch.getToyObj()[i]->getTax();
                os << ch.getToyObj()[i]->getName() << setw(3) << itemNum << " items" << setw(8) << price << "/item  subtotal:";
                os << setw(7) << itemNum * price << " tax:" << setw(6) << fixed << setprecision(2) << tax * price * itemNum;
                os << " total:" << setw(7) << itemNum * price + tax * price * itemNum << endl;
            }
            os << "--------------------------"<<endl;
        }
        CALL_CNT++;
        return os;
    }

}
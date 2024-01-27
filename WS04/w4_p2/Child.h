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
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include <chrono>
#include <cstddef>
#include <string>
#include "Toy.h"
using namespace std;

namespace sdds {
    class Child {
        string m_name;
        size_t m_age = 0;
        size_t m_count = 0;
        const sdds::Toy** m_toyObj;
    public:
        Child();
        Child(std::string name, int age, const Toy* toys[], size_t count);
        ~Child();
        Child(Child& ch);
        size_t size() const;
        string getName() const;
        size_t getAge() const;
        const sdds::Toy** getToyObj() const;
        void setSize(size_t size);
        void setName(string name) ;
        void setAge(size_t age);
        void setToyObj(const sdds::Toy**);
        Child& operator=(Child& ch);
        //move constructor
        Child(Child&& Child)noexcept;
        //move assign
        Child& operator=(Child&& c)noexcept;
        friend std::ostream& operator<<(std::ostream& os, const Child& ch);
    };
}
#endif

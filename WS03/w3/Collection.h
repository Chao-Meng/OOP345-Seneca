/*
    ==================================================
    Workshop 3 Part 2:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :06/04/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <chrono>
#include <cstddef>
#include <string>
#include "Pair.h"

namespace sdds {
   // Pair p;
    template<typename T, size_t m_max=0>
    class Collection {
        T m_type[m_max]{};
        size_t m_num=0;
        //static unsigned int m_num;
    public:
        Collection() {

        }
        size_t size() {
            return m_num;
        }

        std::ostream& display(){
           //if (typeid(m_type[0]) != typeid(Pair)) {
           std::cout << "----------------------"<< std::endl;
           std::cout << "| Collection Content |"<< std::endl;
           std::cout << "----------------------"<< std::endl;
               for (size_t i = 0;i <m_num;i++) {
                    //std::cout << m_type[i]<<endl;
                   std::cout << m_type[i] << std::endl;
               }  
           std::cout << "----------------------" << std::endl;
             //  cout << "yes" << endl;
           //}
           // else {
           //    for (size_t i = 0;i < m_num;i++) {
           //        p.display(m_type[i]);
           //    }
           //  /* for (auto i = 0;i < m_num;i++) {
           //         std::cout <<m_type[i].getKey() << endl;
           //    }*/
           //    cout << "no" << endl;
           // }
           
           return std::cout;
            
        }

        bool add(const T& item) {
            bool isCap = false;
            if (m_num < m_max) {
                m_type[m_num] = item;
                m_num++;
                isCap = true;
            }
            else {
                isCap = false;
            }
            return isCap;
        }

       //std::string operator[](size_t index) {
        const T& operator[](size_t index){
           //if (index > m_num) {
           // //    //if (typeid(m_type[0]) != typeid(Pair)) {
           //        // m_type[index];
           //     //}
           // //    //else {
           // //        //return m_type[index];
           // //    //}
           // //}
           //// else {
           //    if (typeid(m_type[0]) == typeid(Pair)) {
           //       m_type[index]='\0';
           //        //return ' ';
           //    }
           //     else {
           //        m_type[index] = 0;
           //       // return 0;
           //     }
           // }
           return m_type[index];
        }
       
     
    };
    std::ostream& operator<<(std::ostream& os, Pair& p) {
        //if (typeid(this) == typeid(Pair)) {
            //std::cout << m_type[i]<<endl;
        os.width(20);
        os.setf(std::ios::right);
        os << p.getKey() << ": ";
        os.unsetf(std::ios::right);
        os << p.getValue() ;
        //os << p.getKey() << ":" << p.getValue();
        //os<< (p.getValue() << endl;
    //}
        return os;
   }

}



#endif

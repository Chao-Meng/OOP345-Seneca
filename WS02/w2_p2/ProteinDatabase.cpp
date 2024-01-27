/*
    ==================================================
    Workshop 2 Part 2:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :05/28/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <iomanip>
//#include <cstdlib>
#include <fstream>
//#include <cstring>
#include <string>
#include <cstddef>
#include "ProteinDatabase.h"

namespace sdds {
    ProteinDatabase::ProteinDatabase() {
        m_count = 0;
        m_arr = nullptr;
    }

    //to find the string starts with sub
    int startsWith(string s, string sub) {
        return s.find(sub) == 0 ? 1 : 0;
    }

    ProteinDatabase::ProteinDatabase(string str) {
        ifstream infile(str);
        if(infile.is_open()){
            string s;
            while (getline(infile,s, '\n')) { 
                if (startsWith(s, ">") == 1) {
                    m_count++;//count how many protein sequence without description
                }
            }
            m_arr = new string[m_count+1];
            infile.clear();
            infile.seekg(0, ios::beg);
            static int i = -1;
            while (getline(infile, s, '\n')) {
                if (startsWith(s, ">") == 0) {
                   m_arr[i] += s;//combine the protein sequence into an array, when meets '>', index plus 1
                }
                else {
                    i++;
                }
            }
        }
        else {
            cout << "Failed to open the file" << str << endl;
        }
    }
    //copy constructor
    ProteinDatabase::ProteinDatabase(ProteinDatabase& proteinDatabase)  {
        if (proteinDatabase.m_arr != nullptr) {
            this->m_count = proteinDatabase.m_count;
            this-> m_arr = new string[m_count];

            for (size_t i = 0;i < m_count;i++) {
               this-> m_arr[i] = proteinDatabase.m_arr[i];
             }
        }
        else {
            m_count = 0;
            m_arr = nullptr;
        }

    }
    //move constructor 
    ProteinDatabase::ProteinDatabase(ProteinDatabase&& proteinDatabase) noexcept {
        if (proteinDatabase.m_arr != nullptr) {
            this-> m_count = proteinDatabase.m_count;
            this->m_arr = proteinDatabase.m_arr;
            proteinDatabase.m_arr = nullptr;
        }
        else {
            m_count = 0;
            m_arr = nullptr;
        }
    }

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase& proteinDatabase) {
        if (this != &proteinDatabase) {
            if (proteinDatabase.m_arr != nullptr) {
                m_count = proteinDatabase.m_count;
                m_arr = new string[m_count];
                for (size_t i = 0;i < m_count;i++) {
                    m_arr[i] = proteinDatabase.m_arr[i];
                }
            }
            else {
                m_count = 0;
                m_arr = nullptr;
            }
        }
        return *this;
    }
    //move assignment operator
    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& proteinDatabase) noexcept {
       if (this != &proteinDatabase) {
            if(proteinDatabase.m_arr != nullptr) {
                m_count = proteinDatabase.m_count;
                this->m_arr = proteinDatabase.m_arr;
                proteinDatabase.m_arr = nullptr;//destory it after moving
            }
            else {
                m_count = 0;
                m_arr = nullptr;
            }
        }
        return *this;
    }
    //destructor 
    ProteinDatabase::~ProteinDatabase() {
        delete[] m_arr;
    }

    size_t ProteinDatabase::size() {
        return m_count;
    }

    std::string ProteinDatabase::operator[](size_t index) {
        string s; 
        if (index >= m_count) {
            s = "";
        }
        else {
            if (m_arr != nullptr) {
                s = m_arr[index];
            }
            else {
                s = "";
            }
        }
        return s;
    }
}
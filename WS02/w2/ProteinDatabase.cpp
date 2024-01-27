/*
    ==================================================
    Workshop 2 Part 1:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :05/27/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
//#include <vector>
//#include <sstream>
#include "ProteinDatabase.h"

namespace sdds {
    ProteinDatabase::ProteinDatabase() {
        m_count = 0;
        m_arr = nullptr;
    }

    int startsWith(string s, string sub) {
        return s.find(sub) == 0 ? 1 : 0;
    }

    ProteinDatabase::ProteinDatabase(string str) {
        //ifstream infile("proteinsequences.txt");
        ifstream infile(str);
        //infile.open;
        if(infile.is_open()){
          //  char c[10000];
            size_t size=infile.gcount();
            string s;
            while (getline(infile,s, '\n')) { 
                if (startsWith(s, ">") == 1) {
                    m_count++;
                }
            }
            m_arr = new string[m_count+1];
            infile.clear();
            infile.seekg(0, ios::beg);
            static int i = -1;
            while (getline(infile, s, '\n')) {
                if (startsWith(s, ">") == 0) {
                   m_arr[i] += s;
                }
                else {
                    i++;
                }
            }
            int a = 0;
        }
        else {
            cout << "Failed to open the file" << str << endl;
        }
    }

    ProteinDatabase::ProteinDatabase(ProteinDatabase&& proteinDatabase) noexcept {
        
            if (proteinDatabase.m_arr != nullptr) {
               this-> m_count = proteinDatabase.m_count;
               //this-> m_arr = new string[m_count];
             // this->m_arr = proteinDatabase.m_arr;
             // proteinDatabase.m_arr = nullptr;
                for (auto i = 0;i < m_count;i++) {
                  this-> m_arr[i] = proteinDatabase.m_arr[i];
                   proteinDatabase.m_arr[i]=nullptr;
                }
            }
            else {
                m_count = 0;
                m_arr = nullptr;
            }
        
    }

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& proteinDatabase) noexcept {
       if (this != &proteinDatabase) {
            if(proteinDatabase.m_arr != nullptr) {
                m_count = proteinDatabase.m_count;
                //m_arr = new string[m_count];
                //this->m_arr = proteinDatabase.m_arr;
               // proteinDatabase.m_arr = nullptr;
                for (auto i = 0;i < m_count;i++) {
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

    //ProteinDatabase::~ProteinDatabase() {
    //    delete[] m_arr;
    //}
    size_t ProteinDatabase::size() {
        return m_count;
    }
    std::string ProteinDatabase::operator[](size_t index) {
        string s;
        if (index >= m_count) {
            s = "";
        }
        else {
            s = m_arr[index];
        }

        return s;
       // return "";
    }
}
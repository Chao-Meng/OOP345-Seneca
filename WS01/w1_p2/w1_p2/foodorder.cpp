/*
    ==================================================
    Workshop 1 Part 2:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :05/20/2022
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
#include <string.h>
#include <vector>
#include <sstream>
#include "foodorder.h"
double g_taxrate=0.00;
double g_dailydiscount = 0.00;
namespace sdds {

    FoodOrder::FoodOrder() {
        m_foodDescr = nullptr;
        m_foodPrice=0.00;
        m_flag = false;
    }
    //copy constructor,initialize another nesly created object 
    //by using an object of the same type
    FoodOrder::FoodOrder(const FoodOrder& F) {
        m_foodDescr = nullptr;
        if (F.m_foodDescr != nullptr) {
            size_t len = strlen(F.m_foodDescr) + 1;
            m_foodDescr = new char[len];
            strncpy(m_foodDescr, F.m_foodDescr, len);
        }
        strcpy(m_orderName,F.m_orderName);
        m_foodPrice=F.m_foodPrice;
        m_spePrice=F.m_spePrice;
        m_flag=F.m_flag;
    }

    FoodOrder::~FoodOrder() {
        if (m_foodDescr!=nullptr) {
            delete [] m_foodDescr;
            m_foodDescr = nullptr;
        }
    }

    FoodOrder& FoodOrder::operator=(FoodOrder& F) {
        if (F.m_foodDescr != nullptr) {
            size_t len = strlen(F.m_foodDescr) + 1;
            if (m_foodDescr != nullptr) {
                delete[] m_foodDescr;
            }
            m_foodDescr = new char[len];
            strncpy(m_foodDescr, F.m_foodDescr, len);
        }
        else {
            if (m_foodDescr != nullptr) {
                delete[] m_foodDescr;
                m_foodDescr = nullptr;
            }
        }
        strcpy(m_orderName, F.m_orderName);
        m_foodPrice = F.m_foodPrice;
        m_spePrice = F.m_spePrice;
        m_flag = F.m_flag;
        return *this;
    }

    //split the string with special delim, and store them in vector
    vector<string> split(const string& s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    void FoodOrder::read(istream& istr) {
        char getStr[50];
        istr.getline(getStr, 50);
        size_t nSize = strlen(getStr);
        if (nSize == 0) {
            strcpy(m_orderName, "No Order");
            return;
        }
        vector<string> vtElems;
        string s(getStr);
        vtElems = split(s, ',');
        //Assign the strings splited from vectore to the corresponding member variables in order
        strcpy(m_orderName, vtElems[0].c_str());
        size_t len = vtElems[1].length() + 1;
        if (m_foodDescr != nullptr) {
            delete[] m_foodDescr;
        }
        m_foodDescr = new char[len];
        strncpy(m_foodDescr, vtElems[1].c_str(), len);
        m_foodPrice = stof(vtElems[2].c_str());
        string strFlag = vtElems[3];
        vtElems.clear();
        if (strstr(strFlag.c_str(), "Y") != NULL) {
            m_flag = true;
        }
        else {
            m_flag = false;
        }
    }
    
    void FoodOrder::display(){
        static int counter = 1;
        if (strcmp(m_orderName, "No Order") != 0) {
           if (!m_flag) {
               m_foodPrice = m_foodPrice * (1 + g_taxrate);
               cout << left << setw(2) << counter++ << ". " << setw(10) << m_orderName << '|' << setw(25) <<
                   m_foodDescr << '|' << fixed << setw(12) << setprecision(2) << m_foodPrice << '|' << endl;
            }
            else{
                m_foodPrice = m_foodPrice * (1 + g_taxrate);
                m_spePrice = m_foodPrice - g_dailydiscount ;
                cout << left << setw(2) << counter++ << ". " << setw(10) << m_orderName << '|' << setw(25) <<
                    m_foodDescr << '|' << fixed << setw(12) << setprecision(2) << m_foodPrice << '|';
                    cout << right << fixed << setw(13) << setprecision(2) << m_spePrice << endl;
           }

        }
        else {
            cout << left << setw(2) << counter++ << ". " << "No Order" << endl;
        }  
    }
}
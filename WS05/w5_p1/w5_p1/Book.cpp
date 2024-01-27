/*
    ==================================================
    Workshop 5 Part 2:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :06/16/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
//#include <cstdlib>
//#include <string.h>
//#include <vector>
#include <string>
#include <sstream>
#include "Book.h"

namespace sdds {
    Book::Book() {
        m_author = {};
        m_title = {};
        m_country = {};
        m_year=0;
        m_price=0.0;
        m_desc = {};
    }
    const std::string& Book::title() const {
        return m_title;
    }
    const std::string& Book::country() const {
        return m_country;
    }
    const size_t& Book::year() const {
        return m_year;
    }
    double& Book::price() {
        return m_price;
    }
    Book::Book(const std::string& strBook) {
        size_t start = 0;
        size_t end = strBook.find(",");
        m_author = strBook.substr(0, end - start);
        start = end + 1;
        end = strBook.find(",", start);
        m_title = strBook.substr(start, end - start);
        start = end + 1;
        end = strBook.find(",", start);
        m_country = strBook.substr(start, end - start);
        start = end + 1;
        end = strBook.find(",", start);
        m_price = stod(strBook.substr(start, end - start));
        start = end + 1;
        end = strBook.find(",", start);
        m_year = stoi(strBook.substr(start, end - start));
        start = end + 1;
        end = strBook.find(".", start);
        m_desc = strBook.substr(start, end - start);
    }
    
    std::ostream& operator<<(std::ostream& os, const Book& b) {
        os << setw(20) << b.m_author << " |"<< setw(22) << b.title() << " |";
        os << setw(5) << b.country() << " |" << setw(4) << b.year()<< " |";
        os <<setw(6)<< fixed << setprecision(2) << b.m_price << " |";
        os << b.m_desc <<'.' << endl;
        return os;
    }

}
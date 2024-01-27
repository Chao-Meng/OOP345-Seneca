/*
    ==================================================
    Workshop 5 Part 2:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :06/18/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>

#include "Movie.h"
using namespace std;
namespace sdds {
    Movie::Movie() {
        m_title="";
        m_releYear="";
        m_desc="";
    }
    const std::string& Movie::title() const {
        return m_title;
    }
    Movie::Movie(const std::string& strMovie) {
        size_t start = 0;
        size_t end = strMovie.find(",");
        m_title = strMovie.substr(0, end - start);
        m_title.erase(0, m_title.find_first_not_of(" "));
        m_title.erase(m_title.find_last_not_of(" ") + 1, m_title.length());
        start = end + 1;
        end = strMovie.find(",", start);
        m_releYear = strMovie.substr(start, end - start);
        m_releYear.erase(0, m_releYear.find_first_not_of(" "));
        m_releYear.erase(m_releYear.find_last_not_of(" ") + 1, m_releYear.length());
        start = end + 1;
        end = strMovie.find(".", start);
        m_desc = strMovie.substr(start, end - start);
        m_desc.erase(0, m_desc.find_first_not_of(" "));
    }
    std::ostream& operator<<(std::ostream& os, const Movie& m) {
        os << setw(40) << m.m_title << " | " << setw(4) << m.m_releYear << " | "<<m.m_desc << '.' << endl;
        return os;
    }
}
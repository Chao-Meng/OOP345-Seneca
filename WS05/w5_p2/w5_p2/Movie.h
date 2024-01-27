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
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H


#include <string>
#include <cstddef>
#include <iostream>


//using namespace std;

namespace sdds {
    class Movie {
        std::string m_title;
        std::string m_releYear;
        std::string m_desc;
    public:
        Movie();
        const std::string& title() const;
        Movie(const std::string& strMovie);
        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_title);
            spellChecker(m_desc);
        }
        friend std::ostream& operator<<(std::ostream& os, const Movie& m);
    };
}
#endif
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
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <cstddef>
#include <string>

using namespace std;

namespace sdds {
    class Book {
        string m_author;
        string m_title;
        string m_country;
        size_t m_year;
        double m_price;
        string m_desc;
    public:
        Book();
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        Book(const std::string& strBook);
        friend std::ostream& operator<<(std::ostream& os, const Book& b);
    };

}
#endif
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

#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H
#include <cstddef>
#include <string>
using namespace std;

namespace sdds {
    class ProteinDatabase {
       string* m_arr={};
       size_t m_count={};
    public:
        ProteinDatabase();
        ProteinDatabase(string str);//a string containing the name of a file
        ProteinDatabase(ProteinDatabase& proteinDatabase);
        ProteinDatabase(ProteinDatabase&& proteinDatabase) noexcept;
        ProteinDatabase& operator=(ProteinDatabase& proteinDatabase);
        ProteinDatabase& operator=(ProteinDatabase&& proteinDatabase) noexcept;
        ~ProteinDatabase();
        size_t size();
        std::string operator[](size_t);
    };
}


#endif

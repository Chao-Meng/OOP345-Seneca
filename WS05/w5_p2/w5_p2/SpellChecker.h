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
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <cstddef>
#include <string>

using namespace std;

namespace sdds {
    class SpellChecker {
        string m_badWords[6];
        string m_goodWords[6];
        int m_count[6] = { 0 };
    public:
        SpellChecker();
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}
#endif

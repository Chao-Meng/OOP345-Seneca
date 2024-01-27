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
#include <string>
#include <iostream>
#include <iomanip>
//#include <cstdlib>
#include <fstream>
//#include <vector>

//#include <cstddef>

#include "SpellChecker.h"
//using namespace std;
namespace sdds {

 
    SpellChecker::SpellChecker(){
       // m_count = 0;
    }
    SpellChecker::SpellChecker(const char* filename) {
        //open the file via reading
        ifstream file(filename);
        size_t start = 0;
        if (!file) {
            throw " Bad file name!";
        }
        else {
            for (int i = 0;i < 6;i++) {
                string tem;
                std::getline(file,tem,'\n');
                start = tem.find(" ");
                m_badWords[i] = tem.substr(0, start);
                m_goodWords[i] = tem.substr(start, tem.length() - 1);
                m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(" "));
                
                
            }
        }
    }

    void SpellChecker::operator()(std::string& text) {
        
       // static int count;
        for (int i = 0;i < 6;i++) { 
             size_t pos = 0;
             bool finished = false;
           while (!finished) {
               pos = text.find(m_badWords[i]);
                if (pos != string::npos) {
                    text.std::string::replace(pos, m_badWords[i].length(), m_goodWords[i]);
                    m_count[i] += 1;
                }
                else {
                    finished = true;
                }
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const {
        out << "Spellchecker Statistics" << endl;

        for (int i = 0;i <6;i++) {
            out<<setw(15) << m_badWords[i] <<": " << m_count[i] << " replacements" << endl;

        }
    }
        
}
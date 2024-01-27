/*
	==================================================
	Workshop 6 Part 2:
	==================================================
	Name   :Chao Meng
	ID     :128438215
	Email  :cmeng14@myseneca.ca
	Section:ZBB
	Date   :07/08/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Car.h"
using namespace std;
namespace sdds {
    Car::Car() {
       m_maker={};
       m_condition={};
       m_topSpeed=0.00;
    }
    Car::Car(std::istream& istr) {
        string s;
        getline(istr, s);
        size_t start = 0;
        size_t end =s.find(",");
        string tag = {};
        tag = s.substr(0, end - start);
        if (tag!="c") {
            throw string("Invaild tag");
        }

        start = end + 1;
        end = s.find(",", start);
        m_maker = s.substr(start, end - start);
        m_maker.erase(0, m_maker.find_first_not_of(" "));
        m_maker.erase(m_maker.find_last_not_of(" ") + 1, m_maker.length());

        start = end + 1;
        end = s.find(",", start);
        string condition;
        condition = s.substr(start, end - start);
        condition.erase(0, condition.find_first_not_of(" "));
        condition.erase(condition.find_last_not_of(" ") + 1, condition.length());
        switch (condition.at(0)) {
        case 'n':
           m_condition = "new";
            break;
        case 'u':
            m_condition = "used";
            break;
        case 'b':
            m_condition ="broken";
            break;
        default:
            throw string("Invaild condition");
        }

        start = end + 1;
        end = s.find('\0', start);
        string speed = s.substr(start, end - start);
        speed.erase(0, speed.find_first_not_of(" "));
        speed.erase(speed.find_last_not_of(" ") + 1, speed.length());
        if (speed.find_first_of("0123456789")!= std::string::npos) {
            m_topSpeed = stod(speed);
        }
        else {
            throw string("Invalid spped");
        } 
    }
    std::string Car::condition()const {
        return m_condition;
    }

    double Car::topSpeed() const {
        return m_topSpeed;
    }

    void Car::display(std::ostream& out)const {
        out << "| " << std::right << setw(10) << m_maker << " | ";
        out << std::left << setw(6) << m_condition << " | ";
        out << std::right<<fixed << setprecision(2) << m_topSpeed << " | " ;
    }

}
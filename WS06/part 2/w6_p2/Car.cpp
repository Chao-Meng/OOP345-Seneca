/*
	==================================================
	Workshop 6 Part 2:
	==================================================
	Name   :Chao Meng
	ID     :128438215
	Email  :cmeng14@myseneca.ca
	Section:ZBB
	Date   :07/10/2022
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
    //read a single record from the stream
    //extract all the information about a single car and store it in the attributes.
    Car::Car(std::istream& in) {
        string s;
        getline(in, s);
        size_t start = 0;
        size_t end =s.find(",");
        string tag = {};
        tag = s.substr(0, end - start);
        tag.erase(0, tag.find_first_not_of(" "));
        tag.erase(tag.find_last_not_of(" ") + 1, tag.length());
       /* if (tag!="c"&& tag != "C" && tag != "r" && tag != "R") {
            throw string("Invaild tag");
        }*/
        //extract maker info
        start = end + 1;
        end = s.find(",", start);
        m_maker = s.substr(start, end - start);
        m_maker.erase(0, m_maker.find_first_not_of(" "));
        m_maker.erase(m_maker.find_last_not_of(" ") + 1, m_maker.length());
        //extract condition info
        start = end + 1;
        end = s.find(",", start);
        string condition;
        condition = s.substr(start, end - start);
        condition.erase(0, condition.find_first_not_of(" "));
        condition.erase(condition.find_last_not_of(" ") + 1, condition.length());
        //match the condition info with status
        if (condition.length() == 0) {
            m_condition = "new";
        }
        else {
            switch (condition.at(0)) {
            case 'n':
               m_condition = "new";
                break;
            case ' ':
                m_condition = "new";
                break;
            case 'u':
                m_condition = "used";
                break;
            case 'b':
                m_condition ="broken";
                break;
            default:
                throw string("Invalid record!");
            }
        }
        //extract speed info
        start = end + 1;
        end = s.find(",", start);
        string speed = s.substr(start, end - start);
        speed.erase(0, speed.find_first_not_of(" "));
        speed.erase(speed.find_last_not_of(" ") + 1, speed.length());
        //Only the content of this field is a number,the field is considered valid and as speed value.
        if (speed.find_first_of("0123456789")!= std::string::npos) {
            m_topSpeed = stod(speed);
        }
        else {
            throw string("Invalid record!");
        } 
    }
    //getter, maker, to be used for display, the member attribute is private,
    //using private attribute in display function is not a good practice
    std::string Car::maker()const {
        return m_maker;
    }
    //getter, condition
    std::string Car::condition()const {
        return m_condition;
    }
    //getter, topspeed
    double Car::topSpeed() const {
        return m_topSpeed;
    }

    void Car::display(std::ostream& out)const {
        out << "| " << std::right << setw(10) << maker() << " | ";
        out << std::left << setw(6) << condition() << " | ";
        out << std::right<<fixed << setprecision(2) << topSpeed() << " |";
    }

}
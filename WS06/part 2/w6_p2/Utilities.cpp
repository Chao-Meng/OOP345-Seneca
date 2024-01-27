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
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include "Utilities.h"
#include "Autoshop.h"
#include "Car.h"
#include "Vehicle.h"
#include "Racecar.h"
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
        std::string s;
        std::getline(in, s);
        size_t start = 0;
        size_t end = s.find(",");
        std::string tag = {};
        tag = s.substr(0, end - start);
        tag.erase(0, tag.find_first_not_of(" "));
        tag.erase(tag.find_last_not_of(" ") + 1, tag.length());
        Vehicle* v = nullptr;
        std::stringstream ss(s);//save data
        if (tag.length() > 0) {
            if (tag == "c" || tag == "C") {
                //dynamically create an instance of type Car passing the stream to the constructor
                //Vehicle* v = nullptr;
                v = new Car(ss);
            }
            else if (tag == "r" || tag == "R") {
                v = new Racecar(ss);
            }
            else {
                throw std::string("Unrecognized record type: [") + tag.at(0) + "]";
            }
        }
        return v;   
	}

}
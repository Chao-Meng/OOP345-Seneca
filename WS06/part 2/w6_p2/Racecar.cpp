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
#include <fstream>
#include <sstream>
#include "Racecar.h"
using namespace std;
namespace sdds {
	Racecar::Racecar():Car() {
		m_booster = 0.00;
	}
	Racecar::Racecar(std::istream& in):Car(in) {
		//The read pointer of the parent class is already at the end
		//needs to be set back to the beginning
		in.seekg(0, ios::beg);
		string s;
		getline(in, s);
		size_t start = s.find_last_of(",");
		size_t end = s.find("\n"); 
		string booster = {};
		booster = s.substr(start+1, end - start );
		booster.erase(0, booster.find_first_not_of(" "));
		booster.erase(booster.find_last_not_of(" ") + 1, booster.length());
		if(booster.empty()==false){
			m_booster = stod(booster);
		}
		else {
			m_booster = 0.00;
		}	
	}
	void Racecar::display(std::ostream& out)const {
		Car::display(out);
		//if (m_booster > 0) {
			out << '*';
		//}
	}
	//return the top speed of the car, including any booster effects.
	double Racecar::topSpeed()const {
		return (Car::topSpeed() + (Car::topSpeed() * m_booster));
	}
}
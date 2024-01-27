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

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include <istream>
#include "Vehicle.h"
using namespace std;
namespace sdds
{
	class Car : public Vehicle {
		string m_maker;
		string m_condition;
		double m_topSpeed;
	public:
		Car();
		Car(std::istream& istr);
		std::string condition()const;
		double topSpeed() const;
		void display(std::ostream& out)const;
	};
}


#endif

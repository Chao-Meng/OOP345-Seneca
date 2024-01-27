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

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include <string>
#include <istream>
#include "Car.h"
//using namespace std;
namespace sdds
{
	class Racecar : public Car {
		double m_booster;
	public:
		Racecar();
		Racecar(std::istream& in);
		void display(std::ostream& out)const;
		double topSpeed()const;
	};
}
#endif

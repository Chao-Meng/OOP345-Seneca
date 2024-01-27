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

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <string>
#include <vector>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop();
		~Autoshop();
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out)const;
	};
}
#endif

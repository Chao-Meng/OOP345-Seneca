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

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

#include "Vehicle.h"
#include "Car.h"
namespace sdds{
	class Autoshop{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop();
		//destructors
		~Autoshop();
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out)const;
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			/*for (auto& vehicle : m_vehicles) {
				if (test(vehicle))
				{
					vehicles.push_back(vehicle);
				}
			}*/
			for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it) {
				if (test(*it)) {
					vehicles.push_back(*it);
				}	
			}
						
		}
		
	};
}
#endif

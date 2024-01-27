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
#include <iomanip>
#include "Autoshop.h"
namespace sdds {
	Autoshop::Autoshop() {

	}
	Autoshop::~Autoshop() {
		for (auto& vehicle : m_vehicles) {
			delete vehicle;
			vehicle = nullptr;
		}
	}

	//adds the vehicle received as parameter into the m_vehicles vector
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out)const {
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
	for (auto& vehicle : m_vehicles) {
		//for(int i=0; i< m_vehicles.size();i++){
		vehicle->display(out);
		out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}
}
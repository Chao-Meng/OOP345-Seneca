/*
	==================================================
	Workshop 8 Part 2:
	==================================================
	Name   :Chao Meng
	ID     :128438215
	Email  :cmeng14@myseneca.ca
	Section:ZBB
	Date   :07/23/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		EmployeeWage* temp = nullptr;
		for (auto i = 0u;i < emp.size();i++) {
			for (auto j = 0u;j < sal.size();j++) {
				if (emp[i].id == sal[j].id ) {
					if(!activeEmp.checkSin(emp[i].id)){
						temp = new EmployeeWage(emp[i].name, sal[j].salary);
						//if the salary is out of the condition, must delete the new memory
						try {
							temp->rangeValidator();
						}
						catch (const string& msg) {
							delete temp;
							throw std::string("*** Employees salaray range is not valid");
						}
						activeEmp += temp;
						if (temp != nullptr) {
							delete temp;
							temp = nullptr;
						}
					}
					else {
						throw std::string("*** Employees salaray range is not valid");
					}
				}
			}
			
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		for (auto i = 0u;i < emp.size();i++) {
			for (auto j = 0u;j < sal.size();j++) {
				if (emp[i].id == sal[j].id) {
					if (!activeEmp.checkSin(emp[i].id)) {
						std::unique_ptr< EmployeeWage> temp(new EmployeeWage(emp[i].name, sal[j].salary));
						temp->rangeValidator();
						activeEmp += temp;
						temp=nullptr;
					}
					else {
						throw std::string("*** Employees salaray range is not valid");
					}
				}
			}

		}

		return activeEmp;
	}
}

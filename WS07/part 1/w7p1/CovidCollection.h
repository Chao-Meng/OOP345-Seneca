/*
	==================================================
	Workshop 7 Part 2:
	==================================================
	Name   :Chao Meng
	ID     :128438215
	Email  :cmeng14@myseneca.ca
	Section:ZBB
	Date   :07/10/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include <list>
//using namespace std;
namespace sdds
{
	struct Covid{
		std::string m_country;
		std::string m_city;
		std::string m_variant;
		int m_cases;
		int m_year;
		int m_numDeath;
		size_t m_covidLength;
		Covid();
		Covid(const std::string& ss);
	};
	class CovidCollection {
		std::vector <Covid> elems;
		size_t m_length;
	public:
		CovidCollection(const char* fileName);
		void display(std::ostream& out) const;
		void sort();
		void cleanList();
		bool inCollection() const;
		std::list<Covid> getListForCountry() const;
		std::list<Covid> getListForVariant() const;
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif
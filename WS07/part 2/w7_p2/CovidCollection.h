/*
	==================================================
	Workshop 7 Part 2:
	==================================================
	Name   :Chao Meng
	ID     :128438215
	Email  :cmeng14@myseneca.ca
	Section:ZBB
	Date   :07/17/2022
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
		int m_deaths;
		size_t m_covidLength;
		//there should be getter, beacause it's a good practice to use the return value of 
		//getter instead of private member value in display func
		void setYear(int y);
		auto getYear()const;
		Covid();
		Covid(const std::string& ss);
	};
	class CovidCollection {
		std::vector <Covid> elems;
		size_t m_length;
	public:
		CovidCollection(const char* fileName);
		void display(std::ostream& out) const;
		void sort(const char* parameter);
		void cleanList();
		bool inCollection(const char* variant) const;
		//this func was not used in main
		std::list<Covid> getListForCountry(const std::string& country) const;
		std::list<Covid> getListForVariant(const std::string& variant) const;
	};
	//helper
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif
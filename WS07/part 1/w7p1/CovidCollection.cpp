/*
	==================================================
	Workshop 7 Part 2:
	==================================================
	Name   :Chao Meng
	ID     :128438215
	Email  :cmeng14@myseneca.ca
	Section:ZBB
	Date   :07/15/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

#include <algorithm>
#include <numeric>

#include "CovidCollection.h"
//using namespace std;
namespace sdds {
	Covid::Covid() {
		 m_country="[NONE]";
		m_city = "[NONE]";
		m_variant = "[NONE]";
		m_cases=0;
		m_year=0;
		m_numDeath=0;
		m_covidLength = 0;
	}
	Covid::Covid(const std::string& ss):Covid() {
		auto trim = [](std::string string) {

			if (!string.empty() && !std::all_of(string.begin(), string.end(), isspace))
			{

				while (string.at(0) == ' ')
					string = string.substr(1, string.length() - 1);

				while (string.at(string.length() - 1) == ' ')
					string = string.substr(0, string.length() - 1);

			}
			return string;
		};



		if (!ss.empty()) {


			m_country = trim((ss.substr(0, 24)));
			m_city = trim(ss.substr(24, 25));
			m_variant= trim(ss.substr(50, 25));
			int s = stoi(ss.substr(75, 4));
			if (s < 0) {
				std::string(s) = " ";
				std::string(m_year) = " ";
			}
			m_year = s;
			//m_year = stod(ss.substr(75,4));
			m_cases = stod(ss.substr(79,5));
			m_numDeath=stod(ss.substr(85,5));
			m_covidLength= stoul(trim(ss.substr(80, 5)));
			
			

			/*try {
				m_price = stod(line.substr(85, 5));
			}
			catch (...) {
				throw "The price is not a number.";
			}*/

		}
	}
	CovidCollection::CovidCollection(const char* fileName) {
		//std::ifstream file(fileName);
		m_length = 0;
		if (!fileName)
		{
			throw  std::string("ERROR: Cannot open file [ ")+fileName +std::string("]");
			//std::cerr << "ERROR: Cannot open file [" << fileName << "].\n";
			return;
		}
		std::ifstream read(fileName);
		std::string ss;
		if (std::string(fileName) == "covids.txt") {
			if (read.good()) {
				while (std::getline(read, ss)) {
					if (!ss.empty()) {
						//Covid temp(ss);
						elems.push_back(ss);
						m_length += elems.back().m_covidLength;


					}
				}
			}	
		}
		else {
			throw  fileName + std::string("is not correct");
		}
		read.close();
	}
	void CovidCollection::display(std::ostream& out) const {
		std::for_each(elems.begin(), elems.end(), [&](const Covid c) {
			out << c << std::endl; });
	}
	void CovidCollection::sort() {

	}
	void CovidCollection::cleanList() {

	}
	bool CovidCollection::inCollection() const {

	}
	std::list<Covid> CovidCollection::getListForCountry() const {

	}
	std::list<Covid> CovidCollection::getListForVariant() const {

	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		
		out << "| " << std::left << std::setw(20) << theCovid.m_country;
		out << "| " << std::left << std::setw(15) << theCovid.m_city;
		out << "| " << std::left << std::setw(20) << theCovid.m_variant;
		out << "| " << std::left << std::setw(6) << theCovid.m_year;
		out << "| " << std::left << theCovid.m_cases;
		
		out << " | " << std::left << theCovid.m_numDeath << " | ";
		return out;
	}
}
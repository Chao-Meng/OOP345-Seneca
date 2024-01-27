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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
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
		m_variant = {};//"[NONE]";
		m_cases=0;
		m_year=0;
		m_deaths=0;
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
			/*if (s < 0) {
				m_year = ' ';
			}*/
			setYear(s);
			//m_year = stod(ss.substr(75,4));
			m_cases = stod(ss.substr(79,5));
			m_deaths =stod(ss.substr(85,5));
			m_covidLength= stoul(trim(ss.substr(80, 5)));

		}
	}
	void Covid::setYear(int y) {
			m_year = y;	
	}

	auto Covid::getYear()const {
		return m_year;
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
	//display // 求和
	void CovidCollection::display(std::ostream& out) const {
		std::for_each(elems.begin(), elems.end(), [&](const Covid c) {
			out << c << std::endl; });
		out << "----------------------------------------------------------------------------------------" << std::endl;
		out << "|                                                 Total Cases Around the World:  ";
		//calculate the cases ,not use manual loop
		out<<std::accumulate(elems.begin(), elems.end(), (int)0, [](int sum, const Covid c) {
			return sum + c.m_cases;
			});
		out<< " |" << std::endl;
		//calculate the death number
		out << "|                                                Total Deaths Around the World:  ";
		out << std::accumulate(elems.begin(), elems.end(), (int)0, [](int sum, const Covid c) {
			return sum + c.m_deaths;
			});
		out<< " |"<< std::endl;
	}

	void CovidCollection::sort(const char* parameter) {
		auto com = [=](Covid c1, Covid c2) {
			
			if (strcmp(parameter ,"country")==0) {
				return c1.m_country < c2.m_country;
			}
			else if (strcmp(parameter, "variant")==0) {
				return c1.m_variant < c2.m_variant;
			}
			else if (strcmp(parameter, "cases")==0) {
				return c1.m_cases < c2.m_cases;
			}
			else //if (strcmp(parameter ,"deaths")==0) {
				return c1.m_deaths < c2.m_deaths;
			//}
		};
		std::sort(elems.begin(), elems.end(),com);		
	}

	void CovidCollection::cleanList() {
		auto clean = [](Covid& c) {
			if (c.m_variant == "[None]") {
				c.m_variant=" ";
			}
		};
		std::for_each(elems.begin(), elems.end(), clean);
	}

	bool CovidCollection::inCollection(const char* variant) const {
		return std::any_of(elems.begin(), elems.end(), [variant](const Covid c) {
			return c.m_variant == variant;
			});
	}
	std::list<Covid> CovidCollection::getListForCountry(const std::string& country) const {
		
			auto count=count_if(elems.begin(), elems.end(), [&country](const Covid c) {
			return c.m_country == country;
				});
			std::list<Covid> co(count);
			auto listCountry = copy_if(elems.begin(), elems.end(), co.begin(), [&country](const Covid& c) {
				return c.m_country == country;
				});
			co.resize(std::distance(co.begin(), listCountry));
			return co;
	}

	std::list<Covid> CovidCollection::getListForVariant(const std::string& variant) const {

		auto count = count_if(elems.begin(), elems.end(), [&variant](const Covid c) {
			return c.m_variant == variant;
			});
		std::list<Covid> va(count);
		//va.clear();
		//copy elements from vector in the some condition  
		auto listVariant = copy_if(elems.begin(), elems.end(), va.begin(), [&variant](const Covid& c) {
		return c.m_variant == variant;
			});

		va.resize(std::distance(va.begin(), listVariant));

		return va;
	}

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		out << "| " << std::left << std::setw(20) << theCovid.m_country;
		out << "  | " << std::left << std::setw(15) << theCovid.m_city;
		out << " | " << std::left << std::setw(20) << theCovid.m_variant;
		
		if (theCovid.getYear() < 0) {
			out << " | " << std::left << std::setw(6) << " ";
		}
		else {
			out << " | " << std::right << std::setw(6) << theCovid.getYear();
		}
		out << " |  " << std::right<< std::setw(3) << theCovid.m_cases;
		out << " | " << std::right << std::setw(3) << theCovid.m_deaths << " |";
		return out;
	}
}
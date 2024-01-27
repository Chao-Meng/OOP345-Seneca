/*
    ==================================================
    Workshop 3 Part 2:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :06/04/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <chrono>
#include <cstddef>
#include <string>
#include <utility>

namespace sdds {
	
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		
		const std::string& getKey() const{ return m_key; }
		const std::string& getValue()const { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};
		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.
		Pair();
		Pair(const Pair& P);
		
		std::ostream& display(std::ostream& os) const {
			os.width(20);
			os.setf(std::ios::right);
			os << m_key << " : ";
			os.unsetf(std::ios::right);
			os<< m_value << std::endl;
			return os;
		}
		

	};
		/*std::ostream& operator<<(std::ostream& os, const Pair& p) {
			return p.display(os);
	}*/
		
}

#endif

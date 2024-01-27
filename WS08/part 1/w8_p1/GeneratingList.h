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
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool checkSin(std::string sin) {
			int xCheck = atoi(sin.c_str());
			int size =(int)sin.length();
			int sum = 0;
			int m = 0;
			int v = 0;
			for (int i = 0;i < size;i++) {
				if (i % 2 == 1) {
					m = sin[i] * 2;
					if (m > 10) {
						v = m / 10 + m % 10;
					}
					else {
						v = m;
					}
				}
				else {
					v = sin[i];
				}
				sum += v;
			}
			return (sum % 10 == 0);
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(const T* t) {
			list.push_back(*t);
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H

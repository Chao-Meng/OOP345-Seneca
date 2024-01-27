/*
    ==================================================
    Workshop 5 Part 2:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :06/18/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <cstddef>
#include <string>
//#include <stdexcept>

//using namespace std;
namespace sdds{
    template <class T>
    class Collection {
        std::string m_name;
        T* m_arr;
        size_t m_size;
        void (*function)(const Collection<T>&, const T&);
        void observer(const T& item) {
            //if (m_arr) {
            //    T* t = new T[m_size + 1];
            //    for (size_t i = 0;i < m_size;i++) {
            //        t[i] = m_arr[i];
            //    }
            //    
            //    m_arr = t;
            //    t = nullptr;
            //    m_arr[m_size] = item;
            //    m_size++;
            //}
            //else {
            //    m_arr = new T[1];
            //    m_arr[0] = item;
            //    m_size = 1;
            //}
            if (m_arr) {
                T* t = new T[m_size + 1];
                for (size_t i = 0;i < m_size;i++) {
                    t[i] = m_arr[i];
                }

                t[m_size] = item;
                delete[] m_arr;
                m_arr = t;
                t = nullptr;
                m_size++;
            }
            else {
                m_arr = new T[1];
                m_arr[0] = item;
                m_size = 1;
            }
        }
    public:
        Collection(const std::string& name) {
            m_name = name;
            m_arr = nullptr;
            m_size = 0;
            function = nullptr;
        }
            //set any copy constructor an copy assignment to delete
        Collection(const Collection & c) = delete;
        Collection& operator=(const Collection & c) = delete;
        ~Collection() {
            if (m_arr != nullptr) {
                delete[] m_arr;
                m_arr = nullptr;
            }
        }

        const std::string& name() const {
            return m_name;
        }

        size_t size() const {
            return m_size;
        }

        int find(const std::string& title)const {
            int idx = -1;
            for (int i = 0;i < (int)m_size;i++) {
                if (m_arr[i].title() == title) {
                    idx = i;
                    break;
                }
            }
            return idx;
        }

        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            function = observer;
        }

        Collection<T>& operator+=(const T& item) {
            int index = find(item.title());
            if (index == -1) {
                observer(item);
                if (function != nullptr) {
                    function(*this, item);
                }
            }
            return *this;
        }

        T& operator[](size_t idx) const {
            std::string msg;
            msg = "Bad index ["+ std::to_string(idx)+"]. Collection has [" +std::to_string(m_size) +"] items.";
            if (idx > (m_size - 1)) {
                throw std::out_of_range(msg);
            }
            return m_arr[idx];
        }

        T* operator[](const std::string& title) {
            int idx = find(title);
            T* t = nullptr;
            return idx != -1 ? &m_arr[idx]:t;
        }

        friend std::ostream& operator<<(std::ostream& os, const Collection<T>& c) {
            for (size_t i = 0;i < c.m_size;i++) {
                os << c.m_arr[i];
            }
            return os;
        }
    };
}
#endif
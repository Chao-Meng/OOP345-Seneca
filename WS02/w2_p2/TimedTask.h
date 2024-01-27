/*
    ==================================================
    Workshop 2 Part 2:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :05/28/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H
#include <chrono>
#include <cstddef>
#include <string>
using namespace std;

namespace sdds {
    class TimedTask {       
        int recordNum={};
        //the start time for the current task
         std::chrono::time_point<std::chrono::steady_clock> start;
         std::chrono::time_point<std::chrono::steady_clock> end;
        struct task {
            string taskName{};
            string timeUnit{};
            chrono::steady_clock::duration dur;
        }t[10];
    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char* taskName);
    friend ostream & operator<< (std::ostream &ostr,const TimedTask &t);
    };
    

}


#endif
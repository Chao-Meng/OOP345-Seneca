/*
    ==================================================
    Workshop 2 Part 1:
    ==================================================
    Name   :Chao Meng
    ID     :128438215
    Email  :cmeng14@myseneca.ca
    Section:ZBB
    Date   :05/27/2022
*/
/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H
#include <chrono>
using namespace std;

namespace sdds {
  /*  template<
        class Clock,
        class Duration = typename Clock::duration
    > class time_point;*/

 

    class TimedTask {
        
        int recordNum;

        //the start time for the current task
         std::chrono::time_point<std::chrono::steady_clock> start;//=std::chrono::system_clock::now();
         std::chrono::time_point<std::chrono::steady_clock> end;
        //const auto end = std::chrono::steady_clock::now();//the end time for the current task (an object of type 
        struct task {
            string taskName{};
            string timeUnit{};
            //std::chrono::time_point<std::chrono::system_clock> dur;
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
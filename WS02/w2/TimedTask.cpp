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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string.h>
#include <vector>
#include <sstream>
#include "TimedTask.h"

namespace sdds {

    TimedTask::TimedTask() {

    }
    void TimedTask::startClock() {
        start = chrono::steady_clock::now();
    }
    void TimedTask::stopClock() {
       // end = chrono::system_clock::now();
        end = chrono::steady_clock::now();
    }
    void TimedTask::addTask(const char* task) {
       static int i = 0;
       
       t[i].dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        //t[i].dur = dura;
       // double durationSecond = t[i].dur.count();
       t[i].timeUnit = " nanoseconds";
        t[i].taskName = task;
         i++;
         recordNum = i;
    }
    ostream& operator << (std::ostream& ostr, const TimedTask& T) {
        cout << "--------------------------" << endl;
        ostr << "Execution Times:" << endl;
        ostr << "--------------------------" << endl;
        
       for (int i = 0;i < T.recordNum;i++) {
        //for (int i = 0;i < 10;i++) {
        //float durationNanoSecond = T.t[i].dur.count()*1000000000;
        //T.t[i].timeUnit = "nanoseconds";

        ostr << setw(21) << std::left << T.t[i].taskName << " " <<setw(13) << std::right << T.t[i].dur.count() << ' ' << T.t[i].timeUnit<< endl;
        }
        return ostr;
    }
}
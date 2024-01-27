
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
//external linkage
//This foodOrder module declare 2 global variables, which are also applied in main file
extern double g_taxrate;
extern double g_dailydiscount;
using namespace std;

namespace sdds {
    class FoodOrder {
        char m_orderName[10]{};
        //char m_foodDescr[25]{};//part1
        char* m_foodDescr;//part2
        double m_foodPrice;
        double m_spePrice;
        bool m_flag;
    public:
        FoodOrder();
        FoodOrder(const FoodOrder& F);//copy constructor
        ~FoodOrder();
        FoodOrder& operator=(FoodOrder& F);
        void read(istream& istr);
        void display();
    };
}
#endif
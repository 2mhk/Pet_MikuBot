#include <iostream>
using namespace std;



struct myInt
{
private:
    int count;

public:
    myInt& operator=(const myInt& toCompare)
    {
        static int ss;
        count = toCompare.count;
        cout << ss++ << "myInt - = myInt -:- " << toCompare.count << "\n";
        return *this;
    }

    myInt(){ cout << "myInt()\n"; }
    int GetNum(){ cout << "myInt - GetNum()\n"; return count; }

    myInt& operator=(const int& toCompare)
    {
        static int ss = 10000;
        count = toCompare;
        cout << ss++ << "myInt - = int -:- " << toCompare << "\n";
        return *this;
    }
};


//#pragma comment(linker, "/subsystem:console")
//#include <iostream>
//using namespace std;
//#include "tool_structure_1.h"
//
//
//struct t_a
//{
//    vector<myInt> a;
//    t_a()
//    {
//        cout << "t_a()\n";
//        int count = 0;
//        for (int i = 0; i < 10; i++)
//        {
//            myInt _topush;
//            _topush = i;
//            a.emplace_back(_topush);
//        }
//        for (myInt& _num : a)
//        {
//            _num = count++;
//            LogHeartBreak(_num.GetNum());
//        }
//    }
//    vector<myInt> GetList(){ cout << "t_a - GetList()\n"; return a; }
//    //vector<myInt>& GetList(){ cout << "t_a - GetList()\n"; return a; }
//};


//t_a taTest;
//for (auto& item : taTest.GetList())
//{
//    cout << item.GetNum();
//    //int a;
//    //a = item.GetNum();
//
//}

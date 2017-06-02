#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class SwappingDigits
{
public:
    string minNumber(string);
};

string SwappingDigits::minNumber(string num)
{
    string a, b, tem, ret = num;
    a = b = tem = num;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = i + 1; j < b.size(); j++)
        {
            tem[i] = b[j];
            tem[j] = a[i];
            if(tem[0] != '0')
                ret = min(ret, tem);
            tem = num;
        }
    }
    return ret;
}


double test0()
{
    string p0 = "596";
    SwappingDigits * obj = new SwappingDigits();
    clock_t start = clock();
    string my_answer = obj->minNumber(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "569";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1()
{
    string p0 = "93561";
    SwappingDigits * obj = new SwappingDigits();
    clock_t start = clock();
    string my_answer = obj->minNumber(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "13569";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2()
{
    string p0 = "5491727514";
    SwappingDigits * obj = new SwappingDigits();
    clock_t start = clock();
    string my_answer = obj->minNumber(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "1491727554";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3()
{
    string p0 = "10234";
    SwappingDigits * obj = new SwappingDigits();
    clock_t start = clock();
    string my_answer = obj->minNumber(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "10234";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4()
{
    string p0 = "93218910471211292416";
    SwappingDigits * obj = new SwappingDigits();
    clock_t start = clock();
    string my_answer = obj->minNumber(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "13218910471211292496";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}

int main()
{
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;

    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    time = test4();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

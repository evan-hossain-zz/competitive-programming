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

class Time
{
public:
    string whatTime(int);
};

string tostring(int n)
{
    string s, ret;
    do
    {
        s += (n % 10 + '0');
        n /= 10;
    }
    while(n);
    for(int i = s.size() - 1; i >= 0; i--)
        ret += s[i];
    return ret;
}

string Time::whatTime(int seconds)
{
    string ss;
    int h, m, s, cur = seconds;
    h = cur / 3600;
    cur = cur % 3600;
    m = cur / 60;
    s = cur % 60;
    ss = tostring(h) + ":" + tostring(m) + ":" + tostring(s);
    return ss;
}


double test0()
{
    int p0 = 0;
    Time * obj = new Time();
    clock_t start = clock();
    string my_answer = obj->whatTime(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "0:0:0";
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
    int p0 = 3661;
    Time * obj = new Time();
    clock_t start = clock();
    string my_answer = obj->whatTime(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "1:1:1";
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
    int p0 = 5436;
    Time * obj = new Time();
    clock_t start = clock();
    string my_answer = obj->whatTime(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "1:30:36";
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
    int p0 = 86399;
    Time * obj = new Time();
    clock_t start = clock();
    string my_answer = obj->whatTime(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "23:59:59";
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

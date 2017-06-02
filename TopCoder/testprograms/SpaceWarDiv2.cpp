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
#include <queue>

using namespace std;

class SpaceWarDiv2
{
public:
    int minimalFatigue(vector <int>, vector <int>, vector <int>);
};

int SpaceWarDiv2::minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector <int> enemyCount)
{
}


double test0()
{
    int t0[] = {2, 3, 5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1, 3, 4};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {2, 9, 4};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    SpaceWarDiv2 * obj = new SpaceWarDiv2();
    clock_t start = clock();
    int my_answer = obj->minimalFatigue(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 7;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    int t0[] = {2, 3, 5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1, 1, 2};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {2, 9, 4};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    SpaceWarDiv2 * obj = new SpaceWarDiv2();
    clock_t start = clock();
    int my_answer = obj->minimalFatigue(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 5;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    int t0[] = {14, 6, 22};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {8, 33};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {9, 1};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    SpaceWarDiv2 * obj = new SpaceWarDiv2();
    clock_t start = clock();
    int my_answer = obj->minimalFatigue(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = -1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    int t0[] = {17, 10, 29, 48, 92, 60, 80, 100, 15, 69, 36, 43, 70, 14, 88, 12, 14, 29, 9, 40};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {93, 59, 27, 68, 48, 82, 15, 95, 61, 49, 68, 15, 16, 26, 64, 82, 7, 8, 92, 15};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {56, 26, 12, 52, 5, 19, 93, 36, 69, 61, 68, 66, 55, 28, 49, 55, 63, 57, 33, 45};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    SpaceWarDiv2 * obj = new SpaceWarDiv2();
    clock_t start = clock();
    int my_answer = obj->minimalFatigue(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 92;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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

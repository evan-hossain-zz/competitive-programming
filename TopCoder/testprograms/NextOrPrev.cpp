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

class NextOrPrev
{
public:
    int getMinimum(int, int, string, string);
};


int NextOrPrev::getMinimum(int nextcost, int prevcost, string start, string goal)
{
    int shamne = 0, pichhe = 0, i, j, k, cost = 0;
    int l = start.size();
    map <char, int> m;
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < l ; j++)
        {
            if(start[j] > start[i] && goal[j] < goal[i])
                return -1;
        }

    }
    for(i = 0; i < l; i++)
    {
        int pos;
        pos = goal[i] - start[i];
        if(pos >= 0)
            cost += (nextcost * pos);
        else
            cost += (prevcost * -pos);
    }
    return cost;
}


double test0()
{
    int p0 = 5;
    int p1 = 8;
    string p2 = "ae";
    string p3 = "bc";
    NextOrPrev * obj = new NextOrPrev();
    clock_t start = clock();
    int my_answer = obj->getMinimum(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 21;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
    int p0 = 5;
    int p1 = 8;
    string p2 = "ae";
    string p3 = "cb";
    NextOrPrev * obj = new NextOrPrev();
    clock_t start = clock();
    int my_answer = obj->getMinimum(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = -1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
    int p0 = 1;
    int p1 = 1;
    string p2 = "srm";
    string p3 = "srm";
    NextOrPrev * obj = new NextOrPrev();
    clock_t start = clock();
    int my_answer = obj->getMinimum(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
    int p0 = 10;
    int p1 = 1;
    string p2 = "acb";
    string p3 = "bdc";
    NextOrPrev * obj = new NextOrPrev();
    clock_t start = clock();
    int my_answer = obj->getMinimum(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 30;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
    int p0 = 10;
    int p1 = 1;
    string p2 = "zyxw";
    string p3 = "vuts";
    NextOrPrev * obj = new NextOrPrev();
    clock_t start = clock();
    int my_answer = obj->getMinimum(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 16;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
double test5()
{
    int p0 = 563;
    int p1 = 440;
    string p2 = "ptrbgcnlaizo";
    string p3 = "rtscedkiahul";
    NextOrPrev * obj = new NextOrPrev();
    clock_t start = clock();
    int my_answer = obj->getMinimum(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 10295;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
double test6()
{
    int p0 = 126;
    int p1 = 311;
    string p2 = "yovlkwpjgsna";
    string p3 = "zpwnkytjisob";
    NextOrPrev * obj = new NextOrPrev();
    clock_t start = clock();
    int my_answer = obj->getMinimum(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = -1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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

    time = test5();
    if (time < 0)
        errors = true;

    time = test6();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

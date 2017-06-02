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

class CountExpressions2
{
public:
    int calcExpressions(int, int, int);
};

int CountExpressions2::calcExpressions(int x, int y, int val)
{
    int arr[4] = {x, y, x, y};
    bool col[4] = {0};
    int cnt = 0;
    int i, j, k, l, m, n, o;
    for(i = 0; i < 4; i++)
    {
        col[i] = 1;
        for(j = 0; j < 3; j++)
        {
            for(k = 0; k < 4; k++)
            {
                if(col[k]) continue;
                col[k] = 1;
                for(l = 0; l < 3; l++)
                {
                    for(m = 0; m < 4; m++)
                    {
                        if(col[m]) continue;
                        col[m] = 1;
                        for(n = 0; n < 3; n++)
                        {
                            for(o = 0; o < 4; o++)
                            {
                                if(col[o]) continue;
                                col[o] = 1;
                                long long sum = (long long) arr[i];
                                if(j == 0)
                                    sum = sum + arr[k];
                                else if(j == 1)
                                    sum = sum - arr[k];
                                else
                                    sum = (sum * arr[k]);
                                if(l == 0)
                                    sum = sum + arr[m];
                                else if(l == 1)
                                    sum = sum - arr[m];
                                else
                                    sum = (sum * arr[m]);
                                if(n == 0)
                                    sum = sum + arr[o];
                                else if(n == 1)
                                    sum = sum - arr[o];
                                else
                                    sum = (sum * arr[o]);
                                if(sum == val)
                                    cnt++;
                                col[o] = 0;
                            }
                        }
                        col[m] = 0;
                    }
                }
                col[k] = 0;
            }
        }
        col[i] = 0;
    }
    return cnt / 4;
}


double test0()
{
    int p0 = 7;
    int p1 = 8;
    int p2 = 16;
    CountExpressions2 * obj = new CountExpressions2();
    clock_t start = clock();
    int my_answer = obj->calcExpressions(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 9;
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
    int p0 = 3;
    int p1 = 5;
    int p2 = 7;
    CountExpressions2 * obj = new CountExpressions2();
    clock_t start = clock();
    int my_answer = obj->calcExpressions(p0, p1, p2);
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
    int p0 = 99;
    int p1 = 100;
    int p2 = 98010000;
    CountExpressions2 * obj = new CountExpressions2();
    clock_t start = clock();
    int my_answer = obj->calcExpressions(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 6;
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
    int p0 = -99;
    int p1 = 42;
    int p2 = -1764;
    CountExpressions2 * obj = new CountExpressions2();
    clock_t start = clock();
    int my_answer = obj->calcExpressions(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 2;
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
double test4()
{
    int p0 = 100;
    int p1 = -100;
    int p2 = -100000000;
    CountExpressions2 * obj = new CountExpressions2();
    clock_t start = clock();
    int my_answer = obj->calcExpressions(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 0;
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
double test5()
{
    int p0 = 1;
    int p1 = 2;
    int p2 = 5;
    CountExpressions2 * obj = new CountExpressions2();
    clock_t start = clock();
    int my_answer = obj->calcExpressions(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 17;
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

    time = test4();
    if (time < 0)
        errors = true;

    time = test5();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

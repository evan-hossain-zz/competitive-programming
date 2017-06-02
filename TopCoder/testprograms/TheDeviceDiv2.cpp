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

class TheDeviceDiv2
{
public:
    string identify(vector <string>);
};

string TheDeviceDiv2::identify(vector <string> plates)
{
    int i, j, cnt1 = 0, cnt0 = 0;
    for(i = 0; i < plates[0].size(); i++)
        {
            cnt0 = cnt1 = 0;
            for(j = 0; j < plates.size(); j++)
                {
                    if(plates[j][i] == '0')
                        cnt0++;
                    else
                        cnt1++;
                }
            if(cnt0 < 1 || cnt1 < 2)
                return "NO";
        }
    return "YES";
}


double test0()
{
    string t0[] = {"010",
                   "011",
                   "000"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    TheDeviceDiv2 * obj = new TheDeviceDiv2();
    clock_t start = clock();
    string my_answer = obj->identify(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "NO";
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
    string t0[] = {"1",
                   "0",
                   "1",
                   "0"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    TheDeviceDiv2 * obj = new TheDeviceDiv2();
    clock_t start = clock();
    string my_answer = obj->identify(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "YES";
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
    string t0[] = {"11111"}
                  ;
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    TheDeviceDiv2 * obj = new TheDeviceDiv2();
    clock_t start = clock();
    string my_answer = obj->identify(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "NO";
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
    string t0[] = {"0110011",
                   "0101001",
                   "1111010",
                   "1010010"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    TheDeviceDiv2 * obj = new TheDeviceDiv2();
    clock_t start = clock();
    string my_answer = obj->identify(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "NO";
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
    string t0[] = {"101001011",
                            "011011010",
                            "010110010",
                            "111010100",
                            "111111111"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    TheDeviceDiv2 * obj = new TheDeviceDiv2();
    clock_t start = clock();
    string my_answer = obj->identify(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "YES";
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

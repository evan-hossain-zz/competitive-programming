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

class WidgetRepairs {
public:
	int days(vector <int>, int);
};

int WidgetRepairs::days(vector <int> arrivals, int numPerDay)
{
    int i, cnt = 0, cur = 0, prev = 0;
    for(i = 0; i < arrivals.size(); i++)
    {
        cur = arrivals[i] + prev;
        if(cur > 0)
            cnt++;
        if(cur >= numPerDay)
            prev = cur - numPerDay;
        else
            prev = 0;
    }
    cnt += (prev / numPerDay);
    if(prev % numPerDay > 0)
        cnt++;
     return cnt;
}


double test0() {
	int t0[] = { 10, 0, 0, 4, 20 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 8;
	WidgetRepairs * obj = new WidgetRepairs();
	clock_t start = clock();
	int my_answer = obj->days(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = { 0, 0, 0 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 10;
	WidgetRepairs * obj = new WidgetRepairs();
	clock_t start = clock();
	int my_answer = obj->days(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = { 100, 100 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 10;
	WidgetRepairs * obj = new WidgetRepairs();
	clock_t start = clock();
	int my_answer = obj->days(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 20;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = { 27, 0, 0, 0, 0, 9 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 9;
	WidgetRepairs * obj = new WidgetRepairs();
	clock_t start = clock();
	int my_answer = obj->days(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = { 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	WidgetRepairs * obj = new WidgetRepairs();
	clock_t start = clock();
	int my_answer = obj->days(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 15;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
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

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

class RaceCalculator {
public:
	int bestRace(vector <int>, vector <int>);
};

int RaceCalculator::bestRace(vector <int> distances, vector <int> times)
{

}


double test0() {
	int t0[] = {1600,3200,16000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {299,655,4020};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RaceCalculator * obj = new RaceCalculator();
	clock_t start = clock();
	int my_answer = obj->bestRace(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int t0[] = {1600,2000,3200,3000,5000,9600};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {234,306,499,462,802,1629};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RaceCalculator * obj = new RaceCalculator();
	clock_t start = clock();
	int my_answer = obj->bestRace(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {1000,2000,3000,4000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {160,330,510,750};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RaceCalculator * obj = new RaceCalculator();
	clock_t start = clock();
	int my_answer = obj->bestRace(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int t0[] = {1000,50000,10000,5000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {200,70010,2250,1080};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RaceCalculator * obj = new RaceCalculator();
	clock_t start = clock();
	int my_answer = obj->bestRace(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

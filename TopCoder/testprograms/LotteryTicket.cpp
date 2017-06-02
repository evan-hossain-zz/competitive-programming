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

class LotteryTicket {
public:
	string buy(int, int, int, int, int);
};

int arr[4];
bool call(int indx, int sum, int price)
{
    if(sum == price)
        return true;
    if(indx >= 4)
        return false;
    return call(indx + 1, sum + arr[indx], price) || call(indx + 1, sum, price);
}

string LotteryTicket::buy(int price, int b1, int b2, int b3, int b4) {
    int i;
    arr[0] = b1, arr[1] = b2, arr[2] = b3, arr[3] = b4;
    if(call(0, 0, price))
        return "POSSIBLE";
    return "IMPOSSIBLE";
}


double test0() {
	int p0 = 10;
	int p1 = 1;
	int p2 = 5;
	int p3 = 10;
	int p4 = 50;
	LotteryTicket * obj = new LotteryTicket();
	clock_t start = clock();
	string my_answer = obj->buy(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 15;
	int p1 = 1;
	int p2 = 5;
	int p3 = 10;
	int p4 = 50;
	LotteryTicket * obj = new LotteryTicket();
	clock_t start = clock();
	string my_answer = obj->buy(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 65;
	int p1 = 1;
	int p2 = 5;
	int p3 = 10;
	int p4 = 50;
	LotteryTicket * obj = new LotteryTicket();
	clock_t start = clock();
	string my_answer = obj->buy(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 66;
	int p1 = 1;
	int p2 = 5;
	int p3 = 10;
	int p4 = 50;
	LotteryTicket * obj = new LotteryTicket();
	clock_t start = clock();
	string my_answer = obj->buy(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 1000;
	int p1 = 999;
	int p2 = 998;
	int p3 = 997;
	int p4 = 996;
	LotteryTicket * obj = new LotteryTicket();
	clock_t start = clock();
	string my_answer = obj->buy(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 20;
	int p1 = 5;
	int p2 = 5;
	int p3 = 5;
	int p4 = 5;
	LotteryTicket * obj = new LotteryTicket();
	clock_t start = clock();
	string my_answer = obj->buy(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int p0 = 2;
	int p1 = 1;
	int p2 = 5;
	int p3 = 10;
	int p4 = 50;
	LotteryTicket * obj = new LotteryTicket();
	clock_t start = clock();
	string my_answer = obj->buy(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
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

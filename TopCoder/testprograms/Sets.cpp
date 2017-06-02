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
#include <cstring>

#define SZ 1000005

using namespace std;

class Sets {
public:
	vector <int> operate(vector <int>, vector <int>, string);
};

int seet[2 * SZ];
vector <int> ret;

vector <int> Sets::operate(vector <int> A, vector <int> B, string operation) {
    int i;
//    ret.clear();
//    memset(seet, 0, sizeof seet);
    string I = "INTERSECTION", U = "UNION", S = "SYMMETRIC DIFFERENCE";
    for(i = 0; i < A.size(); i++)
    {
        if(A[i] < 0)
            seet[-A[i] + SZ]++;
        else
            seet[A[i]]++;
    }
    for(i = 0; i < B.size(); i++)
    {
        if(B[i] < 0)
            seet[-B[i] + SZ]++;
        else
            seet[B[i]]++;
    }
    if(operation == U)
    {
        for(i = 0; i < SZ; i++)
        {
            if(seet[i])
                ret.push_back(i);
        }
        for(i = SZ; i < 2 * SZ; i++)
        {
            if(seet[i])
                ret.push_back(-(i - SZ));
        }
    }
    else if(operation == I)
    {
         for(i = 0; i < SZ; i++)
        {
            if(seet[i] == 2)
                ret.push_back(i);
        }
        for(i = SZ; i < 2 * SZ; i++)
        {
            if(seet[i] == 2)
                ret.push_back(-(i - SZ));
        }
    }
    else
    {
         for(i = 0; i < SZ; i++)
        {
            if(seet[i] && seet[i] != 2)
                ret.push_back(i);
        }
        for(i = SZ; i < 2 * SZ; i++)
        {
            if(seet[i] && seet[i] != 2)
                ret.push_back(-(i - SZ));
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}


double test0() {
	int t0[] = {1,2,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,4,5,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "INTERSECTION";
	Sets * obj = new Sets();
	clock_t start = clock();
	vector <int> my_answer = obj->operate(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 3,  4 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1,2,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,4,5,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "UNION";
	Sets * obj = new Sets();
	clock_t start = clock();
	vector <int> my_answer = obj->operate(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 1,  2,  3,  4,  5,  6 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {432,756,123};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {534,76,1209};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "INTERSECTION";
	Sets * obj = new Sets();
	clock_t start = clock();
	vector <int> my_answer = obj->operate(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {-466719, -244027, -862196, 643531, -39291, 243096, -826803, -95873, 331987, 808483, -638570, 271226, 730732, -671848, 535948, 163231, -239133, 149077, -543551, 864301, 695924, -873674, 14355, 264947, -367384, 801789, -193466, -237645, 252191, -537796, 989441, -397021, 370805, -398819, 592359, 107395, -749452, 519852, 570249, -615550, 212357, -120019, 514511, -82354};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "SYMMETRIC DIFFERENCE";
	Sets * obj = new Sets();
	clock_t start = clock();
	vector <int> my_answer = obj->operate(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = {-873674, -862196, -826803, -749452, -671848, -638570, -615550, -543551, -537796, -466719, -398819, -397021, -367384, -244027, -239133, -237645, -193466, -120019, -95873, -82354, -39291, 14355, 107395, 149077, 163231, 212357, 243096, 252191, 264947, 271226, 331987, 370805, 514511, 519852, 535948, 570249, 592359, 643531, 695924, 730732, 801789, 808483, 864301, 989441};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {342,654,897,312,76,23,78};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {21,43,87,98,23,756,897,234,645,876,123};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "SYMMETRIC DIFFERENCE";
	Sets * obj = new Sets();
	clock_t start = clock();
	vector <int> my_answer = obj->operate(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 21,  43,  76,  78,  87,  98,  123,  234,  312,  342,  645,  654,  756,  876 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
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

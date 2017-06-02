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

class TomekPhone {
public:
	int minKeystrokes(vector <int>, vector <int>);
};

int TomekPhone::minKeystrokes(vector <int> frequencies, vector <int> keySizes) {
	int neg = 0, i, j, cnt = 0;
	for(i = 0; i < keySizes.size(); i++)
        neg += keySizes[i];
    if(neg < frequencies.size())
        return -1;
    sort(frequencies.rbegin(), frequencies.rend());
    sort(keySizes.begin(), keySizes.end());
    int agerta = 0, button = 1, l = keySizes.size();
    for(i = 0; i < frequencies.size(); i++)
    {
//        cout << button << endl;
        for(j = agerta; j < l; j++)
        {
            if(keySizes[j] >= button)
            {
                if(keySizes[j] == button)
                    keySizes[j] = 0;
                agerta = j + 1;
                cnt += (button * frequencies[i]);
                break;
            }
        }
        if(agerta == l)
        {
            agerta = 0;
            button++;
        }
    }
    return cnt;
}

double test0() {
	int t0[] = {442, 944, 214, 222, 651, 758, 963, 52, 649, 918, 326, 590, 55, 395, 26, 654, 170, 882, 95, 724, 426, 628, 57, 375, 112, 425, 399, 113, 556, 65, 337, 718, 299, 162, 279, 210, 575, 659, 850, 616, 306, 720, 103, 961, 804};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {45, 19, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TomekPhone * obj = new TomekPhone();
	clock_t start = clock();
	int my_answer = obj->minKeystrokes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 126591;
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
	int t0[] = {13,7,4,20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TomekPhone * obj = new TomekPhone();
	clock_t start = clock();
	int my_answer = obj->minKeystrokes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	int t0[] = {11,23,4,50,1000,7,18};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,1,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TomekPhone * obj = new TomekPhone();
	clock_t start = clock();
	int my_answer = obj->minKeystrokes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1164;
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
	int t0[] = {100,1000,1,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {50};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TomekPhone * obj = new TomekPhone();
	clock_t start = clock();
	int my_answer = obj->minKeystrokes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1234;
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
	int t0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10,10,10,10,10,10,10,10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TomekPhone * obj = new TomekPhone();
	clock_t start = clock();
	int my_answer = obj->minKeystrokes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3353;
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

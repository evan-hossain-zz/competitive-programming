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

class PrefixCode {
public:
	string isOne(vector <string>);
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

string PrefixCode::isOne(vector <string> words)
{
	int i, j, match = -1, s, brk = 1, cnt = 0;
	for(i = 0; i < words.size() && brk; i++)
    {
        for(j = 0; j < words.size(); j++)
        {
            if(i == j)
                continue;
            cnt = 0;
            if(words[i].size() > words[j].size())
            {
                for(s = 0; s < words[j].size(); s++)
                {
                    if(words[i][s] == words[j][s])
                        cnt++;
                    else
                        break;
                }
                if(cnt == words[j].size())
                {
                    brk = 0;
                    match = j;
                    break;
                }
            }
            else
            {
                for(s = 0; s < words[i].size(); s++)
                {
                    if(words[i][s] == words[j][s])
                        cnt++;
                    else
                        break;
                }
                if(cnt == words[i].size())
                {
                    brk = 0;
                    match = i;
                    break;
                }
            }
        }
    }
    if(match == -1)
        return "Yes";
    else
        return "No, " + tostring(match);
}


double test0() {
	string t0[] = {"trivial"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixCode * obj = new PrefixCode();
	clock_t start = clock();
	string my_answer = obj->isOne(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"10001", "011", "100", "001", "10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixCode * obj = new PrefixCode();
	clock_t start = clock();
	string my_answer = obj->isOne(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "No, 2";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"no", "nosy", "neighbors", "needed"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixCode * obj = new PrefixCode();
	clock_t start = clock();
	string my_answer = obj->isOne(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "No, 0";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"1010", "11", "100", "0", "1011"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixCode * obj = new PrefixCode();
	clock_t start = clock();
	string my_answer = obj->isOne(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"No", "not"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixCode * obj = new PrefixCode();
	clock_t start = clock();
	string my_answer = obj->isOne(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
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

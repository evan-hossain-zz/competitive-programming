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

string year[13] =  {"", "31", "28", "31", "30", "31", "30", "31", "31", "30", "31", "30", "31"};

class IDNumberVerification {
public:
	string verify(string, vector <string>);
};

bool isleap(string year)
{
    stringstream ss(year);
    int num;
    num = toint
    ss >> num;
    if(num % 400 == 0)
        return true;
    if(num % 4 == 0 && num % 100)
        return true;
    return false;
}

string IDNumberVerification::verify(string id, vector <string> regionCodes) {
	string RC = id.substr(0, 6), BY = id.substr(6, 4), BM = id.substr(10, 2), BD = id.substr(12, 2), checksum = id.substr(14, 3), ret;
	char x = id[17];
	int i;
	for(i = 0; i < regionCodes.size(); i++)
    {
        if(regionCodes[i] == RC)
            break;
    }
    if(i == regionCodes.size() || checksum == "000")
        return "Invalid";
    if(BM < "01" || BM > "12")
        return "Invalid";
    if(BY < "1900" || BY > "2011")
        return "Invalid";
    stringstream mnth(BM);
    int m, code;
    mnth >> m;
    if(m == 2)
    {
        if(BD > "29" || BD < "01")
            return "Invalid";
        if(BD == "29" && !isleap(BY))
            return "Invalid";
    }
    else if(year[m] < BD || BD < "01")
        return "Invalid";
    stringstream cs(checksum);
    cs >> code;
    if(code % 2)
        ret = "Male";
    else
        ret = "Female";
    if(x == 'X')
        code = 10;
    else
        code = (x - '0');
    for(i = 0, m = 17; i < id.size() - 1; i++, m--)
        code += ((id[i] - '0') * (1 << m));
    if(code % 11 == 1)
        return ret;
    return "Invalid";
}


double test0() {
	string p0 = "441323191602290964";
	string t1[] = {"441323"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Male";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "62012319240507058X";
	string t1[] = {"620123"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Female";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "321669197204300886";
	string t1[] = {"610111","659004"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Invalid";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "230231198306900162";
	string t1[] = {"230231"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Invalid";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "341400198407260005";
	string t1[] = {"341400"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Invalid";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string p0 = "520381193206090891";
	string t1[] = {"532922","520381"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Invalid";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

//template <class T> T sqr(T a){return a * a;}    // square
//template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
//template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
//template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
//template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
//template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
//template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
//template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
//template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

class AddMultiply {
public:
	vector <int> makeExpression(int y) {
		int i;
		for(i = 2; i <= 1000; i++)
        {
            if(abs(y - i) > 2 && abs(y - i) % 2 == 0)
            {
                vector <int> v;
                v.pb(2);
                v.pb((y - i) / 2);
                v.pb(i);
                return v;
            }
        }
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	AddMultiply *obj;
	vector <int> answer;
	obj = new AddMultiply();
	clock_t startTime = clock();
	answer = obj->makeExpression(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;

	int p0;
	vector <int> p1;

	// ----- test 0 -----
	disabled = false;
	p0 = 6;
	p1 = {2,2,2};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = 11;
	p1 = {2,3,5};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = 0;
	p1 = {7,10,-70};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = 500;
	p1 = {-400,-3,-700};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = 2;
	p1 = {2,2,-2};
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 5 -----
	disabled = false;
	p0 = 5;
	p1 = {5,2,-5};
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 6 -----
	disabled = false;
	p0 = 500;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, false, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 7 -----
	disabled = false;
	p0 = 1;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, false, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// You are given an int y.
// We are looking for any vector <int> x that satisfies the following constraints:
//
// x has exactly three elements
// ( x[0] * x[1] ) + x[2] = y
// Each x[i] must be between -1000 and 1000, inclusive.
// No x[i] can be equal to 0 or 1.
//
// Find and return one such x.
//
// If there are multiple valid solutions, you may return any of them.
// You may assume that for our constraints on y (specified below) at least one valid x always exists.
//
// DEFINITION
// Class:AddMultiply
// Method:makeExpression
// Parameters:int
// Returns:vector <int>
// Method signature:vector <int> makeExpression(int y)
//
//
// CONSTRAINTS
// -y will be between 0 and 500, inclusive.
//
//
// EXAMPLES
//
// 0)
// 6
//
// Returns: {2, 2, 2 }
//
// 2*2 + 2 = 6
//
// Note that this is one of many possible solutions. Another solution is:
//
// 3*3 + (-3) = 6
//
//
// 1)
// 11
//
// Returns: {2, 3, 5 }
//
//
//
// 2)
// 0
//
// Returns: {7, 10, -70 }
//
// Note that 0 and 1 are not allowed, thus a result like 0 * 0 + 0 would be incorrect.
//
// 3)
// 500
//
// Returns: {-400, -3, -700 }
//
// Some or all of the returned numbers may be negative.
//
// 4)
// 2
//
// Returns: {2, 2, -2 }
//
//
//
// 5)
// 5
//
// Returns: {5, 2, -5 }
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
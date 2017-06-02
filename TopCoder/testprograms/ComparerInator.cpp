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
#define infinity 2147483647
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

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

class ComparerInator {
public:
	int makeProgram(vector <int> A, vector <int> B, vector <int> wanted) {
		
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	ComparerInator *obj;
	int answer;
	obj = new ComparerInator();
	clock_t startTime = clock();
	answer = obj->makeProgram(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1};
	p1 = {2};
	p2 = {2};
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1,3};
	p1 = {2,1};
	p2 = {2,3};
	p3 = 7;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {1,3,5};
	p1 = {2,1,7};
	p2 = {2,3,5};
	p3 = -1;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,3,5};
	p1 = {2,1,7};
	p2 = {1,3,5};
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {1,2,3,4,5,6,7,8,9,10,11};
	p1 = {5,4,7,8,3,1,1,2,3,4,6};
	p2 = {1,2,3,4,3,1,1,2,3,4,6};
	p3 = 7;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {1,5,6,7,8};
	p1 = {1,5,6,7,8};
	p2 = {1,5,6,7,8};
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
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
// Comparer-inator is a very simple language that is specialized in comparisons. It takes an expression and returns the result. There are only two kinds of expressions: a variable name or a tertiary operator inspired by C syntax (which is also used in many languages like Java, C++, and C#). We are interested to use this language to process two vector <int>s, A and B to generate the vector <int> wanted as a result. We have previously found that there are four candidate programs that could be an optimal way to solve the issue we have. Each of the programs takes two arguments a and b.
// 
// "a" : This program will return the given argument a.
// "b" : This program will return the given argument b.
// "a<b?a:b" : If a is less than b, the program will return a, else it will return b.
// "a<b?b:a" : If a is less than b, the program will return b, else it will return a.
// 
// 
// Given vector <int> A, B and wanted find the shortest of the four candidate programs that, for every index i, will return wanted[i] after being provided a=A[i] and b=B[i] as arguments. Return the length of the shortest program. If no candidate program can do the required job, return -1 instead.
// 
// DEFINITION
// Class:ComparerInator
// Method:makeProgram
// Parameters:vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int makeProgram(vector <int> A, vector <int> B, vector <int> wanted)
// 
// 
// CONSTRAINTS
// -A will contain between 1 and 50 elements, inclusive.
// -B and wanted will each contain the same number of elements as A.
// -Each element of A, B and wanted will be between 1 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1}
// {2}
// {2}
// 
// Returns: 1
// 
// "b" and "a<b?b:a" (quotes for clarity) are the two programs that will return 2 after being given a=1, b=2 as arguments. "b" is the shortest of them.
// 
// 
// 1)
// {1,3}
// {2,1}
// {2,3}
// 
// Returns: 7
// 
// "a<b?b:a" is the only program that will return 2 after being provided a=1, b=2 and will also
// return 3 after being provided a=3, b=1.
// 
// 2)
// {1,3,5}
// {2,1,7}
// {2,3,5}
// 
// Returns: -1
// 
// None of the four programs can do the job correctly.
// 
// 3)
// {1,3,5}
// {2,1,7}
// {1,3,5}
// 
// Returns: 1
// 
// 
// 
// 4)
// {1,2,3,4,5,6,7,8,9,10,11}
// {5,4,7,8,3,1,1,2,3,4,6}
// {1,2,3,4,3,1,1,2,3,4,6}
// 
// Returns: 7
// 
// 
// 
// 5)
// {1,5,6,7,8}
// {1,5,6,7,8}
// {1,5,6,7,8}
// 
// Returns: 1
// 
// "a", "b", "a<b?a:b" and "a<b?b:a" are all valid programs that will give the wanted result. "a" and "b" are the shortest.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
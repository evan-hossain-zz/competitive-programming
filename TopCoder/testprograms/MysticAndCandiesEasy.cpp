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

class MysticAndCandiesEasy {
public:
    int box[55];
	int minBoxes(int C, int X, vector <int> high) {
		int n = SZ(high), i;
		int left = C;
		sort(high.begin(), high.end());
        for(i = 0; i < n; i++)
        {
            box[i] = min(high[i], left);
            left -= min(left, high[i]);
        }
        int res = 0;
        left = 0;
        for(i = n - 1; i >= 0; i--)
        {
            left += box[i];
            res++;
            if(left >= X)
                break;
        }
        return res;
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	MysticAndCandiesEasy *obj;
	int answer;
	obj = new MysticAndCandiesEasy();
	clock_t startTime = clock();
	answer = obj->minBoxes(p0, p1, p2);
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

	int p0;
	int p1;
	vector <int> p2;
	int p3;

	// ----- test 0 -----
	disabled = false;
	p0 = 5;
	p1 = 5;
	p2 = {1, 1, 1, 1, 1};
	p3 = 5;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = 10;
	p1 = 7;
	p2 = {3,3,3,3,3};
	p3 = 4;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = 100;
	p1 = 63;
	p2 = {12,34,23,45,34};
	p3 = 3;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = 19;
	p1 = 12;
	p2 = {12,9,15,1,6,4,9,10,10,10,14,14,1,1,12,10,9,2,3,6,1,7,3,4,10,3,14};
	p3 = 22;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = 326;
	p1 = 109;
	p2 = {9,13,6,6,6,16,16,16,10,16,4,3,10,8,11,17,12,5,7,8,7,4,15,7,14,2,2,1,17,1,7,7,12,17,2,9,7,1,8,16,7,4,16,2,13,3,13,1,17,6};
	p3 = 15;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
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
// TopCoder admin mystic_tc is sitting in front of a table. He found N sealed boxes of candies on the table.
//
//
// He is not sure how many candies each box contains. However, he knows the following information:
//
// The total number of candies in the boxes is C.
// For each i, box i (0-based index) contains between 0 and high[i] candies, inclusive.
//
//
// You know that mystic_tc eats candies as follows: first he chooses a subset of the boxes, then he opens them and eats all the candies he found inside.
// He wants to eat at least X candies.
// And as he is smart, he will always choose a subset of boxes for which he is sure that they must contain at least X candies.
//
//
// You are given the ints C and X, and the vector <int> high.
// Return the smallest number of boxes mystic_tc may choose.
//
// DEFINITION
// Class:MysticAndCandiesEasy
// Method:minBoxes
// Parameters:int, int, vector <int>
// Returns:int
// Method signature:int minBoxes(int C, int X, vector <int> high)
//
//
// CONSTRAINTS
// -high will contain between 1 and 50 elements, inclusive.
// -Each element of high will be between 1 and 50, inclusive.
// -C will be between 1 and the sum of all elements of high, inclusive.
// -X will be between 1 and C, inclusive.
//
//
// EXAMPLES
//
// 0)
// 10
// 10
// {20}
//
// Returns: 1
//
// There is only one box. It contains all 10 candies. In order to eat 10 candies mystic_tc must open it.
//
// 1)
// 10
// 7
// {3, 3, 3, 3, 3}
//
// Returns: 4
//
// Now there are many possibilities for the contents of boxes.
// For example, there could be three boxes with 3 candies each, one box with 1 candy, and one empty box.
// Another possibility is that there could be five boxes with 2 candies each.
// Note that in this case mystic_tc could open three boxes and still get only 6 candies, so he needs to open at least four boxes to be sure he gets at least 7 candies.
// And it can be proved that if mystic_tc opens any four of these boxes, they will always contain at least 7 candies in total.
//
// 2)
// 100
// 63
// {12, 34, 23, 45, 34}
//
// Returns: 3
//
// Open boxes 1, 3, 4 (0-based). It can be proved that these boxes contain at least 65 candies in total.
//
// 3)
// 19
// 12
// {12, 9, 15, 1, 6, 4, 9, 10, 10, 10, 14, 14, 1, 1, 12, 10, 9, 2, 3, 6, 1, 7, 3, 4, 10, 3, 14}
//
// Returns: 22
//
//
//
// 4)
// 326
// 109
// {9, 13, 6, 6, 6, 16, 16, 16, 10, 16, 4, 3, 10, 8, 11, 17, 12, 5, 7, 8, 7, 4, 15, 7, 14, 2, 2, 1, 17, 1, 7, 7, 12, 17, 2, 9, 7, 1, 8, 16, 7, 4, 16, 2, 13, 3, 13, 1, 17, 6}
//
// Returns: 15
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
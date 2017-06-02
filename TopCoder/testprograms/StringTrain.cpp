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

class StringTrain {
public:
	string buildTrain(vector <string> cars) {
		string ret;
		int i, tem, cur, j;
		ret = cars[0];
		for(i = 1; i < SZ(cars); i++)
        {
            for(j = 0; j < SZ(ret); j++)
            {
                string suf = ret.substr(j);
                tem = 0;
                for(k = 0; k < SZ(cars[i]) && tem < SZ(ret); k++)
                {
                    if(suf[tem] == cars[i][k])
                        tem++;
                    else
                        break;
                }
                if(k == SZ(cars[i]) || tem == SZ(ret) || tem == 0)
                    break;
                ret = ret.erase(0, tem) + cars[i];
            }
        }
        cout << SZ(ret) << endl;
        return "ok";
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	StringTrain *obj;
	string answer;
	obj = new StringTrain();
	clock_t startTime = clock();
	answer = obj->buildTrain(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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

	vector <string> p0;
	string p1;

	// ----- test 0 -----
	disabled = false;
	p0 = {"ABCDE","CDFFF","CDE","CDEGG","GABC"};
	p1 = "10 DEGABC";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = true;
	p0 = {"AAAAA","AAAAA","AAAAA"};
	p1 = "7 A";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = true;
	p0 = {"CABABDABAB","CABAB","ABABDABAB","DABAB"};
	p1 = "15 CDAB";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = true;
	p0 = {"ABABAB","ABABAB","ABABABAB","BZZZZZ"};
	p1 = "15 ABZ";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = true;
	p0 = {"A","A","A","AA"};
	p1 = "1 A";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
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
// You will be given a vector <string> cars containing a list of strings that will participate in the Train.
// The Train is a string that will be built using the given strings.  The building process works as follows:
//
// 	Train is initialized to the value of the 0th element of cars
// 	For each element of cars in order, beginning with element 1, check if some proper prefix of the current
//         element matches some proper suffix of the Train.  If so, append the element of cars to the Train, not repeating the matched 	prefix.  If more than one proper prefix matches, take the longest.  If no proper prefix matches, the current element of cars
//         is not appended.
//
// A prefix of a string is a substring that starts at the beginning of the string.  A proper prefix is a prefix that has
// positive length, and is not the entire string.  A suffix of a string is a substring that terminates at the end of the string.
// A proper suffix is a suffix that has positive length, and is not the entire string.
//
// Once you have built the Train, remove all but the last occurrence of each character in the Train.  For example, if the Train
// was (quotes for clarity) "abbbcabdb" you would be left with "cadb".  You will return a string of the form "n x" where, n is the length of the Train before removing all but the last occurrence of each character, and x is the string after the removal. n and x are separated by exactly one space, the return should not have any leading or trailing whitespace, and n should have no leading zeros.
//
// DEFINITION
// Class:StringTrain
// Method:buildTrain
// Parameters:vector <string>
// Returns:string
// Method signature:string buildTrain(vector <string> cars)
//
//
// CONSTRAINTS
// -cars will contain between 2 and 50 elements inclusive
// -Each element of cars will contain between 1 and 50 uppercase letters inclusive
//
//
// EXAMPLES
//
// 0)
// {"ABCDE","CDFFF","CDE","CDEGG","GABC"}
//
// Returns: "10 DEGABC"
//
// The Train begins as (quotes for clarity) "ABCDE".  Element 1 of cars cannot be added since it doesn't match any suffix of the Train.  Element 2 of cars cannot be added since the only matching prefix is the entire string.  Element 3 can be added, and the resulting Train is "ABCDEGG".  Element 4 can also be added, and the resulting Train is "ABCDEGGABC".  After removing all but the last occurrence of each character we are left with "DEGABC".
//
// 1)
// {"AAAAA","AAAAA","AAAAA"}
//
// Returns: "7 A"
//
// The Train begins as "AAAAA".  The longest matching proper prefix of element 1 of cars is "AAAA" so the resulting Train is "AAAAAA".  The longest matching proper prefix of element 1 of cars is "AAAA" so the resulting Train is "AAAAAAA".  After removing all but the last occurrence of each character, the result is "A".
//
// 2)
// {"CABABDABAB","CABAB","ABABDABAB","DABAB"}
//
// Returns: "15 CDAB"
//
// 3)
// {"ABABAB","ABABAB","ABABABAB","BZZZZZ"}
//
// Returns: "15 ABZ"
//
// 4)
// {"A","A","A","AA"}
//
// Returns: "1 A"
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
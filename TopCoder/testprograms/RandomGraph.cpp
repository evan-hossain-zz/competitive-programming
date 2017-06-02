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

double dp[51][51][2505];
int n;

class RandomGraph {
public:

    double call(int a, int b, int taken)
    {
        if(a == n || b == n)
            return 0;
    }

	double probability(int N, int p) {

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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	RandomGraph *obj;
	double answer;
	obj = new RandomGraph();
	clock_t startTime = clock();
	answer = obj->probability(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	double p2;

	// ----- test 0 -----
	disabled = false;
	p0 = 7;
	p1 = 0;
	p2 = 0.0;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = 3;
	p1 = 620;
	p2 = 0.0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = 4;
	p1 = 500;
	p2 = 0.59375;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = 8;
	p1 = 100;
	p2 = 0.33566851611343496;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = 15;
	p1 = 50;
	p2 = 0.5686761670525845;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 5 -----
	disabled = false;
	p0 = 50;
	p1 = 10;
	p2 = 0.7494276522159893;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 6 -----
	disabled = false;
	p0 = 50;
	p1 = 1000;
	p2 = 1.0;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, true, p2) ) && all_right;
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
// Consider a random undirected graph on n vertices.
// The vertices are numbered 0 through n-1.
// For each i and j such that 0 <= i < j <= n-1, the graph contains the edge i-j with probability p/1000.
// The probabilities that different edges are present in the graph are all mutually independent.
//
//
//
// You are given the ints n and p.
// Calculate and return the probability that the random graph generated using the above procedure contains at least one connected component with 4 or more vertices.
//
// DEFINITION
// Class:RandomGraph
// Method:probability
// Parameters:int, int
// Returns:double
// Method signature:double probability(int n, int p)
//
//
// NOTES
// -Your return value must have an absolute or relative error less than 1e-9.
// -A connected component is a maximal set S of vertices such that you can get from any vertex in S to any other vertex in S by following a sequence of edges. For example, if a graph with n=5 contains edges 0-2, 2-4, and 1-3, its connected components are {0,2,4} and {1,3}.
//
//
// CONSTRAINTS
// -n will be between 2 and 50, inclusive.
// -p will be between 0 and 1000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 7
// 0
//
// Returns: 0.0
//
// The probability of each edge is 0. Therefore, this graph will always have 7 isolated vertices = 7 connected components, each with just a single vertex.
//
// 1)
// 3
// 620
//
// Returns: 0.0
//
// This graph only has 3 vertices, so it is impossible to have a connected component with at least 4 vertices.
//
// 2)
// 4
// 500
//
// Returns: 0.59375
//
// There are 64 different graphs on 4 labeled vertices.
// As p=500, each of these 64 graphs is equally likely to be generated by our procedure.
// A graph on 4 vertices has a connected component with 4 or more vertices if and only if the entire graph is connected.
// Out of our 64 possible graphs, 38 are connected.
// Therefore, the probability we are looking for is 38/64.
//
// 3)
// 8
// 100
//
// Returns: 0.33566851611343496
//
// In this case, some of the good graphs have two connected components, each with 4 vertices.
//
// 4)
// 15
// 50
//
// Returns: 0.5686761670525845
//
//
//
// 5)
// 50
// 10
//
// Returns: 0.7494276522159893
//
//
//
// 6)
// 50
// 1000
//
// Returns: 1.0
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
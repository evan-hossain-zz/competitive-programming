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
#define infinity (20000000000000)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
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

struct point{LL x, y; point () {} point(LL a, LL b) {x = a, y = b;}};    // for coordinates;

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

#define MAX 500010
/*************************************************HABIJABI ENDS HERE******************************************************/


class MinimumSquareEasy {
public:
    /*
    -1000000000 0
    -500000000 0
    0 0
    0 500000000
    0 1000000000
    */

    point arr[55];
    LL rotation(const point &O, const point &A, const point &B) //checks rotation
    {
            LL rot = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
//            cout << "rot" << rot << endl;
            return rot;
    }

    bool on_segment(point p, point q, point r) // q point lies between p and r
    {
        if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
           return true;

        return false;
    }

    bool check(point a, point b, point c, point d, int n)
    {
        int cnt = 0, i, zero = 0;
        for(i = 0; i < n; i++)
        {
//            if((arr[i].x == a.x && arr[i].y == a.y) ||
//                (arr[i].x == b.x && arr[i].y == b.y) ||
//                (arr[i].x == c.x && arr[i].y == c.y) ||
//                (arr[i].x == d.x && arr[i].y == d.y)){
//                    continue;
//                }
            if(rotation(d, c, arr[i]) + rotation(c, b, arr[i]) + rotation(b, a, arr[i]) + rotation(a, d, arr[i]) == 0)
            {
                if(on_segment(d, arr[i], c))
                    zero++;
                if(on_segment(c, arr[i], b))
                    zero++;
                if(on_segment(b, arr[i], a))
                    zero++;
                if(on_segment(a, arr[i], d))
                    zero++;
                cnt++;
            }
        }
        cout << cnt << ' ' << ' ' << zero << endl;
        if(cnt - zero >= n - 2)
            return true;
        return false;
    }

	long long minArea(vector <int> x, vector <int> y) {
		LL low, high, mid, ret = infinity;
		int i, n = SZ(x);
		for(i = 0; i < n; i++)
        {
            arr[i].x = x[i];
            arr[i].y = y[i];
        }
        for(i = 0; i < n; i++)
        {
            point a, b, c, d;
            //for a
            low = 1, high = 20;
            while(low <= high)
            {
                mid = (low + high) / 2;
                a = d = b = c = arr[i];
                b.x += mid;
                c.x += mid;
                c.y -= mid;
                d.y -= mid;
                if(check(a, b, c, d, n))
                    high = mid - 1, ret = min(ret, mid);
                else
                    low = mid + 1;
            }
            cout << "ret" << ret << endl;
            //for b
            low = 1, high = 20;
            while(low <= high)
            {
                mid = (low + high) / 2;
                a = d = b = c = arr[i];
                a.x -= mid;
                c.y -= mid;
                d.x -= mid;
                d.y -= mid;
                if(check(a, b, c, d, n))
                    high = mid - 1, ret = min(ret, mid);
                else
                    low = mid + 1;
            }
            //for c
            low = 1, high = 20;
            while(low <= high)
            {
                mid = (low + high) / 2;
                a = d = b = c = arr[i];
                a.x -= mid;
                a.y += mid;
                b.y += mid;
                d.x -= mid;
                if(check(a, b, c, d, n))
                    high = mid - 1, ret = min(ret, mid);
                else
                    low = mid + 1;
            }
            //for d
            low = 1, high = 20;
            while(low <= high)
            {
                mid = (low + high) / 2;
                a = d = b = c = arr[i];
                b.x += mid;
                b.y += mid;
                c.x += mid;
                a.y += mid;
                if(check(a, b, c, d, n))
                    high = mid - 1, ret = min(ret, mid);
                else
                    low = mid + 1;
            }
        }
        return ret * ret;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, long long p2) {
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
	cout << "}";
	cout << "]" << endl;
	MinimumSquareEasy *obj;
	long long answer;
	obj = new MinimumSquareEasy();
	clock_t startTime = clock();
	answer = obj->minArea(p0, p1);
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
		res = answer == p2;
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
	long long p2;

	// ----- test 0 -----
	disabled = false;
	p0 = {0,1,2};
	p1 = {0,1,5};
	p2 = 4ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = true;
	p0 = {-1,-1,0,2,0};
	p1 = {-2,-1,0,-1,-2};
	p2 = 9ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = true;
	p0 = {1000000000,-1000000000,1000000000,-1000000000};
	p1 = {1000000000,1000000000,-1000000000,-1000000000};
	p2 = 4000000008000000004ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = true;
	p0 = {93,34,12,-11,-7,-21,51,-22,59,74,-19,29,-56,-95,-96,9,44,-37,-54,-21};
	p1 = {64,12,-43,20,55,74,-20,-54,24,20,-18,77,86,22,47,-24,-33,-57,5,7};
	p2 = 22801ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
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
// There are N points in the plane. You are given their description as two vector <int>s, x and y, with N elements each. The N points have coordinates (x[0],y[0]), (x[1],y[1]), ..., (x[N-1],y[N-1]).
//
// You want to draw a single square onto the plane. The vertices of the square must have integer coordinates, and the sides of the square must be parallel to the coordinate axes. Additionally, at least N-2 of the N given points must lie strictly inside the square (i.e., not on its boundary).
//
// Return the smallest possible area of a square that satisfies these constraints.
//
// DEFINITION
// Class:MinimumSquareEasy
// Method:minArea
// Parameters:vector <int>, vector <int>
// Returns:long long
// Method signature:long long minArea(vector <int> x, vector <int> y)
//
//
// CONSTRAINTS
// -x will contain between 3 and 50 elements, inclusive.
// -y will contain the same number of elements as x.
// -All points will be pairwise distinct.
// -Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
// -Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// {0, 1, 2}
// {0, 1, 5}
//
// Returns: 4
//
// The square must contain at least one of the three given points. One of the optimal solutions is the square with opposite corners at (-1,-1) and (1,1).
//
// 1)
// {-1, -1, 0, 2, 0}
// {-2, -1, 0, -1, -2}
//
// Returns: 9
//
// This time the square must contain at least three of the five given points. The optimal solution is the square with opposite corners at (-2,-3) and (1,0).
//
// 2)
// {1000000000, -1000000000, 1000000000, -1000000000}
// {1000000000, 1000000000, -1000000000, -1000000000}
//
// Returns: 4000000008000000004
//
// In this case one of the optimal solutions is a square that contains all four points.
//
// 3)
// {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21}
// {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7}
//
// Returns: 22801
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!

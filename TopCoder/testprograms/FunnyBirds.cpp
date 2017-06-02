#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010
#define VI vector <int>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};
///int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
template <class T> T GCD(T a, T b) {if(b == 0) return a; return GCD(b, a % b);}
template <class T> T LCM(T a, T b) {return (a * b) / GCD(a, b);}

using namespace std;


class FunnyBirds {
public:
	int gameTime(int n) {
		int tot = n, cnt = 0;
		while(tot > 0)
        {
            for(int i = 1; i <= tot; i++)
                tot -= i, cnt++;
        }
        return cnt;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	FunnyBirds *obj;
	int answer;
	obj = new FunnyBirds();
	clock_t startTime = clock();
	answer = obj->gameTime(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	all_right = true;

	int p0;
	int p1;

	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 3;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 14;
	p1 = 7;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 100;
	p1 = 18;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
//
// n birds on a tree want to learn natural numbers.
// They start singing all natural numbers in the increasing order starting from 1. When a number K is sung, K birds fly away from the tree. If, at any second, the number of birds on the tree is strictly less than the number which must be sung, the birds restart the game and start singing the numbers from 1 again.
//
//
// You are given an int n � the number of birds on the tree. Taking into account that singing a number takes exactly one second, return the total time elapsed before all birds fly away.
//
//
//
// DEFINITION
// Class:FunnyBirds
// Method:gameTime
// Parameters:int
// Returns:int
// Method signature:int gameTime(int n)
//
//
// CONSTRAINTS
// -n will be between 1 and 10^9, inclusive.
//
//
// EXAMPLES
//
// 0)
// 1
//
// Returns: 1
//
// There is just one bird who flies at the first second.
//
// 1)
// 3
//
// Returns: 2
//
// One bird flies away at the first second, the other two at the next one.
//
// 2)
// 4
//
// Returns: 3
//
// At second 1, birds sing "one" and one of four birds flies away (with 3 birds remaining on the tree). At second 2, birds sing "two" and two of three birds fly away. At the third, the birds restart the game from 1 and the last bird flies away.
//
// 3)
// 14
//
// Returns: 7
//
// During the first four seconds the birds will count from 1 to 4, so (1 + 2 + 3 + 4) = 10 birds will fly away, with 4 birds left on the tree. The game will be restarted from 1, so 1 and 2 birds will fly away on seconds 5 and 6 respectively. On second 7, the birds will restart the game again and the only remaining bird will fly away.
//
// 4)
// 100
//
// Returns: 18
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
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
#define all(v) v.begin(), v.end()

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};
///int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
template <class T> T GCD(T a, T b) {if(b == 0) return a; return GCD(b, a % b);}
template <class T> T LCM(T a, T b) {return (a * b) / GCD(a, b);}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostr(T n) {stringstream ss; ss << n; return ss.str();}


class CompilingDecksWithJokers {
public:
	int maxCompleteDecks(vector <int> cards, int jokers) {
	_
		
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	CompilingDecksWithJokers *obj;
	int answer;
	obj = new CompilingDecksWithJokers();
	clock_t startTime = clock();
	answer = obj->maxCompleteDecks(p0, p1);
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
	all_right = true;
	
	vector <int> p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {10,15};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 13;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	p2 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	p2 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {2,3,4,5,6};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	p2 = 4;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
// You are given a vector <int> cards, the i-th element of which is the number of cards you have of type i, and an int jokers, the number of jokers you have. You want to construct decks using these cards. There are two types of valid decks:
// 
// 
// A deck containing exactly 1 card of each type, and no jokers.
// A deck containing exactly 1 card of each type except one, and exactly 1 joker.
// 
// 
// For example, if there are 3 types of cards, the following four decks would be valid: {1, 2, 3}, {J, 2, 3}, {1, J, 3}, {1, 2, J}.  Return the maximum possible number of valid decks you can construct with the given cards.  Each card can only be a member of a single deck.
// 
// 
// 
// DEFINITION
// Class:CompilingDecksWithJokers
// Method:maxCompleteDecks
// Parameters:vector <int>, int
// Returns:int
// Method signature:int maxCompleteDecks(vector <int> cards, int jokers)
// 
// 
// NOTES
// -The total number of types of cards is equal to the total number of elements in cards.
// 
// 
// CONSTRAINTS
// -cards will contain between 1 and 50 elements, inclusive.
// -Each element of cards will be between 0 and 500,000,000, inclusive.
// -jokers will be between 0 and 500,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {10, 15}
// 3
// 
// Returns: 13
// 
// 10 full decks without jokers and 3 decks with jokers instead of cards of the first type can be compiled.
// 
// 1)
// {1, 2, 3}
// 4
// 
// Returns: 3
// 
// Three decks with one joker each can be compiled: one with the card of the second type changed to joker and two with the card of the first type replaced by joker.
// 
// 2)
// {1}
// 5
// 
// Returns: 6
// 
// Note that a deck can be composed of 1 sole joker if there is only 1 type of card.
// 
// 3)
// {2, 3, 4, 5, 6}
// 4
// 
// Returns: 4
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

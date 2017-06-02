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

#define MAX 500010
/*************************************************HABIJABI ENDS HERE******************************************************/


class TrainingCamp {
public:
	vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics) {
		vector <string> ans;
		string s;
        for(int student = 0; student < SZ(attendance); student++)
        {
            s = "";
            cout << "ic";
            for(int i = 0; i < SZ(problemTopics); i++)
            {
                bool flag = true;
                for(int j = 0; j < SZ(problemTopics[i]); j++)
                {
                    cout << j << endl;
                    if(problemTopics[i][j] == 'X' && attendance[student][j] == '-')
                        flag = false;
                }
                if(flag)
                    s += 'X';
                else
                    s += '-';
            }
            cout << s << endl;
            ans.pb(s);
        }
        return ans;
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, vector <string> p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	TrainingCamp *obj;
	vector <string> answer;
	obj = new TrainingCamp();
	clock_t startTime = clock();
	answer = obj->determineSolvers(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p2[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
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
	
	vector <string> p0;
	vector <string> p1;
	vector <string> p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"XXX","XXX","XX-"};
	p1 = {"---","XXX","-XX","XX-"};
	p2 = {"XXXX","XXXX","X--X"};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"-XXXX","----X","XXX--","X-X-X"};
	p1 = {"X---X","-X---","XXX--","--X--"};
	p2 = {"-X-X","----","-XXX","X--X"};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"-----","XXXXX"};
	p1 = {"XXXXX","-----","--X-X"};
	p2 = {"-X-","XXX"};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"-","X","X","-","X"};
	p1 = {"-","X"};
	p2 = {"X-","XX","XX","X-","XX"};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"X----X--X","X--X-X---","--X-X----","XXXX-X-X-","XXXX--XXX"};
	p1 = {"X----X-X-","-----X---","-X----X-X","-X-X-X---","-----X---","X-------X"};
	p2 = {"-X--XX","-X--X-","------","XX-XX-","--X--X"};
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
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
// Manao conducted a training camp in Bazaleti to prepare students for programming contests. The camp lasted for M days and was attended by N students. Each day, a lecture on a separate topic was delivered. Some of the students did not attend on particular days. You are given a vector <string> attendance containing N elements, each of them M characters long. The j-th character in the i-th element of attendance is 'X' if the i-th student attended on the j-th day and '-' otherwise.
// 
// Now Manao is going to arrange a contest comprised of K problems. Some problems are ad hoc and require no special knowledge, some need a specific topic which was analyzed at the camp and some combine several topics from the camp. This information is given in vector <string> problemTopics, which contains K elements of length M. 
// The j-th character in the i-th element of problemTopics is 'X' if problem i requires knowledge of the topic that was taught on the j-th day of the camp and '-' otherwise.
// 
// Manao wants an estimate on which students should solve which of the problems. He reckons that a student should solve a problem if he attended on each of the days when the topics needed for the problem were analyzed. Return a vector <string> containing N elements containing K characters each. The j-th character in the i-th row should be 'X' if student i should solve problem j by Manao's estimate and '-' otherwise.
// 
// DEFINITION
// Class:TrainingCamp
// Method:determineSolvers
// Parameters:vector <string>, vector <string>
// Returns:vector <string>
// Method signature:vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics)
// 
// 
// CONSTRAINTS
// -attendance will contain between 1 and 50 elements, inclusive.
// -Each element of attendance will contain between 1 and 50 characters, inclusive.
// -All elements of attendance will be of the same length.
// -Each character in attendance will be either '-' or 'X'.
// -problemTopics will contain between 1 and 50 elements, inclusive.
// -Each element of problemTopics will contain the same number of characters as attendance[0].
// -Each character in problemTopics will be either '-' or 'X'.
// 
// 
// EXAMPLES
// 
// 0)
// {"XXX",
//  "XXX",
//  "XX-"}
// {"---",
//  "XXX",
//  "-XX",
//  "XX-"}
// 
// Returns: {"XXXX", "XXXX", "X--X" }
// 
// The camp lasted for three days and had three attendees. The first two of them have listened to all the lectures and the third one missed the camp's last day. Of the four problems Manao is going to set for the contest, problem 0 requires no special knowledge, problem 1 combines all three topics taught at the camp and the other two problems are a blend of two of those techniques. Students 0 and 1 should be able to solve all problems, while student 2 is estimated to fail problems 1 and 2 because they both need the topic considered on the last day of the camp.
// 
// 1)
// {"-XXXX",
//  "----X",
//  "XXX--",
//  "X-X-X"}
// {"X---X",
//  "-X---",
//  "XXX--",
//  "--X--"}
// 
// Returns: {"-X-X", "----", "-XXX", "X--X" }
// 
// The camp comprised five days and was attended by four students. Student 0 should solve problems 1 and 3, student 1 is expected to solve nothing, student 2 should solve all problems but the first one and student 3 should solve problems 0 and 3.
// 
// 2)
// {"-----",
//  "XXXXX"}
// {"XXXXX",
//  "-----",
//  "--X-X"}
// 
// Returns: {"-X-", "XXX" }
// 
// Student 0 attended no lectures, but he should still be able to solve problem 1.
// 
// 3)
// {"-",
//  "X",
//  "X",
//  "-",
//  "X"}
// {"-",
//  "X"}
// 
// Returns: {"X-", "XX", "XX", "X-", "XX" }
// 
// 
// 
// 4)
// {"X----X--X",
//  "X--X-X---",
//  "--X-X----",
//  "XXXX-X-X-",
//  "XXXX--XXX"}
// {"X----X-X-",
//  "-----X---",
//  "-X----X-X",
//  "-X-X-X---",
//  "-----X---",
//  "X-------X"}
// 
// Returns: {"-X--XX", "-X--X-", "------", "XX-XX-", "--X--X" }
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
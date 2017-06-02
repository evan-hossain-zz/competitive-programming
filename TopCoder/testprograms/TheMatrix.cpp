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
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};
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

class TheMatrix {
public:
    vector <string> grid;
    int n, m, color[110][110];

    void bfs(int r, int c)
    {
        queue <int> q;
        q.push(r);
        q.push(c);
        color[r][c] = 1;
        int nr, nc, i;
        while(!q.empty())
        {
            r = q.front();
            q.pop();
            c = q.front();
            q.pop();
            for(i = 0; i < 4; i++)
            {
                nr = r + row[i];
                nc = c + col[i];
                if(nr >= n || nr < 1 || nc >= m || nc < 1 || color[nr][nc])
                    continue;
                if(grid[nr][nc] == grid[r][c])
                {
                    color[nr][nc] = 2;
                    continue;
                }
                color[nr][nc] = 1;
                q.push(nr);
                q.push(nc);
            }
        }
    }
    int max_sum()
    {
        int i, j, res, ret = 0;
        for(i = 1; i < n; i++)
            {
                for(j = 1; j < m; j++)
                    {
                        arr[i][j] += arr[i - 1][j];
                    }
            }
        for(i = 1; i < n; i++)
            {
                for(j = 1; j < m; j++)
                    {
                        arr[i][j] += arr[i][j - 1];
                    }
            }
        for(int r1 = 1; r1 < n; r1++)
            {
                for(int r2 = r1; r2 < n; r2++)
                    {
                        for(int c1 = 1; c1 < m; c1++)
                            {
                                for(int c2 = c1; c2 < m; c2++)
                                    {
                                        res = arr[r2][c2] - arr[r1 - 1][c2] - arr[r2][c1 - 1] + arr[r1 -1][c1 - 1];
                                        if(res == ((c2 - c1 + 1) * (r2 - r1 + 1)))
                                            ret = max(res, ret);
                                    }
                            }
                    }
            }
        return ret;
    }

    int arr[110][110];

	int MaxArea(vector <string> board) {
	    grid.resize(SZ(board) + 1);
	    for(int i = 0; i < SZ(board); i++)
            grid[i + 1] = "#" + board[i];
        n = SZ(grid);
        m = SZ(grid[1]);
        clr(color, 0);
        int i, j;
        for(i = 1; i < n; i++)
            for(j = 1; j < m; j++)
                if(!color[i][j])
                    bfs(i, j);
        for(i = 1; i < n; i++)
            for(j = 1; j < m; j++)
                arr[i][j] = (color[i][j] == 1);
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
                cout << arr[i][j] << ' ';
            cout << endl;
        }
        return max_sum();
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	TheMatrix *obj;
	int answer;
	obj = new TheMatrix();
	clock_t startTime = clock();
	answer = obj->MaxArea(p0);
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
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;

	vector <string> p0;
	int p1;

	// ----- test 0 -----
	disabled = true;
	p0 = {"1","0"};
	p1 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = true;
	p0 = {"0000"};
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = true;
	p0 = {"01"};
	p1 = 2;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = true;
	p0 = {"001","000","100"};
	p1 = 2;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = true;
	p0 = {"0"};
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 5 -----
	disabled = true;
	p0 = {"101","010"};
	p1 = 6;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 6 -----
	disabled = true;
	p0 = {"101","011","101","010"};
	p1 = 8;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 7 -----
	disabled = false;
	p0 = {"11001110011000110001111001001110110011010110001011","10100100010111111011111001011110101111010011100001","11101111001110100110010101101100011100101000010001","01000010001010101100010011111000100100110111111000","10110100000101100000111000100001011101111101010010","00111010000011100001110110010011010110010011100100","01100001111101001101001101100001111000111001101010","11010000000011011010100010000000111011001001100101","10100000000100010100100011010100110110110001000001","01101010101100001100000110100110100000010100100010","11010000001110111111011010011110001101100011100010","11101111000000011010011100100001100011111111110111","11000001101100100011000110111010011001010100000001","00100001111001010000101101100010000001100100001000","01001110110111101011010000111111101011000110010111","01001010000111111001100000100010101100100101010100","11111101001101110011011011011000111001101100011011","10000100110111000001110110010000000000111100101101","0101001110110110111000001100011001111100111101"
			"1100","01101010011111010000011001111101011010011100001101","11011000011000110010101111100000101011011111101100","11100001001000110010100011001010101101001010001100","11011011001100111101001100111100000101011101101011","11110111100100101011100101111101000111001111110111","00011001100110111100111100001100101001111100001111","10001111100101110111001111100000000011110000100111","10101010110110100110010001001010000111100110100011","01100110100000001110101001101011001010001101110101","10110101110100110110101001100111110000101111100110","01011000001001101110100001101001110011001001110001","00100101010001100110110101001010010100001011000011","00011101100100001010100000000011000010100110011100","11001001011000000101111111000000110010001101101110","10101010110110010000010011001100110101110100111011","01101001010111010001101000100011101001110101000110","00110101101110110001110101110010100100110000101101","11010101000111010011110011000001101111010011110011","1001000001000111001101110100111011001000"
			"1100011100","00111101110001001100101001110100110010100110110000","00010011011000101000100001101110111100100000010100","01101110001101000001001000001011101010011101011110","00000100110011001011101011110011011101100001110111","00110011110000011001011100001110101010100110010110","00111001010011011111010100000100100000101101110001","10101101101110111110000011111011001011100011110001","00101110010101111000001010110100001110111011100011","01111110010100111010110001111000111101110100111011"};
	p1 = 12;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, true, p1) ) && all_right;
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
// Have you ever had a dream, that you were so sure was real? What if you were unable to wake from that dream? How would you know the difference between the dream world and the real world?
//
// To answer this complex puzzle, one of the questions that must be answered is to find out whether the world that you live in can be represented by a chess matrix.
//
// Cells of a matrix are called adjacent if they share an edge.
// A matrix of zeroes and ones is called a chess matrix if there are no two adjacent cells that share the same value.
// Hence, in a chess matrix the zeroes and ones have to alternate in the same way the colors alternate on a chessboard:
//
//
//
// You are given a vector <string> board that represents a rectangular grid of cells, with a 0 or a 1 in each cell.
// Each character of each element of board will be either '0' or '1'.
// In this grid we selected some rectangular subgrid that is a chess matrix.
// Return the largest possible area of the selected subgrid.
//
// DEFINITION
// Class:TheMatrix
// Method:MaxArea
// Parameters:vector <string>
// Returns:int
// Method signature:int MaxArea(vector <string> board)
//
//
// CONSTRAINTS
// -board will contain between 1 and 100 elements, inclusive.
// -Each element of the board is a string containing between 1 and 100 characters, inclusive.
// -All elements of board will have the same length.
// -Each character of each element of board will be either '0' or '1'.
//
//
// EXAMPLES
//
// 0)
// {"1",
//  "0"}
//
// Returns: 2
//
// The entire board is a chess matrix.
//
// 1)
// {"0000"}
//
// Returns: 1
//
// The largest possible chess matrix here is just a single cell.
//
// 2)
// {"01"}
//
// Returns: 2
//
// Again, the entire board is a chess matrix.
//
// 3)
// {"001",
//  "000",
//  "100"}
//
// Returns: 2
//
// Each rectangular subgrid is determined by a contiguous range of rows and a contiguous range of columns. The four corners of this grid do not form a valid rectangular subgrid.
//
// 4)
// {"0"}
//
// Returns: 1
//
//
//
// 5)
// {"101",
//  "010"}
//
// Returns: 6
//
//
//
// 6)
// {"101",
//  "011",
//  "101",
//  "010"}
//
// Returns: 8
//
//
//
// 7)
// {"11001110011000110001111001001110110011010110001011",
//  "10100100010111111011111001011110101111010011100001",
//  "11101111001110100110010101101100011100101000010001",
//  "01000010001010101100010011111000100100110111111000",
//  "10110100000101100000111000100001011101111101010010",
//  "00111010000011100001110110010011010110010011100100",
//  "01100001111101001101001101100001111000111001101010",
//  "11010000000011011010100010000000111011001001100101",
//  "10100000000100010100100011010100110110110001000001",
//  "01101010101100001100000110100110100000010100100010",
//  "11010000001110111111011010011110001101100011100010",
//  "11101111000000011010011100100001100011111111110111",
//  "11000001101100100011000110111010011001010100000001",
//  "00100001111001010000101101100010000001100100001000",
//  "01001110110111101011010000111111101011000110010111",
//  "01001010000111111001100000100010101100100101010100",
//  "11111101001101110011011011011000111001101100011011",
//  "10000100110111000001110110010000000000111100101101",
//  "01010011101101101110000011000110011111001111011100",
//  "01101010011111010000011001111101011010011100001101",
//  "11011000011000110010101111100000101011011111101100",
//  "11100001001000110010100011001010101101001010001100",
//  "11011011001100111101001100111100000101011101101011",
//  "11110111100100101011100101111101000111001111110111",
//  "00011001100110111100111100001100101001111100001111",
//  "10001111100101110111001111100000000011110000100111",
//  "10101010110110100110010001001010000111100110100011",
//  "01100110100000001110101001101011001010001101110101",
//  "10110101110100110110101001100111110000101111100110",
//  "01011000001001101110100001101001110011001001110001",
//  "00100101010001100110110101001010010100001011000011",
//  "00011101100100001010100000000011000010100110011100",
//  "11001001011000000101111111000000110010001101101110",
//  "10101010110110010000010011001100110101110100111011",
//  "01101001010111010001101000100011101001110101000110",
//  "00110101101110110001110101110010100100110000101101",
//  "11010101000111010011110011000001101111010011110011",
//  "10010000010001110011011101001110110010001100011100",
//  "00111101110001001100101001110100110010100110110000",
//  "00010011011000101000100001101110111100100000010100",
//  "01101110001101000001001000001011101010011101011110",
//  "00000100110011001011101011110011011101100001110111",
//  "00110011110000011001011100001110101010100110010110",
//  "00111001010011011111010100000100100000101101110001",
//  "10101101101110111110000011111011001011100011110001",
//  "00101110010101111000001010110100001110111011100011",
//  "01111110010100111010110001111000111101110100111011"}
//
// Returns: 12
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!

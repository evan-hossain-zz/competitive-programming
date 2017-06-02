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
#include <assert.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
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

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;
//
//template <class T> T sqr(T a){return a * a;}    // square
//template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
//template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
//template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
//template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
//template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
//template <class T> void show(T a){cout << a << endl;}
//template <class T> void show(T a, T b){cout << a << ' ' << b << endl;}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

class TaroCutting {
public:

#define INF 2000000000
#define rows 160
#define clms 160
int arr[rows][clms]; //main matrix
int  u[rows], v[clms]; //used for labeling
int p[clms] , way[clms]; //p = match , way = the augmenting path

//n = number of rows
//m = number of columns
//n<=m
int hungarian(int n,int m) {

    clr(p,0);
    clr(u,0);
    clr(v,0);
    for ( int i = 1 ; i <= n ; ++ i ) {
        p [ 0 ] = i ;
        int j0 = 0 ;
        vector < int > minv ( m + 1 , INF ) ;
        vector < bool > used ( m + 1 , false ) ;
        do { //works like bfs
            used [ j0 ] = true ;
            int i0 = p [ j0 ] ,  delta = INF,  j1 ;
            for ( int j = 1 ; j <= m ; ++ j )
                if ( ! used [ j ] ) {
                    int cur = arr [ i0 ] [ j ] - u [ i0 ] - v [ j ] ;
				if ( cur < minv [ j ] )
					minv [ j ] = cur,  way [ j ] = j0 ;
				if ( minv [ j ] < delta )
					delta = minv [ j ] ,  j1 = j ;
                }
            //matrix doesn't change here
            for ( int j = 0 ; j <= m ; ++ j )
                if ( used [ j ] )
                    u [ p [ j ] ] += delta,  v [ j ] -= delta ;
                else
                    minv [ j ] -= delta ;
            j0 = j1 ;
            } while ( p [ j0 ] != 0 ) ;
        do {
                int j1 = way [ j0 ] ;
                p [ j0 ] = p [ j1 ] ;
                j0 = j1 ;
            } while ( j0 ) ;

    }

    return -v[0]; //minimum cost is stored here
}

	int getNumber(vector <int> height, vector <int> add, vector <int> device, int time) {
		int i, res = 0, j, k, h;
		for(i = 0; i < time; i++)
        {
            if(SZ(device) < SZ(height))
            {
                for(j = 0; j < SZ(height); j++)
                {
                    height[j] += add[j];
                    for(k = 0; k < SZ(device); k++)
                    {
                        arr[k+1][j+1] = min(0, device[k] - height[j]);
                    }
                }
                h = hungarian(SZ(device), SZ(height));
                cout << h << endl;
                for(j = 0; j < SZ(height); j++)
                {
                    if(p[j+1] == 0) continue;
                    height[j] = height[j] > device[p[j+1]-1]? device[p[j+1]-1] : height[j];
                }
            }
            else
            {
                for(j = 0; j < SZ(height); j++)
                {
                    height[j] += add[j];
                    for(k = 0; k < SZ(device); k++)
                    {
                        arr[j+1][k+1] = min(0, device[k] - height[j]);
                    }
                }
                h = hungarian(SZ(height), SZ(device));
                cout << h << endl;
                for(j = 0; j < SZ(device); j++)
                {
                    if(p[j+1] == 0) continue;
                    height[p[j+1]-1] = height[p[j+1]-1] > device[j] ? device[j] : height[p[j+1]-1];
                }
            }
        }
        int ret = 0;
        for(i = 0; i < SZ(height); i++)
            ret += height[i];
        return ret;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, int p3, bool hasAnswer, int p4) {
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
	cout << "}" << "," << p3;
	cout << "]" << endl;
	TaroCutting *obj;
	int answer;
	obj = new TaroCutting();
	clock_t startTime = clock();
	answer = obj->getNumber(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	int p4;

	// ----- test 0 -----
	disabled = false;
	p0 = {4,7};
	p1 = {7,1};
	p2 = {7};
	p3 = 1;
	p4 = 15;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {3,1,2};
	p1 = {1,1,1};
	p2 = {7,7,7};
	p3 = 2;
	p4 = 12;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {100,50};
	p1 = {75,30};
	p2 = {200,100,50};
	p3 = 2;
	p4 = 130;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {7,10,1,7,5,4,11,5,7,9,10,8};
	p1 = {1,3,4,10,2,1,6,4,8,7,5,10};
	p2 = {7,1,5,10};
	p3 = 3;
	p4 = 96;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = {35,45,32,8};
	p1 = {2,25,31,5};
	p2 = {29,28,3,11,28,37};
	p3 = 8;
	p4 = 29;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 5 -----
	disabled = false;
	p0 = {614,649,977,808,821,356,801,493,669,650,652,627,129,261,883,513,62,698,83,772,779,719,83,105,774,867,412,892,142,851,743,66,221,494,125,905,638,342,723,680,407,197,111,368,676,694,765,482,712,188,325,535,6,49,655,595,958,805,659,893,370,904,276,156,29,458,757,632,731,289,582,207,843,365,387,521,69,269,459,428,423,885,744,199,998,968,296,473,50,752,492,919,473,981,380,896,769,991,269,93,108,184,762,312,511,256,374,600,643,445,908,250,384,518,119,464,499,124,82,999,881,767,177,796,2,620,759,380,901,221,407,622,260,622,729,264,768,79,236,524,437,215,108,518,820,725,490,796,986,318};
	p1 = {391,938,772,630,54,775,379,613,647,8,946,885,604,822,663,559,452,565,637,695,24,515,92,956,194,551,813,362,190,268,440,781,450,789,566,372,402,860,531,608,434,761,754,26,504,873,132,756,206,93,284,807,642,637,936,954,205,303,582,822,134,269,967,147,589,549,24,670,403,105,40,531,486,695,898,287,443,542,599,151,45,567,548,945,912,764,451,404,700,522,227,954,84,347,625,278,377,730,635,604,959,845,41,193,459,532,429,216,473,415,85,933,90,643,94,927,692,99,771,594,318,627,89,340,110,488,909,253,20,114,179,177,116,42,676,91,787,437,551,51,880,336,759,795,243,727,279,620,488,607};
	p2 = {942,79,387,184,104,981,766,678,715,998,161,125,439,532,550,415,4,467,211,852,781,577,728,592,40,971,852,592,338,555,662,636,823,122,728,69,701,476,346,190,36,535,826,739,517,551,257,36,906,171,629,292,49,29,109,151,299,180,193,731,655,877,174,688,866,957,57,89,513,765,68,245,454,968,224,417,657,383,769,809,13,51,813,970,632,357,787,717,254,645,352,636,370,950,917,959,364,453,890,43,98,438,748,277,115,298,431,709,312,49,553,395,798,58,419,355,770,818,460,89,880,515,952,219,608,284,532,254,361,524,199,265,407,782,737,928,977,729,510,175,609,81,155,24,425,186,999,839,896,721};
	p3 = 150;
	p4 = 43325;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) ) && all_right;
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
//
// Cat Taro has some trees in his garden.
// Initially, the i-th tree (0-based index) is height[i] meters tall.
// Each day the trees grow.
// For each i, the i-th tree will grow by exactly add[i] meters during each day.
//
//
//
//
// Taro wants cut the trees and he has some devices to do that.
// For each valid i, the i-th device (0-based index) will cut any chosen tree with height greater than device[i] meters to exactly device[i] meters.
//
//
//
//
// At the end of each day, Taro can choose any (possibly empty) subset of trees and cut them.
// There are two restrictions:
//
// Each tree can be cut at most once per day.
// Each device can be used at most once per day.
//
//
//
//
//
// You are given the vector <int>s height, add and device, and an int time.
// Return the smallest possible sum of the heights of the trees after time days (i.e., time iterations of "the trees grow and then Taro cuts some of them").
//
//
// DEFINITION
// Class:TaroCutting
// Method:getNumber
// Parameters:vector <int>, vector <int>, vector <int>, int
// Returns:int
// Method signature:int getNumber(vector <int> height, vector <int> add, vector <int> device, int time)
//
//
// CONSTRAINTS
// -height will contain between 1 and 150 elements, inclusive.
// -height and add will contain the same number of elements.
// -device will contain between 1 and 150 elements, inclusive.
// -Each element of height, add and device will be between 0 and 10,000, inclusive.
// -time will be between 1 and 150, inclusive.
//
//
// EXAMPLES
//
// 0)
// {4, 7}
// {7, 1}
// {7}
// 1
//
// Returns: 15
//
// There are two trees.
// Tree 0 starts 4 meters tall and grows by 7 meters each day.
// Tree 1 starts 7 meters tall and grows by 1 meter each day.
// Thus, during the first day the first tree will grow to 4+7 = 11 meters and the second tree will grow to 7+1 = 8 meters.
// Taro has a single tree-cutting device that cuts a tree to 7 meters.
// As both trees now have more than 7 meters, he can use it on either of them.
// In order to minimize the sum of heights of trees, it is better to cut the taller tree: tree 0.
// After the cutting, the total height of trees will be 7+8 = 15 meters.
//
// 1)
// {3, 1, 2}
// {1, 1, 1}
// {7, 7, 7}
// 2
//
// Returns: 12
//
// After two days the trees' heights will be 5, 3, and 4.
// The trees are still too short so Taro is unable to cut anything.
//
// 2)
// {100, 50}
// {75, 30}
// {200, 100, 50}
// 2
//
// Returns: 130
//
//
//
// 3)
// {7, 10, 1, 7, 5, 4, 11, 5, 7, 9, 10, 8}
// {1, 3, 4, 10, 2, 1, 6, 4, 8, 7, 5, 10}
// {7, 1, 5, 10}
// 3
//
// Returns: 96
//
//
//
// 4)
// {35, 45, 32, 8}
// {2, 25, 31, 5}
// {29, 28, 3, 11, 28, 37}
// 8
//
// Returns: 29
//
//
//
// 5)
// {614, 649, 977, 808, 821, 356, 801, 493, 669, 650, 652, 627, 129, 261, 883, 513, 62, 698, 83, 772,
// 779, 719, 83, 105, 774, 867, 412, 892, 142, 851, 743, 66, 221, 494, 125, 905, 638, 342, 723, 680,
// 407, 197, 111, 368, 676, 694, 765, 482, 712, 188, 325, 535, 6, 49, 655, 595, 958, 805, 659, 893,
// 370, 904, 276, 156, 29, 458, 757, 632, 731, 289, 582, 207, 843, 365, 387, 521, 69, 269, 459, 428,
// 423, 885, 744, 199, 998, 968, 296, 473, 50, 752, 492, 919, 473, 981, 380, 896, 769, 991, 269, 93,
// 108, 184, 762, 312, 511, 256, 374, 600, 643, 445, 908, 250, 384, 518, 119, 464, 499, 124, 82, 999,
// 881, 767, 177, 796, 2, 620, 759, 380, 901, 221, 407, 622, 260, 622, 729, 264, 768, 79, 236, 524,
// 437, 215, 108, 518, 820, 725, 490, 796, 986, 318}
// {391, 938, 772, 630, 54, 775, 379, 613, 647, 8, 946, 885, 604, 822, 663, 559, 452, 565, 637, 695, 24,
// 515, 92, 956, 194, 551, 813, 362, 190, 268, 440, 781, 450, 789, 566, 372, 402, 860, 531, 608, 434,
// 761, 754, 26, 504, 873, 132, 756, 206, 93, 284, 807, 642, 637, 936, 954, 205, 303, 582, 822, 134,
// 269, 967, 147, 589, 549, 24, 670, 403, 105, 40, 531, 486, 695, 898, 287, 443, 542, 599, 151, 45,
// 567, 548, 945, 912, 764, 451, 404, 700, 522, 227, 954, 84, 347, 625, 278, 377, 730, 635, 604, 959,
// 845, 41, 193, 459, 532, 429, 216, 473, 415, 85, 933, 90, 643, 94, 927, 692, 99, 771, 594, 318, 627,
// 89, 340, 110, 488, 909, 253, 20, 114, 179, 177, 116, 42, 676, 91, 787, 437, 551, 51, 880, 336, 759,
// 795, 243, 727, 279, 620, 488, 607}
// {942, 79, 387, 184, 104, 981, 766, 678, 715, 998, 161, 125, 439, 532, 550, 415, 4, 467, 211, 852, 781,
// 577, 728, 592, 40, 971, 852, 592, 338, 555, 662, 636, 823, 122, 728, 69, 701, 476, 346, 190, 36,
// 535, 826, 739, 517, 551, 257, 36, 906, 171, 629, 292, 49, 29, 109, 151, 299, 180, 193, 731, 655,
// 877, 174, 688, 866, 957, 57, 89, 513, 765, 68, 245, 454, 968, 224, 417, 657, 383, 769, 809, 13, 51,
// 813, 970, 632, 357, 787, 717, 254, 645, 352, 636, 370, 950, 917, 959, 364, 453, 890, 43, 98, 438,
// 748, 277, 115, 298, 431, 709, 312, 49, 553, 395, 798, 58, 419, 355, 770, 818, 460, 89, 880, 515,
// 952, 219, 608, 284, 532, 254, 361, 524, 199, 265, 407, 782, 737, 928, 977, 729, 510, 175, 609, 81,
// 155, 24, 425, 186, 999, 839, 896, 721}
// 150
//
// Returns: 43325
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!

#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

#define in freopen("fighting_the_zombie.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

long double dp[25][20*2000+5];
bool visited[25][2000*20+5];
int y;

long double call(int baki, int lagbe)
{
	if(lagbe <= 0)
		return 1.0;
	if(baki <= 0)
		return 0;
	bool &vis = visited[baki][lagbe];
	long double &ret = dp[baki][lagbe];
	if(vis) return ret;
	ret = 0;
	vis = 1;
	for(int i = 1; i <= y; i++)
		ret += call(baki-1, lagbe-i);
	ret /= y;
	return ret;
}

int main()
{
	in;
	out;
	int test, kase = 1, h, n;
	string s;
	long double res;
	cin >> test;
	while(test--)
	{
		cin >> h >> n;
		res = 0;
		while(n--)
		{
			cin >> s;
			int arr[3] = {0}, i = 0;
			char sign;
			for(auto x: s)
			{
				if(isdigit(x))
					arr[i] = arr[i]*10+(x-'0');
				else
					i++, sign = x;
			}
			clr(visited, 0);
			y = arr[1];
			if(arr[2])
			{
				if(sign == '+')
					res = max(res, call(arr[0], h-arr[2]));
				else
					res = max(res, call(arr[0], h+arr[2]));
			}
			else
				res = max(res, call(arr[0], h));
		}
		cout << setprecision(8) << fixed;
		cout << "Case #"<< kase++ << ": " << res << "\n";
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 












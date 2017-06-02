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

#define in freopen("input.in", "r", stdin);
#define out freopen("output.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
#define infinity (1 << 25)
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

#define MAX 1500
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int dp[721][721][2], n = 1440, arr[MAX];

int call(int minute, int a, int b, int cur)
{
	if(minute == n)
		return 0;
	int &ret = dp[a][b][cur];
	if(ret != -1) return ret;
	ret = infinity;
	if(cur == 0)
	{
		if(arr[minute] != 1 && a < 720)
			ret = min(ret, call(minute+1, a + 1, b, cur));
		if(arr[minute] != 0 && b < 720)
			ret = min(ret, call(minute+1, a, b + 1, !cur) + 1);
	}
	else
	{
		if(arr[minute] != 1 && a < 720)
			ret = min(ret, call(minute+1, a + 1, b, !cur) + 1);
		if(arr[minute] != 0 && b < 720)
			ret = min(ret, call(minute+1, a, b + 1, cur));
	}
	return ret;
}

int main()
{
	in;
	out;
	int test, kase = 1, ac, aj, c, d, j, k;
	cin >> test;
	while(test--)
	{
		cin >> ac >> aj;
		for(int i = 0; i < MAX; i++)
			arr[i] = 2;
		while(ac--)
		{
			cin >> c >> d;
			while(c <= d)
				arr[c++] = 0;
		}
		while(aj--)
		{
			cin >> j >> k;
			while(j <= k)
				arr[j++] = 1;
		}
		clr(dp, -1);
		int res1 = call(0, 0, 0, 0)+1;
		int res2 = call(0, 0, 0, 1)+1;
		cout << "Case #" << kase++ << ": " << min(res1, res2) << "\n";
		cerr << "Case #" << kase-1 << ": " << min(res1, res2) << "\n";
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 
















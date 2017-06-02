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

#define in freopen("input.in", "r", stdin);
#define out freopen("output.out", "w", stdout);
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 2010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int dp[MAX][MAX];
string a, b;

int call(int i, int j)
{
	if(i == SZ(a) && j == SZ(b))
	{
		// cout << "ok" << endl;
		return 1;
	}
	int &ret = dp[i][j];
	if(~ret) return ret;
	ret = 0;
	if(i < SZ(a) && j < SZ(b) && a[i] == b[j])
		ret = max(ret, call(i+1, j+1));
	if(i < SZ(a) && a[i] == '*')
	{
		ret = max(ret, call(i+1, j));
		for(int k = j, cnt = 0; k < SZ(b); k++)
		{
			if(b[k] != '*')
				cnt++;
			if(cnt > 4)
				break;
			ret = max(ret, call(i+1, k+1));
		}
	}
	if(j < SZ(b) && b[j] == '*')
	{
		ret = max(ret, call(i, j+1));
		for(int k = i, cnt = 0; k < SZ(a); k++)
		{
			if(a[k] != '*')
				cnt++;
			if(cnt > 4)
				break;
			ret = max(ret, call(k+1, j+1));
		}
	}
	return ret;
}

int main()
{
	in;
	out;
	int test, kase = 1;
	cin >> test;
	while(test--)
	{
		cin >> a >> b;
		clr(dp, -1);
		cout << "Case #" << kase++ << ": ";
		if(call(0, 0))
			cout << "TRUE\n";
		else
			cout << "FALSE\n";
		cerr << kase << endl;
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 
















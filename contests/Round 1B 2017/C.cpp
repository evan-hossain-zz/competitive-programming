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
#define out freopen("output2.out", "w", stdout);
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

#define MAX 210
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

long double t[MAX][MAX];
LL n, q, E[MAX], S[MAX], d[MAX][MAX];

int main()
{
	in;
	out;
	LL test, kase = 1, u, v, i, j, k;
	cin >> test;
	while(test--)
	{
		cin >> n >> q;
		for(i = 0; i < n; i++)
			cin >> E[i] >> S[i];
		for(i = 0; i < n; i++)
			d[i][i] = 0;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				cin >> d[i][j];
				if(d[i][j] == -1)
					d[i][j] = 1LL<<50;
				t[i][j] = 1LL<<50;
			}
			t[i][i] = 0;
		}
		for(k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				long double dist = d[i][j];
				if(dist <= E[i])
					t[i][j] = min(t[i][j], dist/S[i]);
			}
		}
		for(k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
		cout << "Case #" << kase++ << ":";
		cerr << "Case #" << kase-1 << ":";
		while(q--)
		{
			cin >> u >> v, u--, v--;
			cout << setprecision(8) << fixed;
			cerr << setprecision(8) << fixed;
			cout << " " << t[u][v];
			cerr << " " << t[u][v];
		}
		cout << "\n";
		cerr << "\n";
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 
















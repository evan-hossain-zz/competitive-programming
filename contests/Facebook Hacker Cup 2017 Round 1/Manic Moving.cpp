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

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
#define infinity (1LL << 58)
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

#define MAX 110
#define MAXEDGE 5010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL dist[MAX][MAX], dp[MAXEDGE][MAX], k, start[MAXEDGE], finish[MAXEDGE], n;

int main()
{
	in;
	// out;
	int test, kase = 1, m, u, v, g, i, j;
	cin >> test;
	while(test--)
	{
		clr(dist, 63);
		for(i = 1; i <= n; i++)
			dist[i][i] = 0;
		cin >> n >> m >> k;
		while(m--)
		{
			cin >> u >> v >> g;
			dist[u][v] = min(dist[u][v], 1LL*g);
			dist[v][u] = min(dist[v][u], 1LL*g);
		}
		for(i = 1; i <= k; i++)
			cin >> start[i] >> finish[i];
		for(int l = 1; l <= n; l++)
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
		for(i = 1; i <= k; i++)
			for(j = 0; j <= n; j++)
				dp[i][j] = infinity;
		finish[0] = 1;
		for(i = 1; i <= k; i++)
		{
			for(int previous_node = 0; previous_node <= n; previous_node++)
			{
				for(int current_node = 0; current_node <= n; current_node++)
				{
					LL &cur = dp[i][current_node];
					if(previous_node == 0)
					{
						if(current_node == 0)
							cur = min(cur, dist[finish[i-1]][start[i]] + dist[start[i]][finish[i]]);
						else
						{
							cur = min(cur, dist[finish[i-1]][start[i]] + dist[start[i]][current_node] +
								dist[current_node][finish[i]]);
							cur = min(cur, dist[finish[i-1]][current_node] + dist[current_node][start[i]] +
								dist[start[i]][finish[i]]);
							cur = min(cur, dist[finish[i-1]][start[i]] + dist[start[i]][finish[i]] +
								dist[finish[i]][current_node]);
						}
					}
					else
					{
						if(current_node == 0)
						{
							if(start[i] == previous_node)
								cur = min(cur, dist[finish[i-1]][finish[i]]);
						}
						else if(current_node == previous_node)
						{
							cur = min(cur, dist[finish[i-1]][start[i]] + dist[start[i]][finish[i]]);
						}
					}
					cur += dp[i-1][current_node];
					cout << i << ' ' << previous_node << ' ' << current_node << ' ' << cur << endl;
				}
			}
		}
		LL res = infinity;
		for(int i = 0; i <= n; i++)
		{
			if(dp[k][i] > 0)
				res = min(res, dp[k][i]), cout << "k " << k << ' ' << i << ' ' << dp[k][i] << endl;
		}
		if(res == infinity)
			res = -1;
		cout << "Case #" << kase ++ << ": " << res << "\n";
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 












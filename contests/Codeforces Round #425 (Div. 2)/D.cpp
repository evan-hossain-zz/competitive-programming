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
#define out freopen("control.out", "w", stdout);
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
#define LN 20
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int level[MAX], dp[MAX][LN];
vector <int> adj[MAX];

void dfs(int node, int prev)
{
    dp[node][0] = prev;
    level[node] = prev == -1? 1 : level[prev]+1;
    for(int i = 0; i < SZ(adj[node]); i++)
        if(adj[node][i] != prev)
            dfs(adj[node][i], node);
}

void process(int n)
{
    dfs(1, -1);
    int i, lev;
    for(lev = 1; lev < LN; lev++)
    {
        for(i = 1; i <= n; i++)
        {
            if(dp[i][lev - 1] != -1)
                dp[i][lev] = dp[dp[i][lev - 1]][lev - 1];
        }
    }
}

int lca(int high, int low)
{
    if(level[low] < level[high]) swap(low, high);
    int i, diff;
    diff = level[low] - level[high];
    for(i = 0; i < LN; i++)
        if(diff & (1 << i))
            low = dp[low][i];
    if(low == high) return low;
    for(i = LN-1; i >= 0; i--)
    {
        if(dp[low][i] != -1 && dp[low][i] != dp[high][i])
        {
            low = dp[low][i];
            high = dp[high][i];
        }
    }
    return dp[low][0];
}

int main()
{
	in;
    int n, m, i, j, q, a, b, c, u, v, arr[3];
    while(cin >> n >> q)
    {
        memset(dp, -1, sizeof dp);
        for(i = 2; i <= n; i++)
        {
            cin >> u;
            adj[u].pb(i);
            adj[i].pb(u);
        }
        process(n);
        for(i = 0; i < q; i++)
        {
        	int res = 0;
        	for(j = 0; j < 3; j++)
        		cin >> arr[j];
        	sort(arr, arr+3);
        	do{
        		a = arr[0];
        		b = arr[1];
        		c = arr[2];
        		// cout << a << ' ' << b << ' ' << c << endl;

        		int l = lca(a, b);
        		// cout << "lca of " << a << ", " << b << ": " << l << endl;
        		if(l == a)
        		{
        			if(lca(b, c) == b) //a->b->c
        				res = max(res, abs(level[c] - level[b]) + 1);
        			if(lca(b, c) == c) //a->c->b
        				res = max(res, 1);
        			if(lca(a, c) == c) //c->a->b
        				res = max(res, abs(level[c] - level[a]) + 1);
        			if(lca(l, c) != c && lca(l, c) != l)
        				res = max(res, level[c] + level[a] + 1 - 2*level[lca(a, c)]);
        		}
        		if(l == b)
        		{

        			if(lca(a, c) == a) //b->a->c
        				res = max(res, abs(level[c] - level[a]) + 1);
        			if(lca(a, c) == c) //b->c->a
        				res = max(res, 1);
        			if(lca(b, c) == c) //c->b->a
        				res = max(res, abs(level[c] - level[b]) + 1);
        			if(lca(l, c) != c && lca(l, c) != l)
        				res = max(res, level[c] + level[b] + 1 - 2*level[lca(b, c)]);	
        		}
        		if(lca(a, c) == a)
        			res = max(res, abs(level[c] - level[a]) + 1);
        		if(lca(b, c) == b)
        			res = max(res, abs(level[c] - level[b]) + 1);
        		if(lca(b, c) != b && lca(a, c) != a)
        			res = max(res, level[l] + level[c] + 1 - 2*level[lca(l, c)]);

        	}while(next_permutation(arr, arr+3));
        	cout << res << "\n";
        }
    }
    return 0;
}

// clang++ -std=c++11 -stdlib=libc++ 
















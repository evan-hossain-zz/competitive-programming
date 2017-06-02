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
#include <unordered_map>

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

#define MAX 10
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

vector <int> adj[MAX];
map <pair<int,string>,bool> seen;
bitset <MAX> can_be_visited_by[MAX], can_visit[MAX];

bitset<MAX> dfs(int u, bitset <MAX> status)
{
	pair<int, string> f = mp(u, status.to_string());
	if(seen.find(f) != seen.end())
		return can_visit[u];
	seen[f] = true;
	can_be_visited_by[u] |= status;
	status.set(u);
	for(auto v: adj[u])
	{
		can_visit[u] |= dfs(v, status);
		can_visit[u].set(v);
	}
	return can_visit[u];
}

void create_node(int u, int v)
{
	can_be_visited_by[v] |= can_be_visited_by[u];
	can_be_visited_by[v].set(u);
	can_visit[u] |= can_visit[v];
	can_visit[u].set(v);
	cout << can_visit[u] << ' ' << can_visit[v] << endl;
}

int main()
{
	in;
	int n, m, q, u, v, i, t;
	cin >> n >> m;
	while(m--)
	{
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
	}
	bitset <MAX> dummy;
	for(i = 0; i < n; i++)
	{
		dfs(i, dummy);
		cout << i << ' ' << can_visit[i].to_string() << endl;
	}
	cin >> q;
	while(q--)
	{
		cin >> t >> u >> v;
		if(t == 1)
		{
			if(v == 0)
				create_node(u-1, n++);
			else
				create_node(n++, u-1);
		}
		else
		{
			if(can_be_visited_by[--v].test(--u))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 
















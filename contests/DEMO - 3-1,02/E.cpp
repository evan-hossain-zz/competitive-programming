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
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

#define root 0
#define LN 18

vector <int> adj[MAX], costs[MAX];
int depth[MAX], par[MAX][LN], dist[MAX][LN];

void process(int n)
{
    int h, i, lev;
    h = LN-1;
    for(lev = 1; lev <= h; lev++)
    {
        for(i = 0; i < n; i++)
        {
            if(par[i][lev-1] != -1)
            {
                par[i][lev] = par[par[i][lev-1]][lev-1];
                dist[i][lev] = dist[i][lev-1] + dist[par[i][lev-1]][lev-1];
            }
        }
    }
}

pair<int, int> LCA(int high, int low)
{
    if(depth[low] < depth[high]) swap(low, high);
    int h, i, diff, cost = 0;
    h = LN-1;
    diff = depth[low] - depth[high];
    for(i = 0; i <= h; i++)
        if(diff & (1 << i))
        {
            cost += dist[low][i];
            low = par[low][i];
        }
    if(low == high) return mp(low, cost);
    for(i = h; i >= 0; i--)
    {
        if(par[low][i] != -1 && par[low][i] != par[high][i])
        {
            cost += dist[low][i] + dist[high][i];
            low = par[low][i];
            high = par[high][i];
        }
    }
    cost += dist[low][0] + dist[high][0];
    return mp(par[low][0], cost);
}

void dfs(int cur, int prev, int d, int cost)
{
    par[cur][0] = prev;
    dist[cur][0] = cost;
    depth[cur] = d;
    for(int i = 0; i < SZ(adj[cur]); i++)
    {
        int v = adj[cur][i];
        if(v == prev) continue;
        dfs(v, cur, d + 1, costs[cur][i]);
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, i, u, v, c = -1, m, res = infinity;
    while(scanf("%d", &n) == 1)
    {
        if(c != -1)
            puts("");
        for(i = 0; i < n; i++) adj[i].clear(), costs[i].clear();
        for(i = 1; i < n; i++)
        {
            scanf("%d %d %d", &u, &v, &c);
            adj[u].pb(v);
            adj[v].pb(u);
            costs[u].pb(c);
            costs[v].pb(c);
        }
        clr(par, -1);
        dfs(root, -1, 0, 0);
        process(n);
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &c);
            vector <pair<int, int> > tem;
            tem.pb(mp(depth[u], u));
            tem.pb(mp(depth[v], v));
            tem.pb(mp(depth[c], c));
            sort(all(tem));
            res = infinity;
            int temres;
            do{
                temres = LCA(tem[1].second, tem[2].second).second;
                temres += LCA(tem[0].second, LCA(tem[1].second, tem[2].second).first).second;
                res = min(res, temres);
            }while(next_permutation(all(tem)));
            printf("%d\n", res);
        }
        c = 1;
    }
    return 0;
}

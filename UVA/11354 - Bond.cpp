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

#define MAX 50001
/*************************************************HABIJABI ENDS HERE******************************************************/

int level[MAX], pwr[MAX][17], mx[MAX][17], par[MAX];
queue <int> Q;

struct info{
    int node, cost;
    info(int n, int d)
    {
        node = n;
        cost = d;
    }
};
vector <info> adj[MAX];

struct edge
{
    int u, v, w;
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};
vector <edge> e;

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

void mst(int n)
{
    int cnt = n - 1, i;
    sort(e.begin(), e.end());
    for(i = 1; i <= n; i++)
        par[i] = i;
    for(i = 0; i < SZ(e) && cnt; i++)
    {
        int u = find_set(e[i].u);
        int v = find_set(e[i].v);
        if(u != v)
        {
            par[u] = v;
            adj[e[i].u].pb(info(e[i].v, e[i].w));
            adj[e[i].v].pb(info(e[i].u, e[i].w));
            cnt--;
        }
    }
}

void bfs(void)
{
    clr(level, 0);
    Q.push(1);
    level[1] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int elements = adj[u].size(), v, c;
        for(int i = 0; i < elements; i++)
        {
            v = adj[u][i].node;
            c = adj[u][i].cost;
            if(level[v]) continue;
            level[v] = level[u] + 1;
            pwr[v][0] = u;
            mx[v][0] = c;
            Q.push(v);
        }
    }
}

void process(int n)
{
    int h, i, lev;
    h = log2(n) + 1;

    for(lev = 1; lev <= h; lev++)
    {
        for(i = 1; i <= n; i++)
        {
            if(pwr[i][lev - 1] != -1)
            {
                mx[i][lev] = max(mx[i][lev - 1], mx[pwr[i][lev - 1]][lev - 1]);
                pwr[i][lev] = pwr[pwr[i][lev - 1]][lev - 1];
            }
        }
    }
}

int query(int high, int low)
{
    if(level[low] < level[high]) swap(low, high);
    int h, i, diff, ret = 0;
    h = log2(level[low]) + 1;
    diff = level[low] - level[high];
    for(i = 0; i <= h; i++)
        if(diff & (1 << i))
        {
            ret = max(ret, mx[low][i]);
            low = pwr[low][i];
        }
    if(low == high) return ret;
    for(i = h; i >= 0; i--)
    {
        if(pwr[low][i] != -1 && pwr[low][i] != pwr[high][i])
        {
            ret = max(ret, mx[low][i]);
            ret = max(ret, mx[high][i]);
            low = pwr[low][i];
            high = pwr[high][i];
        }
    }
    ret = max(ret, mx[low][0]);
    ret = max(ret, mx[high][0]);
    return ret;
}

int main()
{
    #ifdef Evan
        in;
    #endif
    int n, m, u, v, cost = -1, i, q;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(cost != -1) printf("\n");
        clr(pwr, -1);
        e.clear();
        for(i = 1; i <= n; i++) adj[i].clear();
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &cost);
            e.pb(edge(u, v, cost));
            e.pb(edge(v, u, cost));
        }
        mst(n);
        bfs();
        process(n);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d", &u, &v);
            printf("%d\n", query(u, v));
        }
    }
    return 0;
}


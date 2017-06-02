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

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void show(T a){cout << a << endl;}
template <class T> void show(T a, T b){cout << a << ' ' << b << endl;}
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 30010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

#define root 0
#define LN 16 ///log2(MAX)

vector <int> adj[MAX];
int arr[MAX], now, costs[MAX];
int chain_no, chain_indx[MAX], chain_head[MAX], pos_in_arr[MAX];
int depth[MAX], par[MAX][LN], child[MAX];
int segtree[MAX*3];

void build(int s, int e, int cur)
{
    if(s == e)
    {
        segtree[cur] = arr[s];
        return;
    }
    int lchild = (cur << 1), rchild = lchild | 1, m = (s + e) >> 1;
    build(s, m, lchild);
    build(m+1, e, rchild);
    segtree[cur] = segtree[lchild] + segtree[rchild];
}

void update(int s, int e, int cur, int indx, int val)
{
    if(s == e)
    {
        segtree[cur] = val;
        return;
    }
    int lchild = (cur << 1), rchild = lchild | 1, m = (s + e) >> 1;
    if(indx <= m)
        update(s, m, lchild, indx, val);
    else
        update(m+1, e, rchild, indx, val);
    segtree[cur] = segtree[lchild] + segtree[rchild];
}

int query_tree(int s, int e, int cur, int L, int R)
{
    if(s > R || e < L)
        return 0;
    if(s >= L && e <= R)
        return segtree[cur];
    int lchild = (cur << 1), rchild = lchild | 1, m = (s + e) >> 1;
    return query_tree(s, m, lchild, L, R) + query_tree(m+1, e, rchild, L, R);
}
/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */
int query_up(int u, int v)
{
    int uchain, vchain = chain_indx[v], ans = 0;
    while(true)
    {
        uchain = chain_indx[u];
        if(uchain == vchain)
        {
            ans += query_tree(0, now-1, 1, pos_in_arr[v], pos_in_arr[u]);
            break;
        }
        ans += query_tree(0, now-1, 1, pos_in_arr[chain_head[uchain]], pos_in_arr[u]);
        u = chain_head[uchain];
        u = par[u][0];
    }
    return ans;
}

void process(int n)
{
    int h, i, lev;
    h = LN - 1;

    for(lev = 1; lev <= h; lev++)
    {
        for(i = 0; i < n; i++)
        {
            if(par[i][lev - 1] != -1)
                par[i][lev] = par[par[i][lev - 1]][lev - 1];
        }
    }
}

int LCA(int high, int low)
{
    if(depth[low] < depth[high]) swap(low, high);
    int h, i, diff;
    h = LN - 1;
    diff = depth[low] - depth[high];
    for(i = 0; i <= h; i++)
        if(diff & (1 << i))
            low = par[low][i];
    if(low == high) return low;
    for(i = h; i >= 0; i--)
    {
        if(par[low][i] != -1 && par[low][i] != par[high][i])
        {
            low = par[low][i];
            high = par[high][i];
        }
    }
    return par[low][0];
}

int query(int u, int v)
{
    int lca = LCA(u, v);
    return query_up(u, lca) + query_up(v, lca) - query_tree(0, now-1, 1, pos_in_arr[lca], pos_in_arr[lca]);
}

void change(int i, int val)
{
    update(0, now-1, 1, pos_in_arr[i], val);
}

void HLD(int cur_node, int prev)
{
    if(chain_head[chain_no] == -1)
        chain_head[chain_no] = cur_node;
    chain_indx[cur_node] = chain_no;
    pos_in_arr[cur_node] = now;
    arr[now++] = costs[cur_node];
    int schild = -1, i, v;
    for(i = 0; i < SZ(adj[cur_node]); i++)
    {
        v = adj[cur_node][i];
        if(v == prev) continue;
        if(schild == -1 || child[schild] < child[v])
            schild = v;
    }
    if(schild != -1)
        HLD(schild, cur_node);
    for(i = 0; i < SZ(adj[cur_node]); i++)
    {
        v = adj[cur_node][i];
        if(v == prev) continue;
        if(schild != v)
        {
            chain_no++;
            HLD(v, cur_node);
        }
    }
}

void dfs(int cur, int prev, int d)
{
    par[cur][0] = prev;
    depth[cur] = d;
    child[cur] = 1;
    for(int i = 0; i < SZ(adj[cur]); i++)
    {
        int v = adj[cur][i];
        if(v == prev) continue;
        dfs(v, cur, d + 1);
        child[cur] += child[v];
    }
}

void init(int n)
{
    now = chain_no = 0;
    for(int i = 0; i < n; i++)
    {
        adj[i].clear();
        chain_head[i] = -1;
        for(int j = 0; j < LN; j++)
            par[i][j] = -1;
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int test, n, m, q, u, v, kase = 1, i;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        init(n);
        for(i = 0; i < n; i++)
            scanf("%d", &costs[i]);
        for(i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(root, -1, 0);
        HLD(root, -1);
        build(0, now-1, 1);
        process(now);
        scanf("%d", &m);
        printf("Case %d:\n", kase++);
        while(m--)
        {
            scanf("%d %d %d", &q, &u ,&v);
            if(q)
                change(u, v);
            else
                printf("%d\n", query(u, v));
        }
    }
    return 0;
}

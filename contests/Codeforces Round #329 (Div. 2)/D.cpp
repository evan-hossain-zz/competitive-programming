#include <bits/stdc++.h>

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

#define MAX 400010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

#define root 0
#define LN 22 ///log2(MAX)

vector <LL> adj[MAX];
vector <LL> costs[MAX];
LL arr[MAX], now;
LL chain_no, chain_indx[MAX], chain_head[MAX], pos_in_arr[MAX];
LL depth[MAX], par[MAX][LN], child[MAX];
LL segtree[MAX*4];
struct edge{
    LL u, v;
    LL c;
    edge(){}
    edge(LL uu, LL vv, LL cc)
    {
        u = uu;
        v = vv;
        c = cc;
    }
};
vector <edge> edges;

void build(LL s, LL e, LL cur)
{
    if(s == e)
    {
        segtree[cur] = arr[s];
        return;
    }
    LL lchild = cur << 1, rchild = lchild | 1, m = (s + e) >> 1;
    build(s, m, lchild);
    build(m+1, e, rchild);
    segtree[cur] = max(segtree[lchild], segtree[rchild]);
}

void update(LL s, LL e, LL cur, LL indx, LL val)
{
    if(s == e)
    {
        segtree[cur] = val;
        return;
    }
    LL lchild = cur << 1, rchild = lchild | 1, m = (s + e) >> 1;
    if(indx <= m)
        update(s, m, lchild, indx, val);
    else
        update(m+1, e, rchild, indx, val);
    segtree[cur] = max(segtree[lchild], segtree[rchild]);
}

LL query_tree(LL s, LL e, LL cur, LL L, LL R)
{
    if(s > R || e < L)
        return 0;
    if(s >= L && e <= R)
        return segtree[cur];
    LL lchild = cur << 1, rchild = lchild | 1, m = (s + e) >> 1;
    return max(query_tree(s, m, lchild, L, R),
                query_tree(m+1, e, rchild, L, R));
}
LL query_up(LL u, LL v)
{
    if(u == v) return 0;
    LL uchain, vchain = chain_indx[v];
    LL ans = -1;
    while(true)
    {
        uchain = chain_indx[u];
        if(uchain == vchain)
        {
            if(u == v) break;
            ans = max(ans, query_tree(0, now, 1, pos_in_arr[v]+1, pos_in_arr[u]));
            break;
        }
        ans = max(ans, query_tree(0, now, 1, pos_in_arr[chain_head[uchain]], pos_in_arr[u]));
        u = chain_head[uchain];
        u = par[u][0];
    }
    return ans;
}

void process(LL n)
{
    LL h, i, lev;
    h = LN-1;

    for(lev = 1; lev <= h; lev++)
    {
        for(i = 0; i < n; i++)
        {
            if(par[i][lev - 1] != -1)
                par[i][lev] = par[par[i][lev - 1]][lev - 1];
        }
    }
}

LL LCA(LL high, LL low)
{
    if(depth[low] < depth[high]) swap(low, high);
    LL h, i, diff;
    h = LN - 1;
    diff = depth[low] - depth[high];
    for(i = 0; i <= h; i++)
        if(diff & (1LL << i))
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

LL query(LL u, LL v)
{
    LL lca = LCA(u, v);
    return max(query_up(u, lca), query_up(v, lca));
}

void change(LL i, LL val)
{
    edge tem = edges[i];
    LL pos = pos_in_arr[tem.u];
    if(depth[tem.u] < depth[tem.v])
        pos = pos_in_arr[tem.v];
    update(0, now, 1, pos, val);
}

void HLD(LL cur_node, LL cost, LL prev)
{
    if(chain_head[chain_no] == -1)
        chain_head[chain_no] = cur_node;
    chain_indx[cur_node] = chain_no;
    pos_in_arr[cur_node] = now;
    arr[now++] = cost;
    LL schild = -1, ncost, i, v;
    for(i = 0; i < SZ(adj[cur_node]); i++)
    {
        v = adj[cur_node][i];
        if(v == prev) continue;
        if(schild == -1 || child[schild] < child[v])
        {
            schild = v;
            ncost = costs[cur_node][i];
        }
    }
    if(schild != -1)
        HLD(schild, ncost, cur_node);
    for(i = 0; i < SZ(adj[cur_node]); i++)
    {
        v = adj[cur_node][i];
        if(v == prev) continue;
        if(schild != v)
        {
            chain_no++;
            HLD(v, costs[cur_node][i], cur_node);
        }
    }
}

void dfs(LL cur, LL prev, LL d)
{
    par[cur][0] = prev;
    depth[cur] = d;
    child[cur] = 1;
    for(LL i = 0; i < SZ(adj[cur]); i++)
    {
        LL v = adj[cur][i];
        if(v == prev) continue;
        dfs(v, cur, d + 1);
        child[cur] += child[v];
    }
}

void init(LL n)
{
    edges.clear();
    for(LL i = 0; i < n; i++)
    {
        adj[i].clear();
        costs[i].clear();
        chain_head[i] = -1;
        for(LL j = 0; j < LN; j++)
            par[i][j] = -1;
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL test, n, i, u, v, c, m;
    now = chain_no = 0;
    scanf("%I64d %I64d", &n, &m);
    init(n);
    clr(par, -1);
    for(i = 1; i < n; i++)
    {
        scanf("%I64d %I64d %I64d", &u, &v, &c);
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
        costs[u].pb(c);
        costs[v].pb(c);
        edges.pb(edge(u, v, c));
    }
    dfs(root, -1, 0);
    HLD(root, -1, -1);
    now--;
    build(0, now, 1);
    process(n);
    while(m--)
    {
        int cur;
        scanf("%d", &cur);
        if(cur == 2)
        {
            scanf("%I64d %I64d", &u, &v);
            change(u-1, v);
            continue;
        }
        scanf("%I64d %I64d %I64d", &u, &v, &c);
        u--, v--;
        int lca = LCA(u, v), tem;
        while(u != lca)
        {
            if(query(u, lca) == 1 || c < 1) break;
            while(u != lca)
            {
                LL now = query(u, par[u][0]);
                if(now == 1) break;
                c /= now;
                u = par[u][0];
            }
            tem = u;
            for(i = 0; ; i++)
            {
                int newU = par[u][i];
                if(newU == -1) break;
                if(depth[newU] < depth[lca]) break;
                if(query(u, newU) == 1)
                    tem = newU;
            }
            u = tem;
        }
        while(v != lca)
        {
            if(query(v, lca) == 1 || c < 1) break;
            while(v != lca)
            {
                LL now = query(v, par[v][0]);
                if(now == 1) break;
                c /= now;
                v = par[v][0];
            }
            tem = v;
            for(i = 0; ; i++)
            {
                int newV = par[v][i];
                if(newV == -1) break;
                if(depth[newV] < depth[lca]) break;
                if(query(v, newV) == 1)
                    tem = newV;
            }
            v = tem;
        }
        printf("%I64d\n", c);
    }
    return 0;
}

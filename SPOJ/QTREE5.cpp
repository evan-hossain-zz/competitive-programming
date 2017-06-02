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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 100010
#define LN 20
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int level[MAX], dp[MAX][LN], child[MAX], par[MAX], deleted[MAX], res[MAX];
vector <int> adj[MAX];
bool color[MAX];
set <pair<int,int>> nodes[MAX];

void dfs(int node, int prev)
{
    dp[node][0] = prev;
    level[node] = prev == -1? 0 : level[prev]+1;
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

int getDist(int u, int v)
{
    return level[u] + level[v] - 2*level[lca(u,v)];
}

void dfs2(int u, int prev)
{
    child[u] = 1;
    for(auto v: adj[u])
        if(v != prev && !deleted[v])
            dfs2(v, u), child[u] += child[v];
}

int dfs2(int u, int prev, int nodesLeft)
{
    for(auto v: adj[u])
        if(v != prev && !deleted[v] && child[v] > nodesLeft/2)
            return dfs2(v, u, nodesLeft);
    return u;
}

void decompose(int u, int prev)
{
    dfs2(u, -1);
    int centroid = dfs2(u, -1, child[u]);
    par[centroid] = prev;
    deleted[centroid] = 1;
    for(auto v: adj[centroid])
        if(!deleted[v])
            decompose(v, centroid);
}

void update(int u)
{
    color[u] = 1-color[u];
    int x = u;
    while(x != -1)
    {
        if(color[u])
            nodes[x].insert(mp(getDist(x, u), u));
        else
            nodes[x].erase(mp(getDist(x, u), u));
        x = par[x];
    }
}

int query(int u)
{
    int ret = infinity, x = u;
    while(x != -1)
    {
        if(!nodes[x].empty())
            ret = min(ret, nodes[x].begin()->first+getDist(u, x));
        x = par[x];
    }
    return ret == infinity? -1 : ret;
}
int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, i, u, v;
    cin >> n;
    for(i = 1; i < n; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    process(n);
    decompose(1, -1);
    clr(res, 63);
    cin >> m;
    while(m--)
    {
        cin >> u >> v;
        if(u == 0)
            update(v);
        else
            cout << query(v) << "\n";
    }
    return 0;
}

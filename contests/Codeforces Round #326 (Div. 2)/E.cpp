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

#define MAX 100001
#define LN 18
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int level[MAX], par[MAX][LN];
vector <int> dp[MAX][LN], citizen[MAX], adj[MAX];

vector <int> merge(vector <int> &a, vector <int> &b, int s)
{
    int i = 0, j = 0;
    vector <int> ret;
    while(i < SZ(a) && j < SZ(b))
    {
        if(a[i] < b[j])
            ret.pb(a[i++]);
        else
            ret.pb(b[j++]);
    }
    while(i < SZ(a)) ret.pb(a[i++]);
    while(j < SZ(b)) ret.pb(b[j++]);
    ret.resize(min(SZ(ret), s));
    return ret;
}

void dfs(int node, int prev)
{
    par[node][0] = prev;
    dp[node][0] = merge(dp[node][0], citizen[node], 10);
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
            if(par[i][lev - 1] != -1)
            {
                dp[i][lev] = merge(dp[i][lev-1], dp[par[i][lev - 1]][lev - 1], 10);
                par[i][lev] = par[par[i][lev - 1]][lev - 1];
            }
        }
    }
}

vector <int> lca(int high, int low, int a)
{
    vector <int> ret;
    if(level[low] < level[high]) swap(low, high);
    int i, diff;
    diff = level[low] - level[high];
    for(i = 0; i < LN; i++)
        if(diff & (1 << i))
        {
            ret = merge(ret, dp[low][i], a);
            low = par[low][i];
        }
    if(low == high)
    {
        ret = merge(ret, dp[low][0], a);
        return ret;
    }
    for(i = LN-1; i >= 0; i--)
    {
        if(par[low][i] != -1 && par[low][i] != par[high][i])
        {
            ret = merge(ret, dp[low][i], a);
            ret = merge(ret, dp[high][i], a);
            low = par[low][i];
            high = par[high][i];
        }
    }
    ret = merge(ret, dp[low][0], a);
    ret = merge(ret, dp[high][0], a);
    ret = merge(ret, dp[par[low][0]][0], a);
    return ret;
}


int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, q, i, u, v;
    cin >> n >> m >> q;
    clr(par, -1);
    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(i = 1; i <= m; i++)
    {
        cin >> u;
        citizen[u].pb(i);
        sort(all(citizen[u]));
        if(SZ(citizen[u]) > 10)
            citizen[u].pop_back();
    }
    process(n);
    while(q--)
    {
        cin >> u >> v >> m;
        auto ret = lca(u, v, m);
        cout << SZ(ret) << ' ';
        for(auto x: ret)
            cout << x << ' ';
        cout << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 2000010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

struct edge{
    int u, v, w;
    edge(){}
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (const edge & p) const{
        return w < p.w;
    }
};

vector <edge> edgeList;
int par[MAX];

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

vector <pair<int,int>> adj[MAX];

void mst(int n)
{
    int ret = 0, cnt = n - 1, i;
    sort(all(edgeList));
    for(i = 1; i <= n; i++) par[i] = i;
    for(i = 0; i < SZ(edgeList) && cnt; i++)
    {
        int u = find_set(edgeList[i].u);
        int v = find_set(edgeList[i].v);
        if(u != v)
        {
            par[u] = v;
            adj[edgeList[i].u].pb(mp(edgeList[i].v, edgeList[i].w));
            adj[edgeList[i].v].pb(mp(edgeList[i].u, edgeList[i].w));

            cnt--;
        }
    }
}

LL child[MAX], res[MAX], n;

void dfs(int u, int par)
{
    child[u] = 1;
    for(auto v: adj[u])
    {
        if(v.first != par)
        {
            dfs(v.first, u);
            child[u] += child[v.first];
            res[v.second] += 1LL*child[v.first] * (n-child[v.first]);
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int m, u, v, w, i;
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w;
        edgeList.pb(edge(u, v, w));
    }
    mst(n);
    dfs(1, -1);
    for(i = 0; i < MAX; i++)
    {
        if(res[i] > 1 && (res[i] & (res[i]-1)) == 0)
        {
            res[i+no_of_ones(res[i]-1)]++;
            res[i] = 0;
            continue;
        }
        res[i+1] += res[i]/2;
        res[i] %= 2;
    }
    string ans;
    for(i = MAX-1; i >= 0; i--)
    {
        if(res[i])
            ans += "1";
        else if(!ans.empty())
            ans += "0";
    }
    cout << ans;
    return 0;
}

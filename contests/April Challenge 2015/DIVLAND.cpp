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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100000
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL dfs(int node, vector <int> &color, vector <vector<pair<int,int>>> &adj)
{
    if(color[node] == 2) return 0;
    color[node] = 2;
    LL ret = 0;
    for(auto x: adj[node])
    {
        if(color[node] == color[x.first] && color[x.first] == 1)
            ret += x.second + dfs(x.first, color, adj);
        else
            ret += dfs(x.first, color, adj);
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    vector <int> res, taken;
    int n, m, dummy, u, v, i;
    cin >> n >> m;
    LL totalcost = 0;
    vector <vector<pair<int,int>>> adj(n);
    vector <int> indeg(n), vertex, cost(n), color(n);
    while(m--)
    {
        cin >> u >> v >> dummy;
        adj[u].pb({v, dummy});
        adj[v].pb({u, dummy});
        indeg[u]++, indeg[v]++;
        totalcost += dummy;
    }
    for(i = 0; i < n; i++)
    {
        if(!indeg[i])
            res.pb(i);
        else
            vertex.pb(i);
    }
    if(SZ(res) >= n/2)
    {
        for(i = 0; i < n/2; i++)
            cout << res[i] << ' ';
        cout << "\n";
        return 0;
    }
    taken = res;
    LL iter = 0, mincost = 1LL << 60;
    int limit = 200000;
    vector <int> tem;
    vector <int> other;
    tem = taken;
    random_shuffle(all(vertex));
    while(1)
    {
        iter += n;
        taken = tem;
        LL curcost = 0;
        fill(all(color), 0);
        other = tem;
        for(i = 0; i < n/2; i++)
            color[vertex[i]] = 1;
        while(i < n)
            other.pb(vertex[i++]);
        for(i = 0; i < n/2; i++)
            curcost += dfs(vertex[i], color, adj);
        if(min(curcost, totalcost-curcost) < mincost)
        {
            if(curcost > totalcost - curcost)
                res = other;
            else
                res = taken;
            mincost = min(curcost, totalcost-curcost);
        }
        srand(iter*time(NULL));
        random_shuffle(all(vertex));
        if(iter > limit)
            break;
    }
    while(SZ(res) < n/2)
        res.pb(vertex.back()), vertex.pop_back();
    for(i = 0; i < n/2; i++)
        cout << res[i] << ' ';
    cout << "\n";
    return 0;
}


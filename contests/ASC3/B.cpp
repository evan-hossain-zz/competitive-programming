#include <bits/stdc++.h>

#define in freopen("defence.in", "r", stdin);
#define out freopen("defence.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
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

#define MAX 404
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

vector <int> adj[MAX];
int dist[MAX];
queue <int> Q;

int main()
{
        in;
        out;
    int n, m, i, u, v, j, k, s, t;
    cin >> n >> m >> s >> t;
    vector <pair<int,int>> edges(0);
    while(m--)
    {
    	cin >> u >> v;
    	edges.pb(mp(u, v));
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    Q.push(s);
    clr(dist, 63);
    dist[s] = 0;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(auto v: adj[u])
        {
            if(dist[v] > dist[u]+1)
            {
                dist[v] = dist[u]+1;
                Q.push(v);
            }
        }
    }
    for(i = 1; i <= n; i++) adj[i].clear();
    for(i = 0; i < SZ(edges); i++)
    {
        auto e = edges[i];
        int mn = max(dist[e.first], dist[e.second]);
        if(mn <= dist[t])
            adj[mn].pb(i+1);
        else
            adj[1].pb(i+1);
    }
    cout << dist[t] << "\n";
    for(i = 1; i <= dist[t]; i++)
    {
        cout << SZ(adj[i]);
        for(auto x: adj[i])
            cout << ' ' << x;
        cout << "\n";
    }
    return 0;
}
/*
7 8 1 7
1 2
1 3
2 4
3 4
4 7
3 5
5 6
6 7
*/

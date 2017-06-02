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

#define MAX 500010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

map <pair<LL, LL>, pair<LL, int>> edge;
set <pair <LL, LL>> used;
pair <LL, LL> dist[MAX];
vector <pair<LL,LL>> adj[MAX];
int n, m;
int par[MAX];

void dijkstra(pair<LL,LL> source)
{
    priority_queue<pair<LL, LL>, vector <pair<LL,LL>>, greater<pair<LL,LL>>> Q;
    Q.push(source);
    for(int i = 1; i <= n; i++)
        dist[i] = {1LL << 50, 0};
    dist[source.second] = {0, 0};
    while(!Q.empty())
    {
        source = Q.top();
        Q.pop();
        for(auto x: adj[source.second])
        {
            if(dist[x.second].first > dist[source.second].first + x.first)
            {
                dist[x.second] = {dist[source.second].first + x.first, x.first};
                Q.push({dist[x.second].first, x.second});
                par[x.second] = source.second;
            }
            else if(dist[x.second].first == dist[source.second].first + x.first && dist[x.second].second > x.first)
            {
                dist[x.second] = {dist[source.second].first + x.first, x.first};
                Q.push({dist[x.second].first, x.second});
                par[x.second] = source.second;
            }
        }
    }
}

void getpar(int node)
{
    if(node == m)
        return;
    if(used.find({min(node, par[node]), max(node, par[node])}) == used.end())
    {
        used.insert({min(node, par[node]), max(node, par[node])});
        getpar(par[node]);
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int u, v, w, i = 1;
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
        edge[{min(u, v), max(u, v)}] = {w, i++};
    }
    cin >> m;
    dijkstra({0, m});
    for(i = 1; i <= n; i++)
    {
        getpar(i);
    }
    LL res = 0;
    for(auto x: used)
        res += edge[x].first;
    cout << res << "\n";
    for(auto x: used)
        cout << edge[x].second << ' ';
    return 0;
}

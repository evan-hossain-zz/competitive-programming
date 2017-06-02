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

#define MAX 1010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

struct edge{
    int v;
    LL w;
    char ch;
};
vector <edge> adj[MAX];

int trie[2000000][26], cnt[1000000*26], last;

void add(string str)
{
    int i, id, cur = 0;
    for(i = 0; i < SZ(str); i++)
    {
        id = str[i] - 'a';
        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;
            clr(trie[last], -1);
        }
        cur = trie[cur][id];
        cnt[cur]++;
    }
}
/// do clr(trie[0], -1) and last = 0 for every case

string s;

LL dist[MAX][MAX*15];

void dijkstra(int u)
{
    priority_queue <tuple<int, int, int>, vector <tuple<int, int, int>>, greater <tuple<int, int, int>>> Q;
    Q.push(make_tuple(0, u, 0));
    clr(dist, 63);
    dist[u][0] = 0;
    int d, nex, cur;
    while(!Q.empty())
    {
        u = get <1> (Q.top());
        cur = get <2> (Q.top());
        d = get <0> (Q.top());
        Q.pop();
        for(auto v: adj[u])
        {
            nex = trie[cur][v.ch-'a'];
            if(nex == -1) continue;
            LL ncost = dist[u][cur] + v.w*cnt[nex];
            if(ncost <= dist[v.v][nex])
            {
                dist[v.v][nex] = ncost;
                Q.push(make_tuple(dist[v.v][nex], v.v, nex));
            }
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, i, u , v, w;
    char ch;
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w >> ch;
        adj[u].pb({v, w, ch});
        adj[v].pb({u, w, ch});
    }
    cin >> s;
    clr(trie[0], -1);
    for(i = 0; i < SZ(s); i++)
        add(s.substr(i));
    dijkstra(1);
    LL res = 1LL<<60;
    for(i = 1; i < MAX*15; i++)
        res = min(res, dist[n][i]);
    cout << res << "\n";
    return 0;
}

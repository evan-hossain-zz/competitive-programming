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

#define MAX 2010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int indeg[MAX];
vector <int> adj[MAX];

int dfs(int node)
{
    if(indeg[node]) return 0;
    indeg[node] = 1;
    int ret = 1;
    for(int i = 0; i < SZ(adj[node]); i++)
        ret += dfs(adj[node][i]);
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, u, v, n, m, k, i, j;
    cin >> test;
    while(test--)
    {
        cin >> n >> k >> m;
        for(i = 1; i <= n; i++)
            adj[i].clear(), indeg[i] = 0;
        while(m--)
        {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
            indeg[u]++;
            indeg[v]++;
        }
        while(1)
        {
            int mn = *min_element(indeg+1, indeg+1+n);
            if(mn >= k) break;
            for(i = 1; i <= n; i++)
            {
                if(indeg[i] == mn)
                    break;
            }
            indeg[i] = infinity;
            for(j = 0; j < SZ(adj[i]); j++)
                if(indeg[adj[i][j]] != infinity)
                    indeg[adj[i][j]]--;
        }
        for(i = 1; i <= n; i++)
            if(indeg[i] != infinity)
                indeg[i] = 0;
        int res = 0;
        for(i = 1; i <= n; i++)
            res = max(res, dfs(i));
        cout << res << "\n";
    }
    return 0;
}
/*
2
5 2 6
1 2
3 2
3 4
4 5
5 2
2 4
5 3 6
1 2
3 2
3 4
4 5
5 2
2 4
*/


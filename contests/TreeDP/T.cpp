#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>

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

#define MAX 155
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int n, p, dp[MAX][MAX], child[MAX];
vector <int> adj[MAX];

int dfs(int u, int prev)
{
    int i, v, j, k;
    child[u] = 1;
    dp[u][1] = SZ(adj[u]);
    for(i = 0; i < SZ(adj[u]); i++)
    {
        v = adj[u][i];
        if(v == prev) continue;
        child[u] += dfs(v, u);
        for(j = p; j > 1; j--)
        {
            for(k = 1; k < j && k <= child[v]; k++)
                dp[u][j] = min(dp[u][j], dp[u][j-k]+dp[v][k]-2);
        }
    }
    return child[u];
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, u, v;
    cin >> n >> p;
    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    clr(dp, 63);
    dfs(1, -1);
    int res = dp[154][0];
    for(i = 1; i <= n; i++)
        res = min(res, dp[i][p]);
    cout << res << "\n";
    return 0;
}

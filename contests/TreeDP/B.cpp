#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>

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

#define MAX 110
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int dp[MAX][501], n, T, treasure[MAX];
bool hasN[MAX];
vector <pair<int,int> > adj[MAX];

void dfs(int u, int prev)
{
    int i, j, k, v, t;
//    dp[u][0] = treasure[u];
    for(i = 0; i < SZ(adj[u]); i++)
    {
        v = adj[u][i].first;
        if(v == prev) continue;
        t = adj[u][i].second;
        dfs(v, u);
        hasN[u] |= hasN[v];
        for(j = T; j >= 0; j--)
        {
            for(k = 0; k+(t*(2-hasN[v])) <= j; k++)
            {
                dp[u][j] = max(dp[u][j], dp[u][j-k-(t*(2-hasN[v]))] + dp[v][k]);
            }
            dp[u][j] += treasure[u];
        }
    }
//    for(i = 0; i <= T; i++)
//        dp[u][i] += treasure[u];
    if(SZ(adj[u]) == 1)
        dp[u][0] = treasure[u];
    hasN[u] |= u == n;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, u, v, t;
    while(scanf("%d %d", &n, &T) == 2)
    {
        for(i = 1; i <= n; i++)
            adj[i].clear(), clr(dp[i], 0), hasN[i] = 0;
        for(i = 1; i < n; i++)
        {
            scanf("%d %d %d", &u, &v, &t);
            adj[u].pb(mp(v, t));
            adj[v].pb(mp(u, t));
        }
        for(i = 1; i <= n; i++)
            scanf("%d", &treasure[i]);
        dfs(1, -1);
        printf("%d\n", dp[1][T]);
    }
    return 0;
}

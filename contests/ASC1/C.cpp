#include <bits/stdc++.h>

#define in freopen("grant.in", "r", stdin);
#define out freopen("grant.out", "w", stdout);
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

#define MAX 500010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int dp[MAX][2];
vector <int> adj[MAX], res;

int call(int u, int take)
{
    int &ret = dp[u][take], pre, v;
    if(ret != -1) return ret;
    ret = take;
    for(int i = 0; i < SZ(adj[u]); i++)
    {
        v = adj[u][i];
        ret += call(v, 0);
    }
    pre = ret;
    for(int i = 0; i < SZ(adj[u]); i++)
    {
        v = adj[u][i];
        ret = max(ret, call(v, 1)+pre-call(v, 0)-take);
    }
    return ret;
}

void go(int u, int take)
{
    int ret = take, pre;
    for(auto v: adj[u])
        ret += call(v, 0);
    if(ret == dp[u][take])
    {
        if(take)
            res.pb(u);
        for(int i = 0; i < SZ(adj[u]); i++)
        {
            int v = adj[u][i];
            go(v, 0);
        }
        return;
    }
    pre = ret;
    for(int i = 0; i < SZ(adj[u]); i++)
    {
        int v = adj[u][i];
        if(call(v, 1)+pre-call(v, 0)-take == dp[u][take])
        {
            go(v, 1);
            for(int i = 0; i < SZ(adj[u]); i++)
            {
                int vv = adj[u][i];
                if(v != vv)
                    go(vv, 0);
            }
            return;
        }
    }
}

int main()
{
        in;
        out;
    int n, i, v;
    scanf("%d", &n);
    for(i = 2; i <= n; i++)
    {
        scanf("%d", &v);
        adj[v].pb(i);
    }
    clr(dp, -1);
    printf("%d\n", call(1, 0)*1000);
    go(1,0);
    sort(all(res));
    for(int i = 0; i < SZ(res); i++)
        printf("%d ", res[i]);
    return 0;
}

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

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL ncr[MAX][30], mod = 1e9+9, poly[5], k, dp[MAX][5][22], f;
vector <int> adj[MAX];

LL call(int u, int lastPoly, int usedColor, int par)
{
    LL ret = 0, i, j;
    for(auto v: adj[u])
    {
        if(v == par) continue;
        for(i = 0; i < f; i++)
        {
            for(j = 1; j <= poly[i]; j++)
            {
                LL take = min(k, j);
                if(i == lastPoly)
                {
                    take = min(k-usedColor, j);
                    if(take)
                        ret += call(v, i, j, u) * ncr[k-usedColor][take];
                }
                else
                    ret += call(v, i, j, u) * ncr[k][take];
                ret %= mod;
            }
        }
    }
    if(SZ(adj[u]) == 1)
    {
        for(i = 0; i < f; i++)
        {
            for(j = 1; j <= poly[i]; j++)
            {
                LL take = min(k, j);
                if(i == lastPoly)
                {
                    take = min(k-usedColor, j);
                    if(take)
                        ret += ncr[k-usedColor][take];
                }
                else
                    ret += ncr[k][take];
                ret %= mod;
            }
        }
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, j, n;
    for(i = 1; i < MAX; i++)
    {
        ncr[i][1] = i;
        for(j = 2; j <= min(22, i); j++)
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])% mod;
    }
    cin >> n >> k >> f;
    for(i = 0; i < f; i++)
        cin >> poly[i];
    for(i = 1; i < n; i++)
    {
        cin >> j;
        j--;
        adj[j].pb(i);
        adj[i].pb(j);
    }
    clr(dp, -1);
    cout << call(0, -1, 0, -1);
    return 0;
}

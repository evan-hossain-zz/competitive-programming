#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#include <set>

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

#define MAX 110
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

vector <int> hor[MAX][MAX], adj[2010];
int H, V, n, m;
bool color[2010];

void dfs(int u)
{
    if(color[u])
        return;
    color[u] = 1;
    if(u < n)
        H++;
    else
        V++;
    for(int i = 0; i < SZ(adj[u]); i++)
        dfs(adj[u][i]);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, j, x, y;
    while(scanf("%d %d", &n, &m)==2 && (n|m))
    {
        for(i = 0; i < MAX; i++)
            for(j = 0; j < MAX; j++)
                hor[i][j].clear();
        int cnt = 0;
        clr(color, 0);
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            hor[x][y].pb(cnt);
            hor[x+1][y].pb(cnt++);
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            for(j = 0; j < SZ(hor[x][y]); j++)
            {
                adj[cnt].pb(hor[x][y][j]);
                adj[hor[x][y][j]].pb(cnt);
            }
            y++;
            for(j = 0; j < SZ(hor[x][y]); j++)
            {
                adj[cnt].pb(hor[x][y][j]);
                adj[hor[x][y][j]].pb(cnt);
            }
            cnt++;
        }
        int res = 0;
        for(i = 0; i < cnt; i++)
        {
            H = V = 0;
            dfs(i);
            res += max(H, V);
        }
        for(i = 0; i < cnt; i++)
            adj[i].clear();
        printf("%d\n", res);
    }
    return 0;
}
/*
3 2
1 1
0 2
2 2
1 1
2 1
*/

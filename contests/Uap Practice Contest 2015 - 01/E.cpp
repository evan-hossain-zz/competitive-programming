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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 5002
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

#define get(i, x) ((arr[i][(x)>>6]>>((x)&63))&1);
#define set(i, x) arr[i][(x)>>6]|=(1LL<<((x)&63));

vector <int> adj[MAX];
bool grid[MAX][MAX];
unsigned LL arr[MAX][MAX/64+2];
unsigned LL count_bit(unsigned LL x)
{
  x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
  x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
  x = (x & 0x0000FFFF) + ((x >> 16)& 0x0000FFFF);
  x = (x & 0xFFFFFFFF) + ((x >> 32)& 0xFFFFFFFF);
  return x;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, kase = 1, n, m, i, j, u, v;
    LL res;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);
        res = 0;
        for(i = 1; i <= n; i++)
            adj[i].clear(), clr(grid[i], 0);
        while(m--)
        {
            scanf("%d %d", &u, &v);
            grid[u][v] = grid[v][u] = 1;
        }
        for(i = 1; i <= n; i++)
        {
            for(j = i+1; j <= n; j++)
            {
                if(!grid[i][j])
                    adj[i].pb(j), adj[j].pb(i);
            }
        }
        for(i = 1; i <= n; i++)
        {
            clr(arr[i], 0);
            for(j = 0; j < SZ(adj[i]); j++)
                set(i, adj[i][j]);
        }
        for(i = 1; i <= n; i++)
        {
            for(j = i + 1; j <= n; j++)
            {
                if(grid[i][j]) continue;
                int lim = n >> 6, tem = 0, mn = min(SZ(adj[i]), SZ(adj[j]));
                for(int k = 0; k <= lim && tem < mn; k++)
                    tem += count_bit(arr[i][k] & arr[j][k]);
                res += tem;
            }
        }
        printf("Case #%d: %lld\n", kase++, res/3);
    }
    return 0;
}


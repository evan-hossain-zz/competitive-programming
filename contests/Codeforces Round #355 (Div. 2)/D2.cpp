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
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};
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

#define MAX 310
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int grid[MAX][MAX], dist[MAX][MAX], cnt[MAX*MAX], n, m, color[MAX][MAX];
vector <pair<int,int>> adj[MAX*MAX];

void go(int cur)
{
    clr(color, 0);
    queue <pair<int,int>> Q;
    for(auto u: adj[cur])
        Q.push(u), color[u.first][u.second] = dist[u.first][u.second]+1;
    while(!Q.empty())
    {
        auto u = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nr = u.first+row[i];
            int nc = u.second+col[i];
            if(nr < 0 || nr == n || nc < 0 || nc == m)
                continue;
            if(color[nr][nc] && color[nr][nc] <= color[u.first][u.second] + abs(nr-u.first) + abs(nc-u.second))
                continue;
            color[nr][nc] = color[u.first][u.second] + abs(nr-u.first) + abs(nc-u.second);
            if(grid[nr][nc] == cur+1)
            {
                dist[nr][nc] = min(dist[nr][nc], color[nr][nc]-1);
                continue;
            }
            Q.push(mp(nr, nc));
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int p, i, j, x;
    cin >> n >> m >> p;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
        {
            cin >> x;
            cnt[x]++;
            adj[x].pb(mp(i, j));
            grid[i][j] = x;
        }
    clr(dist, 63);
    for(auto x: adj[1])
        dist[x.first][x.second] = x.first + x.second;
    for(i = 1; i < p; i++)
    {
        if(1LL*cnt[i]*cnt[i+1] <= n*m)
        {
            for(auto x: adj[i])
                for(auto y: adj[i+1])
                    dist[y.first][y.second] = min(dist[y.first][y.second], dist[x.first][x.second] + abs(x.first-y.first) + abs(x.second-y.second));
        }
        else
            go(i);
    }
    int res = 1<<28;
    for(auto x: adj[p])
        res = min(res, dist[x.first][x.second]);
    cout << res;
    return 0;
}

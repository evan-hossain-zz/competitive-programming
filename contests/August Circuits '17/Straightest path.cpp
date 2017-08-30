#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>

#define in freopen("input.in", "r", stdin);
#define out freopen("output.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
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

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 1010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

string grid[MAX];
int dist[MAX][MAX][2], n, m;

bool ok(int nr, int nc, int ndir, int new_dist)
{
    if(nr >= n || nr < 0)
        return false;
    if(nc >= m || nc < 0)
        return false;
    if(grid[nr][nc] == '*')
        return false;
    return dist[nr][nc][ndir] > new_dist;
}

int get_dir(int old_dir, int r, int c, int nr, int nc)
{
    if(old_dir == 0)
    {
        if(r == nr)
            return old_dir;
        return !old_dir;
    }
    if(c == nc)
        return old_dir;
    return !old_dir;
}

void bfs(int r, int c)
{
    clr(dist[r][c], 0);
    queue <int> Q;
    Q.push(r), Q.push(c), Q.push(0); //horizontal
    Q.push(r), Q.push(c), Q.push(1); //vertical
    int i, nr, nc, dir, ndir, ndist;
    while(!Q.empty())
    {
        r = Q.front();
        Q.pop();
        c = Q.front();
        Q.pop();
        dir = Q.front();
        Q.pop();
        for(i = 0; i < 4; i++)
        {
            nr = r + row4[i];
            nc = c + col4[i];
            ndir = get_dir(dir, r, c, nr, nc);
            ndist = dist[r][c][dir] + (ndir != dir);
            if(ok(nr, nc, ndir, ndist))
            {
                dist[nr][nc][ndir] = ndist;
                Q.push(nr), Q.push(nc), Q.push(ndir);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> grid[i];
    clr(dist, 63);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] != '.' && grid[i][j] != '*')
            {
                if(dist[i][j][0] > n*m && dist[i][j][1] > n*m)
                    bfs(i, j);
                else
                    return cout << min(dist[i][j][0], dist[i][j][1]) << "\n", 0;
            }
    cout << -1;
    return 0;
}

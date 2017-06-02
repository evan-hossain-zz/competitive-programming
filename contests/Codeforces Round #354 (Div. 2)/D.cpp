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

#define MAX 1010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

char grid[4][MAX][MAX];
int dist[4][MAX][MAX];

char rot(char ch)
{
    if(ch == '-')
        return '|';
    if(ch == '|')
        return '-';
    if(ch == '^')
        return '>';
    if(ch == '>')
        return 'v';
    if(ch == '<')
        return '^';
    if(ch == 'v')
        return '<';
    if(ch == 'L')
        return 'U';
    if(ch == 'R')
        return 'D';
    if(ch == 'U')
        return 'R';
    if(ch == 'D')
        return 'L';
    return ch;
}

bool ok(int sx, int sy, int nx, int ny, int r)
{
    char dir;
    if(sx == nx)
    {
        if(sy > ny)
            dir = 'L';
        else
            dir = 'R';
    }
    else
    {
        if(sx > nx)
            dir = 'U';
        else
            dir = 'D';
    }
    char shas = grid[r][sx][sy], nhas = grid[r][nx][ny];
    if(nhas == '*')
        return false;
//    cout << "dir " << r << ' ' << sx << ',' << sy << '-' << nx << "," << ny << ' ' << shas << ' ' << nhas << ' ' << dir << endl;

    if(dir == 'L')
    {
        if(shas == '|' || shas == '^' || shas == '>' || shas == 'v' || shas == 'L')
            return false;
        if(nhas == '|' || nhas == '^' || nhas == '<' || nhas == 'v' || nhas == 'R')
            return false;
        return true;
    }
    if(dir == 'R')
    {
        if(shas == '|' || shas == '^' || shas == '<' || shas == 'v' || shas == 'R')
            return false;
        if(nhas == '|' || nhas == '^' || nhas == '>' || nhas == 'v' || nhas == 'L')
            return false;
        return true;
    }
    if(dir == 'U')
    {
        if(shas == '-' || shas == '>' || shas == '<' || shas == 'v' || shas == 'U')
            return false;
        if(nhas == '-' || nhas == '>' || nhas == '<' || nhas == '^' || nhas == 'D')
            return false;
        return true;
    }
    if(dir == 'D')
    {
//        cout << "here " << r << ' ' << sx << ',' << sy << '-' << nx << "," << ny << ' ' << shas << ' ' << nhas << endl;

        if(shas == '-' || shas == '>' || shas == '<' || shas == '^' || shas == 'D')
            return false;
        if(nhas == '-' || nhas == '>' || nhas == '<' || nhas == 'v' || nhas == 'U')
            return false;
        return true;
    }
    assert(0);
    return true;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, i, j, k, sx, sy, dx, dy;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cin >> grid[0][i][j];
            for(k = 1; k < 4; k++)
                grid[k][i][j] = rot(grid[k-1][i][j]);
        }
    }
//    cout << endl;
//    for(i = 1; i < 4; i++)
//    {
//        for(j = 0; j < n; j++)
//            cout << grid[i][j] << endl;
//        cout << endl;
//    }
    clr(dist, 63);
    cin >> sx >> sy;
    cin >> dx >> dy;
    sx--, sy--, dx--, dy--;
    queue <int> Q;
    Q.push(sx);
    Q.push(sy);
    Q.push(0);
    dist[0][sx][sy] = 0;
    int r, nr, nx, ny;
    while(!Q.empty())
    {
        sx = Q.front();
        Q.pop();
        sy = Q.front();
        Q.pop();
        r = Q.front();
        Q.pop();
        for(i = 0; i < 4; i++)
        {
            nx = sx + row[i];
            ny = sy + col[i];
            if(nx < 0 || nx == n || ny < 0 || ny == m || !ok(sx, sy, nx, ny, r) || dist[r][nx][ny] <= dist[r][sx][sy] + 1)
                continue;
//            cout << r << ' ' << sx << ',' << sy << '-' << nx << "," << ny << ' ' << grid[r][sx][sy] << ' ' << grid[r][nx][ny] << endl;
            Q.push(nx);
            Q.push(ny);
            Q.push(r);
            dist[r][nx][ny] = dist[r][sx][sy] + 1;
        }
        nr = (r+1)%4;
        if(dist[nr][sx][sy] > dist[r][sx][sy] + 1)
        {
            dist[nr][sx][sy] = dist[r][sx][sy] + 1;
            Q.push(sx);
            Q.push(sy);
            Q.push(nr);
        }
    }
    int res = infinity;
    for(i = 0; i < 4; i++)
    {
        res = min(dist[i][dx][dy], res);
//        cout << dist[i][dx][dy] << endl;
    }
    if(res >= infinity)
        res = -1;
    cout << res;
    return 0;
}

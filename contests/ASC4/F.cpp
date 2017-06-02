#include <bits/stdc++.h>

#define in freopen("straight.in", "r", stdin);
#define out freopen("straight.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp make_pair
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

#define MAX 1010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int dist[MAX][MAX];
string grid[MAX];
int n, m;
queue <int> Q;

bool ok(int r, int c, int d)
{
    if(r >= 2*n-1 || r < 0 || c >= 2*m-1 || c < 0 || !(grid[r][c] == '+' || grid[r][c] == '-' || grid[r][c] == '|'))
        return false;
    return true;
}

void update(int nr, int nc, int ndir, int r, int c, int dir)
{
    if(dist[nr][nc] > dist[r][c]+1)
    {
        dist[nr][nc] = dist[r][c]+1;
        Q.push(nr), Q.push(nc), Q.push(ndir);
    }
}

int get(int cur)
{
    clr(dist, 63);
    dist[0][2*m-2] = 0;
    Q.push(0);
    Q.push(2*m-2);
    Q.push(cur);
    int r, c, nr, nc, dir, ndir;
    while(!Q.empty())
    {
        r = Q.front();
        Q.pop();
        c = Q.front();
        Q.pop();
        dir = Q.front();
        Q.pop();
        int add = grid[r][c] == '+';
        if(dir == 0)
        {
            nr = r, nc = c+1, ndir = dir;
            if(ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
            nr = r+1, nc = c, ndir = 3;
            if(add && ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
            nr = r-1, nc = c, ndir = 1;
            if(add && ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
        }
        else if(dir == 1)
        {
            nr = r-1, nc = c, ndir = dir;
            if(ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
            nr = r, nc = c-1, ndir = 2;
            if(add && ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
            nr = r, nc = c+1, ndir = 0;
            if(add && ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
        }
        else if(dir == 2)
        {
            nr = r, nc = c-1, ndir = dir;
            if(ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
            nr = r+1, nc = c, ndir = 3;
            if(add && ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
            nr = r-1, nc = c, ndir = 1;
            if(add && ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
        }
        else
        {
            nr = r+1, nc = c, ndir = dir;
            if(ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
            nr = r, nc = c+1, ndir = 0;
            if(add && ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
            nr = r, nc = c-1, ndir = 2;
            if(add && ok(nr, nc, ndir))
                update(nr, nc, ndir, r, c, dir);
        }
    }
    return dist[2*n-2][0];
}

void forw(int &r, int &c, int cur)
{
    if(cur == 0)
        c++;
    else if(cur == 1)
        r--;
    else if(cur == 2)
        c--;
    else
        r++;
}

void lef(int &r, int &c, int cur)
{
    if(cur == 0)
        r--;
    else if(cur == 1)
        c--;
    else if(cur == 2)
        r++;
    else
        c++;
}
void rig(int &r, int &c, int cur)
{
    if(cur == 0)
        r++;
    else if(cur == 1)
        c++;
    else if(cur == 2)
        r--;
    else
        c--;
}

int main()
{
//    #ifdef Evan
        in;
        out;
//    #endif
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < 2*n-1; i++)
        getline(cin, grid[i]);
    int r, c, nr, nc, dir, ndir;
    int cur;
    if(get(2) > get(3))
        get(3);
    else
        get(2);
    r = 2*n-2, c = 0;
    int mn = dist[r][c];
    if(dist[r][c+1]+1 == mn)
        cout << "E\n", c++, cur = 0;
    else
        cout << "N\n", r--, cur = 1;
    int taken = 1;
    while(mp(r, c) != mp(0, 2*m-2))
    {
        assert(taken < mn);
        if(grid[r][c] != '+')
        {
            forw(r, c, cur);
            taken++;
            continue;
        }
        int nrf = r, ncf = c, nrr = r, ncr = c, nrl = r, ncl = c;
        forw(nrf, ncf, cur);
        rig(nrr, ncr, cur);
        lef(nrl, ncl, cur);
        if(ok(nrf, ncf, cur) && taken + 1 + dist[nrf][ncf] == mn)
        {
            cout << 'F';
            r = nrf;
            c = ncf;
            taken++;
        }
        else if(ok(nrr, ncr, cur) && taken + 1 + dist[nrr][ncr] == mn)
        {
            cout << 'R';
            r = nrr;
            c = ncr;
            taken++;
            cur = (cur+3)%4;
        }
        else
        {
            cout << 'L';
            r = nrl;
            c = ncl;
            taken++;
            cur = (cur+1)%4;
        }
    }
    return 0;
}
/*
4 4
+-+*+-+
|*|*|*|
+*+-+-+
|***|**
+-+-+-+
|*****|
+-+-+-+
4 4
+-+*+-+
|*|*|**
+*+-+-+
|***|**
+-+-+-+
|*****|
+-+-+-+
*/

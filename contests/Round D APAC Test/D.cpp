#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#define in freopen("D-large.in", "r", stdin);
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
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void show(T a){cout << a << endl;}
template <class T> void show(T a, T b){cout << a << ' ' << b << endl;}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 110
/*************************************************HABIJABI ENDS HERE******************************************************/

char grid[MAX][MAX];
int col[MAX][MAX];

bool isvalid(int r, int c)
{
    if(r > 8 || c > 8 || r < 1 || c < 1)
        return false;
    return true;
}

void downright(int r, int c)
{
    col[r][c] = 1;
    if(isvalid(r + 1, c + 1) && !grid[r][c])
        downright(r + 1, c + 1);
}
void pdownright(int r, int c)
{
    if(isvalid(r, c))
        col[r][c] = 1;
}

void downleft(int r, int c)
{
    col[r][c] = 1;
    if(isvalid(r + 1, c - 1) && !grid[r][c])
        downleft(r + 1, c - 1);
}
void pdownleft(int r, int c)
{
    if(isvalid(r, c))
        col[r][c] = 1;
}

void upright(int r, int c)
{
    col[r][c] = 1;
    if(isvalid(r - 1, c + 1) && !grid[r][c])
        upright(r - 1, c + 1);
}
void upleft(int r, int c)
{
    col[r][c] = 1;
    if(isvalid(r - 1, c - 1) && !grid[r][c])
        upleft(r - 1, c - 1);
}

char ch;

void get(int r, int c)
{
    int nr, nc, i, j;
    if(ch == 'K')
    {
        for(i = 0; i < 8; i++)
        {
            nr = r + row8[i];
            nc = c + col8[i];
            if(isvalid(nr, nc))
                col[nr][nc] = 1;
        }
    }
    if(ch == 'Q')
    {
//        cout << "ic" << endl;
        ///right
        for(i = c; i <= 8; i++)
        {
            col[r][i] = 1;
            if(grid[r][i])
                break;
        }
        ///left
        for(i = c; i > 0; i--)
        {
//            cout << r << ' ' << i << endl;
            col[r][i] = 1;
            if(grid[r][i])
                break;
        }
        ///down
        for(i = r; i <= 8; i++)
        {
            col[i][c] = 1;
            if(grid[i][c])
                break;
        }
        ///up
        for(i = r; i > 0; i--)
        {
            col[i][c] = 1;
            if(grid[i][c])
                break;
        }
        ///down right
        downright(r, c);
        ///down left
        downleft(r, c);
        ///up right
        upright(r, c);
        ///up left
        upleft(r, c);
    }
    if(ch == 'R')
    {
        ///right
        for(i = c; i <= 8; i++)
        {
            col[r][i] = 1;
            if(grid[r][i])
                break;
        }
        ///left
        for(i = c; i > 0; i--)
        {
            col[r][i] = 1;
            if(grid[r][i])
                break;
        }
        ///down
        for(i = r; i <= 8; i++)
        {
            col[i][c] = 1;
            if(grid[i][c])
                break;
        }
        ///up
        for(i = r; i > 0; i--)
        {
            col[i][c] = 1;
            if(grid[i][c])
                break;
        }
    }
    if(ch == 'B')
    {
        ///down right
        downright(r, c);
        ///down left
        downleft(r, c);
        ///up right
        upright(r, c);
        ///up left
        upleft(r, c);
    }
    if(ch == 'P')
    {
        pdownright(r + 1, c + 1);
        pdownleft(r + 1, c - 1);
    }
    if(ch == 'N')
    {
        for(i = 0; i < 8; i++)
        {
            nr = r + rr[i];
            nc = c + cc[i];
            if(isvalid(nr, nc))
                col[nr][nc] = 1;
        }
    }
}


int kill(int r, int c)
{
    int i, j, ret = 0;
    for(i = 1; i <= 8; i++)
    {
        for(j = 1; j <= 8; j++)
        {
            if(i == r && j == c || !grid[i][j])
                continue;
            clr(col, 0);
            ch = grid[i][j];
            grid[i][j] = 0;
            get(i, j);
            grid[i][j] = ch;
            ret += col[r][c];
//            cout << col[r][c] << ' ' << grid[i][j] << "KILLED" << endl;
        }
    }
    return ret;
}


int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, n, i, j, kase = 1, x, res;
    char ch, p;
    scanf("%d", &test);
    while(test--)
    {
        clr(grid, 0);
        res = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf(" %c%d-%c", &ch, &x, &p);
            grid[ch - 'A' + 1][x] = p;
//            cout << ch - 'A' + 1 << ' ' << x << ' ' << p << endl;
        }
        for(i = 1; i <= 8; i++)
        {
            for(j = 1; j <= 8; j++)
            {
                if(grid[i][j])
                {
                    res += kill(i, j);
//                    cout << grid[i][j] << ' ' << res << endl;
                }
            }
        }
        printf("Case #%d: %d\n", kase++, res);
    }
    return 0;
}




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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

string grid[110][3];
int dp[3][110][110];

void printgrid(int t)
{
    cout << "at " << t << endl;
    for(auto x: grid[t])
        cout << x << endl;
}

bool ok(int x, int y, int t)
{
    if(x < 0 || x > 2 || y >= SZ(grid[0][0]))
        return false;
    return grid[t][x][y] == '.';
}

int call(int x, int y, int t)
{
    if(y==SZ(grid[0][0])-1)
        return 1;
    int &ret = dp[x][y][t];
    if(ret != -1) return ret;
    ret = 0;
    if(ok(x, y+1, t+1))
        ret = max(ret, call(x, y + 1, t+1));
    if(ok(x - 1, y+1, t+1))
        ret = max(ret, call(x - 1, y + 1, t+1));
    if(ok(x + 1, y+1, t+1))
        ret = max(ret, call(x + 1, y + 1, t+1));
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, n, x, y, k, i, j, t;
    cin >> test;
    while(test--)
    {
        cin >> n >> k;
        for(i = 0; i < 3; i++)
        {
            cin >> grid[0][i];
            for(j = 0; j < SZ(grid[0][i]); j++)
                if(grid[0][i][j] == 's')
                    grid[0][i][j] = '.', x=i,y=j;
        }
        for(t = 1; t <= SZ(grid[0][0]); t++)
        {
//            cout << t << endl;
            for(i = 0; i < 3; i++)
            {
                grid[t][i] = grid[t-1][i].substr(2) + "..";
                if(grid[t][i][0] == '.') continue;
                j = 1;
                while(j < SZ(grid[0][0]) && grid[t][i][j] == grid[t][i][0])
                    grid[t][i][j] = '.', j++;
                grid[t][i][0] = '.';
            }
//            for(auto x:grid[t])
//                cout << x << endl;
        }
        clr(dp, -1);
        if(call(x,y,0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

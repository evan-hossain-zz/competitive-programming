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

#define MAX 510
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL dp[MAX][MAX];
char grid[MAX][MAX];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, i, j;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            cin >> grid[i][j];
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(grid[i][j] == '#') continue;
            if(grid[i-1][j] == '.')
                dp[i][j]++;
            if(grid[i][j-1] == '.')
                dp[i][j]++;
        }
    }
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            dp[i][j] += dp[i][j-1];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            dp[i][j] += dp[i-1][j];
    int q, a, b, c, d;
    cin >> q;
    while(q--)
    {
        cin >> a >> b >> c >> d;
        LL res = dp[c][d] + dp[a-1][b-1] - dp[a-1][d] - dp[c][b-1];
        for(i = b; i <= d; i++)
            res -= (grid[a-1][i] == '.') && (grid[a][i] == '.');
        for(i = a; i <= c; i++)
            res -= (grid[i][b-1] == '.') && (grid[i][b] == '.');
        cout << res << "\n";
    }
    return 0;
}

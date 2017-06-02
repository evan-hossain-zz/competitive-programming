#include <bits/stdc++.h>

#define in freopen("A-large.in", "r", stdin);
#define out freopen("output2.txt", "w", stdout);
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
#define double long double

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

#define MAX 22
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int R, C, color[MAX][MAX];
double p, q;
char arr[MAX][MAX];

double dfs(int r, int c, int baki)
{
    if(baki == 0)
        return 0;
    double ret = 0;
    for(int i = 0; i < 4; i++)
    {
        int nr = r + row[i];
        int nc = c + col[i];
        if(nr < 0 || nr == R || nc < 0 || nc == C)
            continue;
        double extra;
        if(arr[nr][nc] == 'A')
            extra = p;
        else
            extra = q;
        if(color[nr][nc])
        {
            ret = max(ret, dfs(nr, nc, baki-1) + extra*(1-extra));
            continue;
        }
        color[nr][nc] = 1;
        ret = max(ret, dfs(nr, nc, baki-1)+extra);
        color[nr][nc] = 0;
    }
    return ret;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, kase = 1, s, r, c;
    cin >> test;
    while(test--)
    {
        cin >> R >> C >> r >> c >> s;
        cin >> p >> q;
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
                cin >> arr[i][j];
        }
        cout << "Case #" << kase++ << ": " << setprecision(8) << fixed << dfs(r, c, s) << "\n";
    }
    return 0;
}

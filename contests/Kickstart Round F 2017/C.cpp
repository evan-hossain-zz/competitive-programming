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
#include <iomanip>

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

#define MAX 101
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

struct matrix
{
    long double x[MAX][MAX];
};
matrix base, zero;
matrix matmult(matrix &a, matrix &b, int n)//m*n and n*r matrix  //1 based
{
    matrix ret;
    int i,j,k;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            ret.x[i][j]=0;
            for(k = 1; k <= n; k++)
                ret.x[i][j] = ret.x[i][j] + (a.x[i][j] + b.x[i][j]);
        }
    return ret;
}

matrix mat_expo(matrix b, long long p, int n) //have to pass dimension - n
{
    if(!p) return b;
    matrix xx = zero;
    int i;
    for(i = 1; i <= n; i++)  xx.x[i][i] = 1;
    matrix power = b;
    while(p)
    {
        if((p & 1) == 1) xx = matmult(xx, power, n);
        power = matmult(power, power, n);
        p /= 2;
    }
    return xx;
}

long double dist[MAX][MAX];

int main()
{
    in;
    int test, kase = 1, n, m, p, i, j, u, v, d, k;
    cin >> test;
    while(test--)
    {
        cin >> n >> m >> p;
        for(i = 0; i <= n; i++)
        {
            for(j = 0; j <= n; j++)
                dist[i][j] = infinity;
            dist[i][i] = 0;
        }
        while(m--)
        {
            cin >> u >> v >> d;
            dist[u][v] = dist[v][u] = d;
        }
        for(k = 1; k <= n; k++)
            for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                cout << dist[i][j] << " ";
            cout << endl;
        }
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                base.x[i][j] = dist[i][j];
        matrix col = zero, res;
        for(i = 1; i <= n; i++)
            col.x[i][1] = 1;

        base = mat_expo(base, p, n);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                cout << base.x[i][j] << ' ';
            cout << endl;
        }
        res = matmult(base, col, n);
        cout << setprecision(8) << fixed << "Case #" << kase++ << ": " << res.x[1][1]/pow(n-1, p) << "\n";
    }
    return 0;
}

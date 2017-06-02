#include <bits/stdc++.h>

#define in freopen("B-small-attempt0.in", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
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

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int adj[10][10], b, m, found, cycle, color[10], kase = 1;

struct matrix
{
    LL x[10][10];
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
                ret.x[i][j] = ret.x[i][j] + (a.x[i][k] * b.x[k][j]);
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

void getRes()
{
    matrix mat, tem;
    for(int i = 1; i <= b; i++)
        for(int j = 1; j <= b; j++)
            mat.x[i][j] = adj[i][j];
    tem = mat;
    int got = 0, p = 1;
    while(p < b)
    {
        tem = mat_expo(mat, p, b);
        got += tem.x[1][b];
        p++;
    }
    if(got == m && found == 0)
    {
        cout << "Case #" << kase++ << ": POSSIBLE\n";
        for(int i = 1; i <= b; i++)
        {
            for(int j = 1; j <= b; j++)
                cout << adj[i][j];
            cout << "\n";
        }
        found = 1;
    }
}

void call(int r, int c)
{
    if(found)
        return;
    if(r > b && c > b)
    {
        getRes();
        return;
    }
    if(c > b)
    {
        call(r+1, 1);
        return;
    }
    if(r == c || r == b)
    {
        call(r, c+1);
        return;
    }
    call(r, c+1);
    if(c > r)
    {
        adj[r][c] = 1;
        call(r, c+1);
        adj[r][c] = 0;
    }
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test;
    cin >> test;
    while(test--)
    {
        cin >> b >> m;
        found = 0;
        call(1, 1);
        if(!found)
            cout << "Case #" << kase++ << ": IMPOSSIBLE\n";
    }
    return 0;
}

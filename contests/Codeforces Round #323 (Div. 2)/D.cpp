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

struct matrix
{
    LL x[101][101];
};
matrix base, zero;
matrix matmult(matrix &a, matrix &b, int n)//m*n and n*r matrix  //1 based
{
    matrix ret;
    int i,j,k;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            ret.x[i][j] = -infinity;
            for(k = 1; k <= n; k++)
                ret.x[i][j] = max(ret.x[i][j], (a.x[i][k] + b.x[k][j]));
        }
    return ret;
}

matrix mat_expo(matrix b, long long p, int n) //have to pass dimension - n
{
    if(!p) return b;
    matrix xx = zero;
    int i;
    matrix power = b;
    while(p)
    {
        if((p & 1) == 1) xx = matmult(xx, power, n);
        power = matmult(power, power, n);
        p /= 2;
    }
    return xx;
}


int arr[101];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, t, i, j, s;
    cin >> n >> t;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    for(s = 1; s <= n; s++)
    {
        for(i = 1; i <= n; i++)
        {
            if(arr[s] > arr[i])
            {
                base.x[s][i] = -infinity;
                continue;
            }
            base.x[s][i]=1;
            for(j = i-1; j ; j--)
            {
                if(arr[j] <= arr[i])
                    base.x[s][i] = max(base.x[s][i], base.x[s][j] + 1);
            }
        }
    }
    matrix tem = mat_expo(base, t, n);
    LL res = 0;
    for(i = 1; i <= n; i++)
        res = max(res, *max_element(tem.x[i]+1, tem.x[i]+n+1));
    cout << res << "\n";
    return 0;
}

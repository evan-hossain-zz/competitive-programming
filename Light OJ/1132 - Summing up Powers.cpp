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

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
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

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 60
/*************************************************HABIJABI ENDS HERE******************************************************/

struct matrix
{
    unsigned int x[MAX][MAX];
};
matrix zero, mul, res;
unsigned int ncr[MAX][MAX];

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

void get_ncr()
{
    int i, j;
    ncr[1][1] = ncr[1][0] = ncr[0][0] = 1;
    for(i = 2; i < MAX; i++)
    {
        ncr[i][1] = i;
        ncr[i][0] = 1;
        for(j = 2; j <= i; j++)
            ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
    }
}

void make_mul(int k)
{
    int i, row = 1, cur_k, org_k = k;
    mul.x[1][1] = 1;
    for(i = 2, cur_k = 0; i <= k + 2; i++, cur_k++)
        mul.x[row][i] = ncr[org_k][cur_k];
    while(k + 1)
    {
        row++;
        for(i = row, cur_k = 0; i <= org_k + 2; i++, cur_k++)
            mul.x[row][i] = ncr[k][cur_k];
        k--;
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    get_ncr();
    int test, kase = 1, i;
    LL n, k;
    unsigned int ans;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%lld %lld", &n, &k);
        if(k == 0)
            printf("Case %d: %u\n", kase++, n);
        else if(n == 1)
            printf("Case %d: 1\n", kase++);
        else
        {
            make_mul(k);
            res = mat_expo(mul, n - 1, k + 2);
            ans = 0;
            for(i = 1; i <= k + 2; i++)
                ans = ans + res.x[1][i];
            printf("Case %d: %u\n", kase++, ans);
        }
    }
    return 0;
}


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

#define MAX 1201
/*************************************************HABIJABI ENDS HERE******************************************************/

int arr[MAX], visited[MAX][MAX], cnt, weight[MAX], lis_dp[MAX][MAX], lds_dp[MAX][MAX], n;

int lis_call(int indx, int last)
{
    if(indx == n)
        return 0;
    int &ret = lis_dp[indx][last];
    if(visited[indx][last] == cnt) return ret;
    visited[indx][last] = cnt;
    ret = lis_call(indx + 1, last);
    if(last < arr[indx])
        ret = max(ret, lis_call(indx + 1, arr[indx]) + weight[indx]);
    return ret;
}

int lds_call(int indx, int last)
{
    if(indx == n)
        return 0;
    int &ret = lds_dp[indx][last];
    if(visited[indx][last] == cnt) return ret;
    visited[indx][last] = cnt;
    ret = lds_call(indx + 1, last);
    if(last > arr[indx])
        ret = max(ret, lds_call(indx + 1, arr[indx]) + weight[indx]);
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, kase = 1, i, inc, dec;
    cnt = 1;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for(i = 0; i < n; i++)
            scanf("%d", &weight[i]);
        inc = lis_call(0, 0);
        cnt++;
        dec = lds_call(0, 2000);
        cnt++;
        if(inc < dec)
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", kase++, dec, inc);
        else
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", kase++, inc, dec);
    }
    return 0;
}


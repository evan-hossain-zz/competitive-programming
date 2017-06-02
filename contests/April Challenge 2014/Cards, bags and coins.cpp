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

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
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
LL bigmod(LL B,LL P,LL M){LL R=1LL; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 110
/*************************************************HABIJABI ENDS HERE******************************************************/

LL dp[MAX][MAX], mod = 1000000009LL;
LL arr[100010], tem, cnt[MAX], M, have[MAX], ncr[MAX][MAX];

LL call(LL indx, LL modval)
{
    if(indx == M)
        return modval == 0;
    LL &ret = dp[indx][modval], i;
    if(ret != -1) return ret;
    ret = call(indx + 1, modval);
    for(i = 1; i <= have[indx]; i++)
        ret = (ret + (call(indx + 1, (modval + (i * indx)) % M) * ncr[have[indx]][i]) % mod) % mod;
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
    #endif
    LL test, q, i, cur, res, n;
    ncr[1][1] = 1;
    for(i = 2; i <= 100; i++)
    {
        ncr[i][1] = i;
        for(int j = 2; j <= i; j++)
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
    }
    scanf("%lld", &test);
    while(test--)
    {
        scanf("%lld %lld", &n, &q);
        for(i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        while(q--)
        {
            scanf("%lld", &M);
            clr(cnt, 0);
            clr(have, 0);
            for(i = 0; i < n; i++)
            {
                tem = Mod(arr[i], M);
                cnt[tem]++;
            }
            for(i = 1; i < M; i++)
            {
                cur = (lcm(i, M) / i);
                if(cnt[i] - cur > 0)
                {
                    have[i] = cur;
                    cnt[i] -= cur;
                }
                else
                {
                    have[i] = cnt[i];
                    cnt[i] = 0;
                }
            }
            clr(dp, -1);
            res = call(1, 0);
            cout << res << "res" << endl;
            for(i = 0; i < M; i++)
                res = (res * bigmod(2LL, cnt[i], mod)) % mod;
            printf("%lld\n", res);
        }
    }
    return 0;
}


/*
2
10 1
1 -1 2 -2 3 -3 4 -4 5 -5
2

8 1
2 1 2 1 2 2 2
6
*/

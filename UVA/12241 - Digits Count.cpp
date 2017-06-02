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
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define SZ(v) (int)(v.size())
#define eps 10e-7

#define F(i, n) for(i = 0; i < n; i++)

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
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 10010
/*************************************************HABIJABI ENDS HERE******************************************************/

string s;
LL dp[9][9][2];
LL zdp[9][9][2][2];
int now;
LL digits[10];

LL call(int indx, int digit, int chhoto)
{
//    cout << indx << ' ' << digit << ' ' << chhoto << endl;
    if(indx == SZ(s))
        return digit;
    LL &ret = dp[indx][digit][chhoto];
    if(ret != -1) return ret;
    ret = 0;
    int i, limit = chhoto? 9 : (s[indx] - '0');
    for(i = 0; i <= limit; i++)
        ret += call(indx + 1,digit + (i == now), i < limit || chhoto);
    return ret;
}

LL zcall(int indx, int zero, int chhoto, int start)
{
    if(indx == SZ(s))
        return zero * start;
    LL &ret = zdp[indx][zero][chhoto][start];
    if(ret != -1) return ret;
    ret = 0;
    int i, limit = chhoto? 9 : (s[indx] - '0');
    for(i = 0; i <= limit; i++)
        ret += zcall(indx + 1,zero + (!i && start), i < limit || chhoto, (i != 0) || start);
    return ret;
}

LL getzero(string ls, string us)
{
    LL up = 0, low = 0;
    if(ls != "-1")
    {
        clr(zdp, -1);
        s = ls;
        low += zcall(0, 0, 0, 0);
    }
    else
        up++;
    s = us;
    clr(zdp, -1);
    up += zcall(0, 0, 0, 0);
    return up - low;
}

int main()
{
    int i, a, b;
    LL tem, up, low;
    string ls, us;
    while(cin >> a >> b && (a || b))
    {
        ls = tostring(a - 1);
        us = tostring(b);
        digits[0] = getzero(ls, us);
        printf("%lld", digits[0]);
        for(now = 1; now < 10; now++)
        {
            low = up = 0;
            if(ls > "0")
            {
                clr(dp, -1);
                s = ls;
                low += call(0, 0, 0);
            }
            s = us;
            clr(dp, -1);
            up += call(0, 0, 0);
            digits[now] = up - low;
        }
        for(i = 1; i < 10; i++)
            printf(" %lld", digits[i]);
        printf("\n");
    }
    return 0;
}


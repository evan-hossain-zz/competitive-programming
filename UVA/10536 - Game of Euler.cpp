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

#define MAX 110
/*************************************************HABIJABI ENDS HERE******************************************************/

short dp[2][16][16][16][16];

short call(bool turn, short a, short b, short c, short d)
{
    cout << ' ' << a << ' ' << b << " " << c << ' ' << d << endl;
    if(a == 15 && b == 15 && c == 15 && d == 15)
        return false;
    short &ret = dp[turn][a][b][c][d], i;
    if(ret != -1) return !ret;
    ret = 0;
    for(i = 0; i < 4; i++)
    {
        if(a & (1 << i)) continue;
        ret |= call(!turn, a | (1 << i), b, c, d);
        if(!(b & (1 << i)))
        {
            ret |= call(!turn, a | (1 << i), b | (1 << i), c, d);
            if(!(c & (1 << i)))
                ret |= call(!turn, a | (1 << i), b | (1 << i), c | (1 << i), d);
        }
    }
    for(i = 0; i < 4; i++)
    {
        if(d & (1 << i)) continue;
        ret |= call(!turn, a, b, c, d | (1 << i));
        if(!(c & (1 << i)))
        {
            ret |= call(!turn, a, b, c | (1 << i), d | (1 << i));
            if(!(b & (1 << i)))
                ret |= call(!turn, a, b | (1 << i), c | (1 << i), d | (1 << i));
        }
    }
    if(!(a & 1))
        ret |= call(!turn, a | 1, b, c, d);
    if(!(a & 3))
        ret |= call(!turn, a | 3, b, c, d);
    if(!(a & 7))
        ret |= call(!turn, a | 7, b, c, d);
    if(!(a & 8))
        ret |= call(!turn, a | 8, b, c, d);
    if(!(a & 12))
        ret |= call(!turn, a | 12, b, c, d);
    if(!(a & 14))
        ret |= call(!turn, a | 14, b, c, d);
    if(!(b & 1))
        ret |= call(!turn, a, b | 1, c, d);
    if(!(b & 3))
        ret |= call(!turn, a, b | 3, c, d);
    if(!(b & 7))
        ret |= call(!turn, a, b | 7, c, d);
    if(!(b & 8))
        ret |= call(!turn, a, b | 8, c, d);
    if(!(b & 12))
        ret |= call(!turn, a, b | 12, c, d);
    if(!(b & 14))
        ret |= call(!turn, a, b | 14, c, d);
    if(!(c & 1))
        ret |= call(!turn, a, b, c | 1, d);
    if(!(c & 3))
        ret |= call(!turn, a, b, c | 3, d);
    if(!(c & 7))
        ret |= call(!turn, a, b, c | 7, d);
    if(!(c & 8))
        ret |= call(!turn, a, b, c | 8, d);
    if(!(c & 12))
        ret |= call(!turn, a, b, c | 12, d);
    if(!(c & 14))
        ret |= call(!turn, a, b, c | 14, d);
    if(!(d & 1))
        ret |= call(!turn, a, b, c, d | 1);
    if(!(d & 3))
        ret |= call(!turn, a, b, c, d | 3);
    if(!(d & 7))
        ret |= call(!turn, a, b, c, d | 7);
    if(!(d & 8))
        ret |= call(!turn, a, b, c, d | 8);
    if(!(d & 12))
        ret |= call(!turn, a, b, c, d | 12);
    if(!(d & 14))
        ret |= call(!turn, a, b, c, d | 14);
    for(i = 0; i < 4; i++)
    {
        if(a & (1 << i)) ret |= call(!turn, a | (1 << i), b, c, d);
        if(b & (1 << i)) ret |= call(!turn, a, b | (1 << i), c, d);
        if(c & (1 << i)) ret |= call(!turn, a, b, c | (1 << i), d);
        if(d & (1 << i)) ret |= call(!turn, a, b, c, d | (1 << i));
    }
    return !ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, i, a, b, c, d;
    scanf("%d", &test);
    char ch;
    while(test--)
    {
        a = b = c = d = 0;
        for(i = 0; i < 4; i++)
        {
            scanf(" %c", &ch);
            if(ch == 'X') a |= (1 << i);
        }
        for(i = 0; i < 4; i++)
        {
            scanf(" %c", &ch);
            if(ch == 'X') b |= (1 << i);
        }
        for(i = 0; i < 4; i++)
        {
            scanf(" %c", &ch);
            if(ch == 'X') c |= (1 << i);
        }
        for(i = 0; i < 4; i++)
        {
            scanf(" %c", &ch);
            if(ch == 'X') d |= (1 << i);
        }
        clr(dp, -1);
        cout << a << " " << b << ' ' << c << ' ' << d << endl;
        if(!call(0, a, b, c, d))
            puts("WINNING");
        else
            puts("LOSING");
    }
    return 0;
}



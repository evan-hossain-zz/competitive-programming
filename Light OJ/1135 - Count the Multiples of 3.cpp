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
#define mp(a, b) make_pair(a, b)
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

int segtree[MAX * 6][3], lazy[6 * MAX], n;

void build(int beg, int en, int cur)
{
    if(beg == en)
    {
        segtree[cur][0] = 1;
        segtree[cur][1] = segtree[cur][2] = 0;
        return;
    }
    int mid = (beg + en) / 2;
    build(beg, mid, cur * 2);
    build(mid + 1, en, cur * 2 + 1);
    for(int i = 0; i < 3; i++)
        segtree[cur][i] = segtree[cur * 2][i] + segtree[cur * 2 + 1][i];
}

void lazy_update(int L, int R, int beg, int en, int cur, int val)
{
    int i, tem[3];
    if(lazy[cur])
    {
        lazy[cur * 2] += lazy[cur];
        lazy[cur * 2] %= 3;
        lazy[cur * 2 + 1] += lazy[cur];
        lazy[cur * 2 + 1] %= 3;

        for(i = 0; i < 3; i++)
            tem[(i - lazy[cur] + 3) % 3] = segtree[cur][i];
        for(i = 0; i < 3; i++)
            segtree[cur][i] = tem[i];
        lazy[cur] = 0;
    }
    if(beg > R || en < L) return;
    if(beg >= L && en <= R)
    {
        lazy[cur * 2] += val;
        lazy[cur * 2] %= 3;
        lazy[cur * 2 + 1] += val;
        lazy[cur * 2 + 1] %= 3;

        for(i = 0; i < 3; i++)
            tem[(i - val + 3) % 3] = segtree[cur][i];
        for(i = 0; i < 3; i++)
            segtree[cur][i] = tem[i];
        return;
    }
    int mid = (beg + en) / 2;
    lazy_update(L, R, beg, mid, cur * 2, val);
    lazy_update(L, R, mid + 1, en, cur * 2 + 1, val);
    for(i = 0; i < 3; i++)
        segtree[cur][i] = segtree[cur * 2][i] + segtree[cur * 2 + 1][i];
}

int query(int L, int R, int beg, int en, int cur)
{
    int tem[3], i;
    if(lazy[cur])
    {
        lazy[cur * 2] += lazy[cur];
        lazy[cur * 2] %= 3;
        lazy[cur * 2 + 1] += lazy[cur];
        lazy[cur * 2 + 1] %= 3;

        for(i = 0; i < 3; i++)
            tem[(i - lazy[cur] + 3) % 3] = segtree[cur][i];
        for(i = 0; i < 3; i++)
            segtree[cur][i] = tem[i];
        lazy[cur] = 0;
    }
    if(beg > R || en < L)
        return 0;
    if(beg >= L && en <= R)
        return segtree[cur][0];

    int mid = (beg + en) / 2;
    return query(L, R, beg, mid, cur * 2) + query(L, R, mid + 1, en, cur * 2 + 1);
}


int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int test, i, kase = 1, q, m, a, b;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);
        clr(lazy, 0);
        build(0, n - 1, 1);
        printf("Case %d:\n", kase++);
        while(m--)
        {
            scanf("%d %d %d", &q, &a, &b);
            if(q)
                printf("%d\n", query(a, b, 0, n - 1, 1));
            else
                lazy_update(a, b, 0, n - 1, 1, 1);
        }
    }
    return 0;
}



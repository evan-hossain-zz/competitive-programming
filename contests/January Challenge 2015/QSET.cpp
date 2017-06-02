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
#define eps 1e-7

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
template <class T> void show(T a){cout << a << endl;}
template <class T> void show(T a, T b){cout << a << ' ' << b << endl;}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int segtree[MAX * 6][3], lazy[6 * MAX], arr[MAX];
string s;

void build(int beg, int en, int cur)
{
    if(beg == en)
    {
        segtree[cur][0] = arr[beg] == 0;
        segtree[cur][1] = arr[beg] == 1;
        segtree[cur][2] = arr[beg] == 2;
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
            tem[(i + lazy[cur]) % 3] = segtree[cur][i];
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
            tem[(i + val) % 3] = segtree[cur][i];
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

int query(int L, int R, int beg, int en, int cur, int q)
{
    int tem[3], i;
    if(lazy[cur])
    {
        lazy[cur * 2] += lazy[cur];
        lazy[cur * 2] %= 3;
        lazy[cur * 2 + 1] += lazy[cur];
        lazy[cur * 2 + 1] %= 3;

        for(i = 0; i < 3; i++)
            tem[(i + lazy[cur]) % 3] = segtree[cur][i];
        for(i = 0; i < 3; i++)
            segtree[cur][i] = tem[i];
        lazy[cur] = 0;
    }
    if(beg > R || en < L)
        return 0;
    if(beg >= L && en <= R)
        return segtree[cur][q];

    int mid = (beg + en) / 2;
    return query(L, R, beg, mid, cur * 2, q) + query(L, R, mid + 1, en, cur * 2 + 1, q);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int n, q, i, m, a, b;
    cin >> n >> m >> s;
    for(i = 1; i <= n; i++)
        arr[i] = (arr[i - 1] + (s[i-1] - '0')) % 3;
    build(1, n, 1);
    while(m--)
    {
        cin >> q >> a >> b;
        if(q == 1)
        {
            b %= 3;
            int has = 0, bame = 0;
            if(query(a, a, 1, n, 1, 0))
                has = 0;
            if(query(a, a, 1, n, 1, 1))
                has = 1;
            if(query(a, a, 1, n, 1, 2))
                has = 2;
            a--;
            if(query(a, a, 1, n, 1, 0))
                bame = 0;
            if(query(a, a, 1, n, 1, 1))
                bame = 1;
            if(query(a, a, 1, n, 1, 2))
                bame = 2;
            a++;
            has = (3 + has - bame) % 3;
            int val = (3 + b) - has;
            val %= 3;
//            cout << "val" << val << endl;
            lazy_update(a, n, 1, n, 1, val);
        }
        else
        {
            int has = 0, zero, one, two;
            a--;
            if(query(a, a, 1, n, 1, 0))
                has = 0;
            if(query(a, a, 1, n, 1, 1))
                has = 1;
            if(query(a, a, 1, n, 1, 2))
                has = 2;
            a++;
//            cout << "has " << has << endl;
            one = query(a, b, 1, n, 1, 1);
            two = query(a, b, 1, n, 1, 2);
            zero = b - a + 1 - one - two;
            LL tem[3];
//            cout << "before shift" << zero << ' ' << one << ' ' << two << endl;
            tem[(0 - has + 3) % 3] = zero;
            tem[(1 - has + 3) % 3] = one;
            tem[(2 - has + 3) % 3] = two;
//            cout << "values" << tem[0] << ' ' << tem[1] << ' ' << tem[2] << ' ' << has << endl;
            LL res = tem[0] * (tem[0] + 1) / 2;
            res += tem[1] * (tem[1] - 1) / 2;
            res += tem[2] * (tem[2] - 1) / 2;
            cout << res << "\n";
        }
    }
    return 0;
}

/*
7 4
1112212
2 1 7
1 4 1
2 1 7
2 3 4
*/

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

#define MAX 800010
/*************************************************HABIJABI ENDS HERE******************************************************/

int segtree[MAX*6][12], arr[MAX], n, lazy[MAX*6], shifted[10000][12];

int shift(char *str, int len)
{
    int i;
    str[len + 1] = 0;
    str[len] = str[0];
    for(i = 0; i <= len; i++)
        str[i] = str[i + 1];
    return atoi(str);
}

void build(int beg, int en, int cur)
{
    if(beg == en)
    {
        for(int i = 0; i < 12; i++)
            segtree[cur][i] = shifted[arr[beg]][i];
        return;
    }
    int i, mid = (beg + en) / 2;
    build(beg, mid, cur * 2);
    build(mid + 1, en, cur * 2 + 1);
    for(i = 0; i < 12; i++)
        segtree[cur][i] = max(segtree[cur * 2][i], segtree[cur * 2 + 1][i]);
}

void update(int L, int R, int beg, int en, int cur, int val)
{
    int temp[12], i;

    if(lazy[cur])
    {
        lazy[cur * 2] += lazy[cur];
        lazy[cur * 2] %= 12;
        lazy[cur * 2 + 1] += lazy[cur];
        lazy[cur * 2 + 1] %= 12;

        for(i = 0; i < 12; i++)
            temp[(i - lazy[cur] + 12) % 12] = segtree[cur][i];
        for(i = 0; i < 12; i++)
            segtree[cur][i] = temp[i];
        lazy[cur] = 0;
    }
    if(beg > R || en < L) return;
    if(beg >= L && en <= R)
    {
        lazy[cur * 2] += val;
        lazy[cur * 2] %= 12;
        lazy[cur * 2 + 1] += val;
        lazy[cur * 2 + 1] %= 12;

        for(i = 0; i < 12; i++)
            temp[(i - val + 12) % 12] = segtree[cur][i];
        for(i = 0; i < 12; i++)
            segtree[cur][i] = temp[i];
        return;
    }
    int mid = (beg + en) / 2;
    update(L, R, beg, mid, cur * 2, val);
    update(L, R, mid + 1, en, cur * 2 + 1, val);
    for(i = 0; i < 12; i++)
        segtree[cur][i] = max(segtree[cur * 2][i], segtree[cur * 2 + 1][i]);
}

int query(int L, int R, int beg, int en, int cur)
{
    int temp[12], i;
    if(lazy[cur])
    {
        lazy[cur * 2] += lazy[cur];
        lazy[cur * 2] %= 12;
        lazy[cur * 2 + 1] += lazy[cur];
        lazy[cur * 2 + 1] %= 12;

        for(i = 0; i < 12; i++)
            temp[(i - lazy[cur] + 12) % 12] = segtree[cur][i];
        for(i = 0; i < 12; i++)
            segtree[cur][i] = temp[i];
        lazy[cur] = 0;
    }
    if(beg > R || en < L)
        return 0;
    if(beg >= L && en <= R)
        return segtree[cur][0];

    int mid = (beg + en) / 2;
    return max(query(L, R, beg, mid, cur * 2), query(L, R, mid + 1, en, cur * 2 + 1));
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    char str[7];
    cin >> n;
    for(int i = 0, len; i < n; i++)
    {
        cin >> str;
        len = strlen(str);
        arr[i] = atoi(str);
        shifted[arr[i]][0] = arr[i];
        for(int j = 1; j < 12; j++)
        {
            if(j < len && !shifted[arr[i]][j])
                shifted[arr[i]][j] = shift(str, len);
            else
                shifted[arr[i]][j] = shifted[arr[i]][j % len];
        }
    }
    build(0, n - 1, 1);
    int m, q, a, b, val;
    cin >> m;
    while(m--)
    {
        cin >> q;
        if(q)
        {
            cin >> a >> b;
            cout << query(a, b, 0, n - 1, 1) << "\n";
        }
        else
        {
            cin >> a >> b >> val;
            val %= 12;
            update(a, b, 0, n - 1, 1, val);
        }
    }
    return 0;
}



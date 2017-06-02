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

#define MAX 1000010
/*************************************************HABIJABI ENDS HERE******************************************************/

int segtree[MAX * 4], arr[MAX], last_occurance[MAX];

void build(int l, int r, int cur)
{
    if(l == r)
    {
        segtree[cur] = last_occurance[l];
        return;
    }
    build(l, (l + r) / 2, cur * 2);
    build(((l + r) / 2) + 1, r, (cur * 2) + 1);
    segtree[cur] = min(segtree[cur * 2], segtree[(cur * 2) + 1]);
}

int query(int l, int r, int L, int R, int cur)
{
    if(r < L || l > R) return infinity;
    if(l >= L && r <= R)
        return segtree[cur];
    return min(query(l, (l + r) / 2, L, R, cur * 2),
               query(((l + r) / 2) + 1, r, L, R, (cur * 2) + 1));
}

map <int, int> mpp;

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, q, i, l, r;
    while(scanf("%d %d", &n, &q) == 2 && (n | q))
    {
        clr(last_occurance, 127);
        mpp.clear();
        for(i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        for(i = n; i > 0; i--)
        {
            if(mpp[arr[i]]) last_occurance[i] = mpp[arr[i]];
            mpp[arr[i]] = i;
        }
        build(1, n, 1);
        while(q--)
        {
            scanf("%d %d", &l, &r);
            i = query(1, n, l, r, 1);
            if(i > r)
                puts("OK");
            else
                printf("%d\n", arr[i]);
        }
        puts("");
    }
    return 0;
}



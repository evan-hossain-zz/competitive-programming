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

#define MAX 2000010
/*************************************************HABIJABI ENDS HERE******************************************************/

vector < pair <int, int> > arr;

int n, val[MAX], segtree[MAX * 4];

map <int, int> mpp;

void update(int beg, int en, int cur, int indx, int val)
{
    if(beg == en)
    {
        segtree[cur] = 1;
        return;
    }
    int mid = (beg + en) / 2;
    if(indx <= mid)
        update(beg, mid, cur * 2, indx, val);
    else
        update(mid + 1, en, cur * 2 + 1, indx, val);
    segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1];
}

int query(int beg, int en, int cur, int L, int R)
{
    if(beg > R || en < L) return 0;
    if(beg >= L && en <= R)
        return segtree[cur];
    int mid = (beg + en) / 2;
    return query(beg, mid, cur * 2, L, R) +
           query(mid + 1, en, cur * 2 + 1, L, R);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    cin >> n;
    int i;
    for(i = 1; i <= n; i++)
        cin >> val[i];
    for(i = 1; i <= n; i++)
    {
        mpp[val[i]]++;
        arr.pb(make_pair(mpp[val[i]], i));
    }
    mpp.clear();
    for(i = n; i > 0; i--)
    {
        mpp[val[i]]++;
        arr.pb(make_pair(mpp[val[i]], n + i));
    }
    sort(all(arr));
    LL res = 0;
    for(i = 0; i < SZ(arr); i++)
    {
        if(arr[i].second <= n)
            res += query(1, n, 1, arr[i].second + 1, n);
        else
            update(1, n, 1, arr[i].second - n, 1);
    }
    cout << res << endl;
    return 0;
}



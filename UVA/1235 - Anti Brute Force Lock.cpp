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
#define fast_input_output ios_base::sync_with_stdio(0);cin.tie(0);
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

struct point{LL x, y;};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> LL getdist(T a, T b){return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 10010
/*************************************************HABIJABI ENDS HERE******************************************************/

struct edge
{
    int u, v, w;
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> e;
int par[MAX], d[MAX];
string arr[MAX];

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

int dist(string a, string b)
{
    int k, ret = 0, tem;
    for(k = 0; k < 4; k++)
    {
        tem = (int) abs(a[k] - b[k]);
        tem = min(tem, '9' - max(a[k], b[k]) + 1 + min(a[k] - '0', b[k] - '0'));
        ret += tem;
    }
    return ret;
}

int mst(int n)
{
    int cnt = n - 1, i, ret = 0;
    sort(e.begin(), e.end());
    for(i = 0; i < e.size() && cnt; i++)
    {
        int u = find_set(e[i].u);
        int v = find_set(e[i].v);
        if(u != v)
        {
            par[u] = v;
            ret += e[i].w;
            cnt--;
        }
    }
    return ret;
}


int main()
{
    int i, test, j, k, c, ta, tb, n, add;
    string a, b;
    cin >> test;
    clr(d, -1);
    d[0] = 0;
    while(test--)
    {
        e.clear();
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> arr[i];
            add = dist("0000", arr[i]);
            for(j = 0; j < i; j++)
            {
                a = arr[i], b = arr[j];
                ta = tb = 0;
                for(k = 0; k < 4; k++)
                {
                    ta = ta * 10 + (a[k] - '0');
                    tb = tb * 10 + (b[k] - '0');
                }
                c = dist(a, b);
                if(d[ta] == -1) d[ta] = dist("0000", a);
                if(d[tb] == -1) d[tb] = dist("0000", b);
                add = min(add, min(d[ta], d[tb]));
                e.pb(edge(ta, tb, c));
                e.pb(edge(tb, ta, c));
                par[ta] = ta;
                par[tb] = tb;
            }
        }
        cout << mst(n) + add << '\n';
    }
    return 0;
}

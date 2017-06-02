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

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

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

#define MAX 205
/*************************************************HABIJABI ENDS HERE******************************************************/

struct edge
{
    int u, v, w, indx;
    edge(int a, int b, int c, int i)
    {
        u = a;
        v = b;
        w = c;
        indx = i;
    }
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> e;
int par[MAX], baad[MAX], best, second;

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

int mst(int n, int sec)
{
    int ret = 0, cnt = n - 1, i;
    for(i = 0; i <= n; i++)
        par[i] = i;
    for(i = 0; i < e.size() && cnt; i++)
    {
        if(baad[e[i].indx] == 1) continue;
        int u = find_set(e[i].u);
        int v = find_set(e[i].v);
        if(u != v)
        {
            par[u] = v;
            ret += e[i].w;
            if(!sec)
                baad[e[i].indx] = 0;
            cnt--;
        }
    }
    return cnt? -1 : ret;
}

int main()
{
    fast_input_output
    int n, m, i, test, c, a, b, kase = 1;
    cin >> test;
    while(test--)
    {
        e.clear();
        second = infinity;
        clr(baad, -1);
        cin >> n >> m;
        for(i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            e.pb(edge(a, b, c, i));
            e.pb(edge(b, a, c, i));
        }
        sort(e.begin(), e.end());
        best = mst(n, 0);
        for(i = 0; i < m; i++)
        {
            if(baad[i] == -1) continue;
            baad[i] = 1;
            c = mst(n, 1);
            if(c != -1) second = min(c, second);
            baad[i] = 0;
        }
        if(best == -1)
            cout << "Case #" << kase++ << " : No way\n";
        else if(second >= infinity)
            cout << "Case #" << kase++ << " : No second way\n";
        else
            cout << "Case #" << kase++ << " : " << second << "\n";
    }
    return 0;
}

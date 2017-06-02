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

#define MAX 200010
/*************************************************HABIJABI ENDS HERE******************************************************/

int par[MAX], dist[MAX], max_dist, far_node;
vector <int> adj[MAX];

int find_par(int node)
{
    if(node == par[node])
        return node;
    return par[node] = find_par(par[node]);
}

void dfs(int node, int par, int d)
{
    if(d > max_dist)
    {
        max_dist = d;
        far_node = node;
    }
    int i;
    for(i = 0; i < SZ(adj[node]); i++)
    {
        if(adj[node][i] == par) continue;
        dfs(adj[node][i], node, d + 1);
    }
}

int find_dist(int node)
{
    max_dist = -1;
    dfs(node, -1, 0);
    max_dist = -1;
    dfs(far_node, -1, 0);
    return max_dist;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int n, m, q, a, b, i, tem;
    cin >> n >> m >> q;
    for(i = 0; i <= n; i++)
        par[i] = i;
    while(m--)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        a = find_par(a);
        b = find_par(b);
        if(a != b)
        {
            par[a] = b;
        }
    }
    for(i = 1; i <= n; i++)
        if(par[i] == i) dist[i] = find_dist(i);
    while(q--)
    {
        cin >> m;
        if(m == 1)
        {
            cin >> a;
            a = find_par(a);
            cout << dist[a] << endl;
        }
        else
        {
            cin >> a >> b;
            a = find_par(a);
            b = find_par(b);
            if(a != b)
            {
                int x = dist[find_par(a)];
                int y = dist[find_par(b)];
                tem = max(x, y);
                tem = max(tem, (x + 1) / 2 + (y + 1) / 2 + 1);
                dist[a] = tem;
                dist[b] = tem;
                par[a] = b;
            }
        }
    }
    return 0;
}



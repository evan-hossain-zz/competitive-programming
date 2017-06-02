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

#define MAX 255
/*************************************************HABIJABI ENDS HERE******************************************************/

int route[MAX][MAX], d[MAX], n, c, k, rcost[MAX];

struct edge
{
    int city, cost;
    edge(){};
    edge(int ct, int co)
    {
        city = ct;
        cost = co;
    }
    bool operator < (const edge &p) const
    {
        return p.cost < cost;
    }
};

vector <edge> adj[MAX];
priority_queue <edge> Q;

void init(void)
{
    for(int i = 0; i <= n; i++)
    {
        adj[i].clear();
        d[i] = infinity;
    }
}

void dijkstra(void)
{
    edge u, v;
    int ucost, vcost, i;
    Q.push(edge(k, 0));
    d[k] = 0;
    while(!Q.empty())
    {
        u = Q.top(), Q.pop();
        ucost = d[u.city];
        for(i = 0; i < SZ(adj[u.city]); i++)
        {
            v = adj[u.city][i];
            vcost = ucost + v.cost;
            if(v.city >= 0 && v.city < c)
            {
                d[c - 1] = min(d[c - 1], rcost[v.city] + vcost);
                continue;
            }
            if(d[v.city] > vcost)
            {
                d[v.city] = vcost;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int m, a, b, cost;
    while(scanf("%d %d %d %d", &n, &m, &c, &k) == 4 && (n || m || c || k))
    {
        init();
        while(m--)
        {
            scanf("%d %d %d", &a, &b, &cost);
            adj[a].pb(edge(b, cost));
            adj[b].pb(edge(a, cost));
            route[a][b] = route[b][a] = cost;
        }
        rcost[c - 1] = 0;
        for(int i = c - 1 - 1; i >= 0; i--)
            rcost[i] = route[i][i + 1] + rcost[i + 1];
        dijkstra();
        printf("%d\n", d[c - 1]);
    }
    return 0;
}


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

#define MAX 10010
/*************************************************HABIJABI ENDS HERE******************************************************/

int level[MAX], pwr[MAX][15], dist[MAX];
bool color[MAX];
struct info{
    int node, cost;
    info(int n, int c)
    {
        node = n;
        cost = c;
    }
};
vector <info> adj[MAX];
queue <int> Q;

void bfs(void)
{
    Q.push(1);
    clr(color, 0);
    color[1] = 1;
    level[1] = 0;
    dist[1] = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int elements = adj[u].size(), v, c;
        for(int i = 0; i < elements; i++)
        {
            v = adj[u][i].node;
            c = adj[u][i].cost;
            if(color[v]) continue;
            color[v] = 1;
            level[v] = level[u] + 1;
            dist[v] = c + dist[u];
            pwr[v][0] = u;
            Q.push(v);
        }
    }
}

void process(int n)
{
    int h, i, lev;
    h = log2(n) + 1;

    for(lev = 1; lev <= h; lev++)
    {
        for(i = 1; i <= n; i++)
        {
            if(pwr[i][lev - 1] != -1)
                pwr[i][lev] = pwr[pwr[i][lev - 1]][lev - 1];
        }
    }
}

int lca(int high, int low)
{
    if(level[low] < level[high]) swap(low, high);
    int h, i, diff;
    h = log2(level[low]) + 1;
    diff = level[low] - level[high];
    for(i = 0; i <= h; i++)
        if(diff & (1 << i))
            low = pwr[low][i];
    if(low == high) return low;
    for(i = h; i >= 0; i--)
    {
        if(pwr[low][i] != -1 && pwr[low][i] != pwr[high][i])
        {
            low = pwr[low][i];
            high = pwr[high][i];
        }
    }
    return pwr[low][0];
}

int get_kth(int u, int v, int k)
{
    int meet = lca(u, v);
    if(level[u] - level[meet] == k - 1)
        return meet;
    int laaf = 0, h, i;
    if(level[u] - level[meet] >= k)
    {
        h = log2(level[u]) + 1;
        for(i = h; i >= 0; i--)
        {
            if(laaf + (1 << i) <= k - 1)
                u = pwr[u][i], laaf += (1 << i);
        }
        return u;
    }
    k -= (level[u] - level[meet] + 1);
    int baki = level[v] - level[meet] - k;
    h = log2(level[v]) + 1;
    for(i = h; i >= 0; i--)
    {
        if(laaf + (1 << i) <= baki)
            v = pwr[v][i], laaf += (1 << i);
    }
    return v;
}

int main()
{
    #ifdef Evan
        in;
    #endif
    int test, i, n, u, v, cost;
    char str[5];
    scanf("%d", &test);
    while(test--)
    {
        clr(pwr, -1);
        scanf("%d", &n);
        for(i = 1; i <= n; i++) adj[i].clear();
        for(i = 1; i < n; i++)
        {
            scanf("%d %d %d", &u, &v, &cost);
            adj[u].pb(info(v, cost));
            adj[v].pb(info(u, cost));
        }
        bfs();
        process(n);
        while(scanf(" %s", str) && strcmp(str, "DONE"))
        {
            if(strcmp(str, "DIST") == 0)
            {
                scanf("%d %d", &u, &v);
                cost = lca(u, v);
                printf("%d\n", dist[u] + dist[v] - 2 * dist[cost]);
            }
            else
            {
                scanf("%d %d %d", &u, &v, &cost);
                printf("%d\n", get_kth(u, v, cost));
            }
        }
        puts("");
    }
    return 0;
}


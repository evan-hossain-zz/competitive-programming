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
#define infinity (1 << 20)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
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

#define MAX 1010
/*************************************************HABIJABI ENDS HERE******************************************************/

struct edge
{
    int u, v, w;
    edge();
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};

vector <edge> graph;
vector <int> ulta[MAX], ans;
bool col[MAX];

void dfs(int node)
{
    col[node] = 1;
    ans.pb(node);
    for(int i = 0; i < SZ(ulta[node]); i++)
    {
        if(!col[ulta[node][i]])
            dfs(ulta[node][i]);
    }
}

int dist[MAX], n, m;
void belford(void)
{
    int i, j, u, v, w;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            u = graph[j].u;
            v = graph[j].v;
            w = graph[j].w;
            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    for(j = 0; j < m; j++)
    {
        u = graph[j].u;
        v = graph[j].v;
        w = graph[j].w;
        if(dist[u] + w < dist[v])
            if(!col[u]) dfs(u);
    }
}


int main()
{
    int test, i, a, b, c, kase = 1;
    scanf("%d", &test);
    while(test--)
    {
        graph.clear();
        ans.clear();
        clr(col, 0);
        scanf("%d %d", &n, &m);
        for(i = 0; i <= n; i++) dist[i] = infinity, ulta[i].clear();
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            ulta[b].pb(a);
            graph.pb(edge(b, a, c));
        }
        belford();
        printf("Case %d:", kase++);
        if(ans.empty())
        {
            puts(" impossible");
            continue;
        }
        n = SZ(ans);
        sort(all(ans));
        for(i = 0; i < n; i++)
            printf(" %d", ans[i]);
        puts("");
    }
    return 0;
}



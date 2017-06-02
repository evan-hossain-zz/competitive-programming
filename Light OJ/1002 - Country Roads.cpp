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
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int par[550], khoroch[550][550];

struct edge
{
    int u, v, w;
    bool operator < (const edge &p) const
    {
        return p.w > w;
    }
};

vector <edge> roads;
vector <int> adj[550];

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}
void mst(int n)
{
    sort(roads.begin(), roads.end());
    int elements = roads.size();
    for(int i = 0; i < elements; i++)
    {
        int u = find_set(roads[i].u);
        int v = find_set(roads[i].v);
        if(u == v)
            continue;
        par[u] = v;
        adj[roads[i].u].pub(roads[i].v), adj[roads[i].v].pub(roads[i].u);
        khoroch[roads[i].u][roads[i].v] = khoroch[roads[i].v][roads[i].u] = roads[i].w;
    }
}
void dfs(int node, int maxtillnow)
{
    int i, elements = adj[node].size();
    for(i = 0; i < elements; i++)
    {
        int to = adj[node][i];
        if(par[to] == -1)
        {
            par[to] = max(maxtillnow, khoroch[node][to]);
            dfs(to, par[to]);
        }
    }
}
int main()
{
    int test, kase, i, j, n, m, a, b, w, start;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        roads.clear();
        memset(khoroch, 0, sizeof khoroch);
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++) par[i] = i, adj[i].clear();
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &w);
            roads.pub(edge{a, b, w});
        }
        mst(n);
        memset(par, -1, sizeof par);
        scanf("%d", &start);
        par[start] = 0;
        dfs(start, 0);
        printf("Case %d:\n", kase);
        for(i = 0; i < n; i++)
        {
            if(par[i] == -1)
                printf("Impossible\n");
            else
                printf("%d\n", par[i]);
        }
    }
    return 0;
}


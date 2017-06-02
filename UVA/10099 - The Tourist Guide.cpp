#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w > p.w;
    }
};

int find_set(int node);
void mst(int n);
void dfs(int x);

vector <edge> e;
vector <int> vc[110];
int path[110][110];
int par[110], y, s, en;

int main()
{
    int n, r, i, jon, kase = 0, j;
    edge t;
    while(scanf("%d %d", &n, &r) == 2 && (n | r))
    {
        for(i = 1; i <= n; i++)
            par[i] = i;
        for(i = 0; i < r; i++)
        {
            scanf("%d %d %d", &t.u, &t.v, &j);
            t.w = j - 1;
            e.pub(t);
        }
        scanf("%d %d %d", &s, &en, &jon);
        mst(n);
        printf("Scenario #%d\n", ++kase);
        if(jon % y == 0)
            printf("Minimum Number of Trips = %d\n\n", jon / y);
        else
            printf("Minimum Number of Trips = %d\n\n", jon / y + 1);
        for(i = 0; i <= n; i++)
        {
            for(j = 0; j <= n; j++)
                path[i][j] = 0;
            vc[i].clear();
        }
        e.clear();
    }
    return 0;
}

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

void mst(int n)
{
    int i;
    int cnt = n - 1;
    sort(e.begin(), e.end());
    for(i = 0; i < e.size() && cnt; i++)
    {
        int u = find_set(e[i].u);
        int v = find_set(e[i].v);
        if(u != v)
        {
            par[u] = v;
            path[u][v] = path[v][u] = e[i].w;
            vc[u].pub(v);
            vc[v].pub(u);
            cnt--;
        }
    }
    y = 1 << 31;
    y--;
    if(s != en)
        dfs(s);
}

void dfs(int x)
{
    int p;
    for(p = 0; p < vc[x].size(); p++)
    {
        if(path[x][vc[x][p]])
        {
            y = min(y, path[x][vc[x][p]]);
            path[x][vc[x][p]] = path[vc[x][p]][x] = 0;
            if(vc[x][p] == en)
                return;
            else
                dfs(vc[x][p]);
        }
    }
}

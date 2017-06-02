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
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 3003

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

bool artipoints[SZ], visited[SZ];
int discovered[SZ], backedge[SZ], prdfn, child;

vector <int> adj[SZ];

void dfs(int u, int parent);

int main()
{
    int n, m, k, i, j, cnt, test, a, b;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d", &n, &m, &k);
        prdfn = child = cnt = 0;
        for(i = 0; i < n; i++)
            artipoints[i] = visited[i] = 0;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].pub(b);
            adj[b].pub(a);
        }
        dfs(0, -1);
        for(i = 0; i < n; i++)
        {
            if(artipoints[i])
                cnt++;
            adj[i].clear();
        }
        printf("%d\n", cnt * k);
    }
    return 0;
}

void dfs(int u, int parent)
{
    visited[u] = true;
    artipoints[u] = false;
    prdfn++;
    discovered[u] = backedge[u] = prdfn;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == parent) continue;
        if(!visited[v])
        {
            dfs(v, u);
            if(parent == -1)
            {
                child++;
                if(child >= 2)
                    artipoints[u] = 1;
            }
            else
            {
                backedge[u] = min(backedge[u], backedge[v]);
                if(backedge[v] >= discovered[u])
                    artipoints[u] = 1;
            }
        }
        else
            backedge[u] = min(discovered[v], backedge[u]);
    }
}

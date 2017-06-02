#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 10010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;
pair <int, int> pr;
vector <pair <int, int> > bridges;
vector <int> adj[SZ];
int discover[SZ], bedge[SZ], discovery_time;

void dfs_bridge(int node, int from)
{
    discover[node] = bedge[node] = discovery_time++;
    int i, connected = adj[node].size(), to;
    for(i = 0; i < connected; i++)
    {
        to = adj[node][i];
        if(to == from) continue;
        if(!discover[to])
        {
            dfs_bridge(to, node);
            bedge[node] = min(bedge[node], bedge[to]);
            if(bedge[to] > discover[node])
            {
                if(node < to)
                    pr = make_pair(node, to);
                else
                    pr = make_pair(to, node);
                bridges.pub(pr);
            }
        }
        else if(discover[node] > discover[to])
            bedge[node] = min(discover[to], bedge[node]);
    }
}

int main()
{
    int kase, test, i, n, m, j, b, a;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        discovery_time = 0;
        memset(discover, 0, sizeof discover);
        memset(bedge, 0, sizeof bedge);
        bridges.clear();
        scanf("%d", &n);
        for(i = 0; i <= n; i++)
            adj[i].clear();
        for(i = 0; i < n; i++)
        {
            scanf(" %d (%d)", &a, &m);
            for(j = 0; j < m; j++)
            {
                scanf("%d", &b);
                adj[a].pub(b);
            }
        }
        for(i = 0; i < n; i++)
        {
            if(!discover[i])
                dfs_bridge(i, -1);
        }
        b = bridges.size();
        printf("Case %d:\n", kase);
        printf("%d critical links\n", b);
        sort(bridges.begin(), bridges.end());
        for(i = 0; i < b; i++)
            printf("%d - %d\n", bridges[i].first, bridges[i].second);
    }
    return 0;
}

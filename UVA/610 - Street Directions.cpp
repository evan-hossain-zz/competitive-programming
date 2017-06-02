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
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 1010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <int> adj[SZ];
int discovery_time[SZ], bedge[SZ], T;

void find_bridge(int node, int parent)
{
    discovery_time[node] = bedge[node] = ++T;
    int to, i, connected = adj[node].size();
    for(i = 0; i < connected; i++)
    {
        to = adj[node][i];
        if(to == parent) continue;
        if(!discovery_time[to])
        {
            printf("%d %d\n", node, to);
            find_bridge(to, node);
            bedge[node] = min(bedge[node], bedge[to]);
            if(bedge[to] > discovery_time[node])
                printf("%d %d\n", to, node);
        }
        else if(discovery_time[node] > discovery_time[to])
        {
            printf("%d %d\n", node, to);
            bedge[node] = min(bedge[node], discovery_time[to]);
        }
    }
}

int main()
{
    int n, m, i, kase = 1, a, b;
    while(scanf("%d %d", &n, &m) == 2 && (n | m))
    {
        T = 0;
        for(i = 0; i <= n; i++)
            discovery_time[i] = bedge[i] = 0, adj[i].clear();
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].pub(b);
            adj[b].pub(a);
        }
        printf("%d\n\n", kase++);
        find_bridge(1, -1);
//        n = bridge.size();
//        for(i = 0; i < n; i++)
//            printf("%d %d\n", bridge[i].a, bridge[i].b);
        printf("#\n");
    }
    return 0;
}

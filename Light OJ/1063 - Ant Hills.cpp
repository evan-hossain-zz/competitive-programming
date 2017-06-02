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
#define clr(arr, key) memset(arr, key, sizeof arr)
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 10010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;
vector <int> adj[SZ];
int discover[SZ], bedge[SZ], discovery_time;
bool arti[SZ];

void dfs_artpoint(int node, int from)
{
    arti[node] = false;
    discover[node] = bedge[node] = discovery_time++;
    int i, connected = adj[node].size(), to, child = 0;
    for(i = 0; i < connected; i++)
    {
        to = adj[node][i];
        if(to == from) continue;
        if(!discover[to])
        {
            dfs_artpoint(to, node);
            child++;
            bedge[node] = min(bedge[node], bedge[to]);
            if(bedge[to] >= discover[node] && from != -1)
                arti[node] = true;
        }
        else if(discover[node] > discover[to])
            bedge[node] = min(discover[to], bedge[node]);
    }
    if(from == -1 && child >= 2)
        arti[node] = true;
}

int main()
{
    int n, m, i, j, kase, test, a, b, hills;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
//        clr(discover, 0);
//        clr(bedge, 0);
        discovery_time = 1;
        hills = 0;
        scanf("%d %d", &n, &m);
        for(i = 1; i <= n; i++)
            adj[i].clear(), discover[i] = bedge[i] = 0;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].pub(b), adj[b].pub(a);
        }
        dfs_artpoint(1, -1);
        for(i = 1; i <= n; i++)
            if(arti[i]) hills++;
        printf("Case %d: %d\n", kase, hills);
    }
}

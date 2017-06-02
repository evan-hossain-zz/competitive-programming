#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
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
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int level[SZ], node_value[SZ], pwr[SZ][25];
vector <int> adj[SZ];
queue <int> Q;

void bfs(void)
{
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int elements = adj[u].size();
        for(int i = 0; i < elements; i++)
        {
            int v = adj[u][i];
            level[v] = level[u] + 1;
            Q.push(v);
        }
    }
}
void process(int n)
{
    int h, lev, i;
    for(h = 1; (1 << h) < n; h++);
    for(lev = 1; lev <= h; lev++)
    {
        for(i = 0; i < n; i++)
        {
            if(pwr[i][lev - 1] != -1)
                pwr[i][lev] = pwr[pwr[i][lev - 1]][lev - 1];
        }
    }
}
int query(int low, int value)
{
    int h, i;
    for(h = 1; (1 << h) < level[low]; h++);
    for(i = h; i >= 0; i--)
    {
        if(node_value[pwr[low][i]] >= value)
            low = pwr[low][i];
    }
    return low;
}

int main()
{
    int n, q, i, j, test, kase, a, b;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        level[0] = 0;
        memset(pwr, -1, sizeof pwr);
        scanf("%d %d", &n, &q);
        for(i = 0; i <= n; i++) adj[i].clear();
        for(i = 1; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].pub(i);
            pwr[i][0] = a;
            node_value[i] = b;
        }
        Q.push(0);
        bfs();
        process(n);
        node_value[0] = 1;
        printf("Case %d:\n", kase);
        for(i = 0; i < q; i++)
        {
            scanf("%d %d", &a, &b);
            printf("%d\n", query(a, b));
        }
    }
    return 0;
}


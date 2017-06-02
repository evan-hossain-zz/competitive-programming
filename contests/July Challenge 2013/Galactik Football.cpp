#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
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

vector <int> adj[SZ];
stack <int> S;
int col[SZ], dis[SZ], low[SZ], timer, n, m, components;
LL mx, tax[SZ], group_cost[SZ];

void scc(int u)
{
    col[u] = 1;
    low[u] = dis[u] = timer++;
    S.push(u);
    int i, v, tem, elements = adj[u].size();
    for(i = 0; i < elements; i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], dis[v]);
        else if(col[v] == 0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==dis[u])
    {
        do
        {
            tem = S.top();
            S.pop();
            if(tax[tem] >= 0)
                group_cost[components] = min(tax[tem], group_cost[components]);
            col[tem]=2;
        }
        while(tem != u);
        components++;
    }
}

void tarjan(void)
{
    timer = components = 1;
    while(!S.empty()) S.pop();
    for(int i = 1; i <= n; i++)
    {
        if(col[i] == 0)
            scc(i);
    }
    return;
}

bool check_connections(void)
{
    int i;
    mx = 0;
    for(i = 1; i < components && components > 2; i++)
    {
        if(group_cost[i] == infinity)
            return false;
    }
    sort(group_cost + 1, group_cost + (LL) components);
    for(i = 2; i < components; i++)
        mx += group_cost[1] + group_cost[i];
    return true;
}

int main()
{
    int i, j, a, b;
    while(scanf("%d %d", &n, &m) == 2)
    {
        clr(col, 0);
        for(i = 1; i <= n; i++)
        {
            group_cost[i] = infinity;
            adj[i].clear();
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].pub(b);
            adj[b].pub(a);
        }
        for(i = 1; i <= n; i++)
            scanf("%lld", &tax[i]);
        tarjan();
        if(check_connections())
            printf("%lld\n", mx);
        else
            printf("-1\n");
    }
    return 0;
}


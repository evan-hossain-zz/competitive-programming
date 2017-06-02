int level[MAX], dp[MAX][LN];
vector <int> adj[MAX];

void dfs(int node, int prev)
{
    dp[node][0] = prev;
    level[node] = prev == -1? 0 : level[prev]+1;
    for(int i = 0; i < SZ(adj[node]); i++)
        if(adj[node][i] != prev)
            dfs(adj[node][i], node);
}

void process(int n)
{
    dfs(1, -1);
    int i, lev;
    for(lev = 1; lev < LN; lev++)
    {
        for(i = 1; i <= n; i++)
        {
            if(dp[i][lev - 1] != -1)
                dp[i][lev] = dp[dp[i][lev - 1]][lev - 1];
        }
    }
}

int lca(int high, int low)
{
    if(level[low] < level[high]) swap(low, high);
    int i, diff;
    diff = level[low] - level[high];
    for(i = 0; i < LN; i++)
        if(diff & (1 << i))
            low = dp[low][i];
    if(low == high) return low;
    for(i = LN-1; i >= 0; i--)
    {
        if(dp[low][i] != -1 && dp[low][i] != dp[high][i])
        {
            low = dp[low][i];
            high = dp[high][i];
        }
    }
    return dp[low][0];
}

int main()
{
    int n, m, i, j, q;
    while(cin >> n >> m && (n | m))
    {
        memset(dp, -1, sizeof dp);
        for(i = 0; i < m; i++)
        {
            cin >> j >> q;
            adj[j].pub(q);
            adj[q].pub(j);
        }
        process(n);
        cin >> q;
        for(i = 0; i < q; i++)
        {
            cin >> n >> m;
            cout << lca(n, m) << endl;
        }
    }
    return 0;
}


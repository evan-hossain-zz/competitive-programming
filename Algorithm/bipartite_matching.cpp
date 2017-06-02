int par[MAX];
bool col[MAX];
int MAX_BMP(int n) // finds maximum possible bipartite matching
{
    int ret = 0, i;
    clr(par, -1);
    for(i = 0; i < n; i++)
    {
        clr(col, 0);
        if(dfs(i)) ret++;
    }
    return ret;
}
int dfs(int u)
{
    if(col[u])
        return false;
    col[u] = true;
    for(int i = 0; i < SZ(adj[u]); i++)
    {
        int v = adj[u][i];
        if(par[v] == -1 || dfs(par[v]))
        {
            par[v] = u;
            return true;
        }
    }
    return false;
}


int low[MAX], tim[MAX], col[MAX], no_of_component, n, timer, group_id[MAX];
vector <int> adj[MAX], dag[MAX];
stack <int> st;
void scc(int u)
{
    low[u] = tim[u] = timer++;
    col[u] = 1;
    st.push(u);
    int i, elements = adj[u].size(), v, tem;
    for(i = 0; i < elements; i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tim[v]);
        else if(col[v] == 0)
        {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == tim[u])
    {
        do
        {
            tem = st.top();
            st.pop();
            group_id[tem]=no_of_component;
            col[tem] = 2;
        }
        while(tem != u);
        no_of_component++;
    }
}
void call_for_scc_check()
{
    no_of_component = timer = 0;
    clr(col, 0);
    int i;
    while(!st.empty()) st.pop();
    for(i = 0; i < n; i++)
    {
        if(col[i] == 0)
            scc(i);
    }
}

void make_new_DAG()
{
    int i,j,u,v;

    for(i = 0; i < no_of_component; i++) dag[i].clear();

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < SZ(adj[i]); j++)
        {
            u=group_id[i];
            v=group_id[adj[i][j]];
            if(u!=v)
                dag[u].pb(v);
        }
    }
}

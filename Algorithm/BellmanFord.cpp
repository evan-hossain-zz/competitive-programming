struct edge
{
    int u, v, w;
    edge();
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};

vector <edge> graph;
vector <int> adj[MAX];

int dist[MAX], n, m;

///graph is a vector of edges
bool belford(void)
{
    for(i = 1; i <= n; i++) dist[i] = infinity;
        dist[0] = 0;
    int i, j, u, v, w;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            u = graph[j].u;
            v = graph[j].v;
            w = graph[j].w;
            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    for(j = 0; j < m; j++)
    {
        u = graph[j].u;
        v = graph[j].v;
        w = graph[j].w;
        if(dist[u] + w < dist[v])
            return true;
    }
    return false;
}


int main()
{
    int test, i, a, b, c, kase = 1;
    scanf("%d", &test);
    while(test--)
    {
        graph.clear();
        ans.clear();
        scanf("%d %d", &n, &m);
        for(i = 1; i <= n; i++) adj[i].clear();
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            adj[a].pb(b);
            graph.pb(edge(a, b, c));
        }
        if(belford())
            cout << "NEGATIVE CYCLE\n";
        else
            cout << "NO NEGATIVE CYCLE\n";
    }
    return 0;
}

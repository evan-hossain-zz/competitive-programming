int source, sink, from[MAX], visited[MAX], capacity[MAX][MAX];
vector <int> adj[MAX];

int find_path()
{
    //find augmenting path
    queue <int> Q;
    Q.push(source);
    clr(visited, 0);
    clr(from, -1);
    visited[source] = 1;
    int v, lim, i, cur;
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        lim = SZ(adj[cur]);
        for(i = 0; i < lim; i++)
        {
            v = adj[cur][i];
            if(visited[v] || v == from[cur] || !capacity[cur][v])
                continue;
            Q.push(v);
            visited[v] = 1;
            from[v] = cur;
            if(v == sink)
                break;
        }
        if(i < lim)
            break;
    }
    //compute path capacity
    int path_capacity = infinity, prev;
    cur = sink;
    while(from[cur] > -1)
    {
        prev = from[cur];
        path_capacity = min(path_capacity, capacity[prev][cur]);
        cur = prev;
    }
    //update residual graph
    cur = sink;
    while(from[cur] > -1)
    {
        prev = from[cur];
        capacity[prev][cur] -= path_capacity;
        capacity[cur][prev] += path_capacity;
        cur = prev;
    }
    if(path_capacity == infinity)
        return 0;
    return path_capacity;
}

int max_flow()
{
    int result = 0, path_capacity;
    while(true)
    {
        path_capacity = find_path(); //finds augmenting path
        if(path_capacity == 0) //no augmenting path found
            break;
        else
            result += path_capacity;
    }
    return result;
}

void print_min_cut()
{
    vector <int> first_set;
    queue <int> Q;
    Q.push(source);
    clr(visited, 0);
    visited[source] = 1;
    int v, lim, i, cur, j;
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        lim = SZ(adj[cur]);
        for(i = 0; i < lim; i++)
        {
            v = adj[cur][i];
            if(visited[v])
                continue;
            if(!capacity[cur][v])
            {
                if(visited[cur] == 1)
                {
                    visited[cur]++;
                    first_set.pb(cur);
                }
                continue;
            }
            Q.push(v);
            visited[v] = 1;
        }
    }
    lim = SZ(first_set);
    for(i = 0; i < lim; i++)
    {
        cur = first_set[i];
        for(j = 0; j < SZ(adj[cur]); j++)
        {
            v = adj[cur][j];
            if(!visited[v] && !capacity[cur][v])
                printf("%d %d\n", cur, v);
        }
    }
    printf("\n");
}

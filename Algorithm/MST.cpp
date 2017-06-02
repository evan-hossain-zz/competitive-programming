struct edge{
    int u, v, w;
    edge(){}
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (const edge & p) const{
        return w < p.w;
    }
};

vector <edge> edgeList;
int par[MAX];

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

int mst(int n)
{
    int ret = 0, cnt = n - 1, i;
    sort(all(edgeList));
    for(i = 1; i <= n; i++) par[i] = i;
    for(i = 0; i < SZ(edgeList) && cnt; i++)
    {
        int u = find_set(edgeList[i].u);
        int v = find_set(edgeList[i].v);
        if(u != v)
        {
            par[u] = v;
            ret += edgeList[i].w;
            cnt--;
        }
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    return 0;
}


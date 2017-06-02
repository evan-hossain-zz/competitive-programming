///spoj QTREE
/*
given weight of edges. query on max edge and update on singe edge
*/

#define root 0
#define LN 16 ///log2(MAX)

vector <int> adj[MAX], costs[MAX];
int arr[MAX], now;
int chain_no, chain_indx[MAX], chain_head[MAX], pos_in_arr[MAX];
int depth[MAX], par[MAX][LN], child[MAX];
int segtree[MAX*4];
struct edge{
    int u, v, c;
    edge(){}
    edge(int uu, int vv, int cc)
    {
        u = uu;
        v = vv;
        c = cc;
    }
};
vector <edge> edges;

void build(int s, int e, int cur)
{
    if(s == e)
    {
        segtree[cur] = arr[s];
        return;
    }
    int lchild = (cur << 1), rchild = lchild | 1, m = (s + e) >> 1;
    build(s, m, lchild);
    build(m+1, e, rchild);
    segtree[cur] = max(segtree[lchild], segtree[rchild]);
}

void update(int s, int e, int cur, int indx, int val)
{
    if(s == e)
    {
        segtree[cur] = val;
        return;
    }
    int lchild = (cur << 1), rchild = lchild | 1, m = (s + e) >> 1;
    if(indx <= m)
        update(s, m, lchild, indx, val);
    else
        update(m+1, e, rchild, indx, val);
    segtree[cur] = max(segtree[lchild], segtree[rchild]);
}

int query_tree(int s, int e, int cur, int L, int R)
{
    if(s > R || e < L)
        return 0;
    if(s >= L && e <= R)
        return segtree[cur];
    int lchild = (cur << 1), rchild = lchild | 1, m = (s + e) >> 1;
    return max(query_tree(s, m, lchild, L, R),
                query_tree(m+1, e, rchild, L, R));
}
/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */
int query_up(int u, int v)
{
    if(u == v) return 0;
    int uchain, vchain = chain_indx[v], ans = -1;
    while(true)
    {
        uchain = chain_indx[u];
        if(uchain == vchain)
        {
            if(u == v) break;
            ans = max(ans, query_tree(0, now, 1, pos_in_arr[v]+1, pos_in_arr[u]));
            break;
        }
        u = chain_head[uchain];
        ans = max(ans, query_tree(0, now, 1, pos_in_arr[u], pos_in_arr[u]));
        u = par[u][0];
    }
    return ans;
}

void process(int n)
{
    int h, i, lev;
    h = log2(n) + 1;

    for(lev = 1; lev <= h; lev++)
    {
        for(i = 0; i < n; i++)
        {
            if(par[i][lev - 1] != -1)
                par[i][lev] = par[par[i][lev - 1]][lev - 1];
        }
    }
}

int LCA(int high, int low)
{
    if(depth[low] < depth[high]) swap(low, high);
    int h, i, diff;
    h = log2(depth[low]) + 1;
    diff = depth[low] - depth[high];
    for(i = 0; i <= h; i++)
        if(diff & (1 << i))
            low = par[low][i];
    if(low == high) return low;
    for(i = h; i >= 0; i--)
    {
        if(par[low][i] != -1 && par[low][i] != par[high][i])
        {
            low = par[low][i];
            high = par[high][i];
        }
    }
    return par[low][0];
}

int query(int u, int v)
{
    int lca = LCA(u, v);
    return max(query_up(u, lca), query_up(v, lca));
}

void change(int i, int val)
{
    edge tem = edges[i];
    int pos = pos_in_arr[tem.u];
    if(depth[tem.u] < depth[tem.v])
        pos = pos_in_arr[tem.v];
    update(0, now, 1, pos, val);
}

void HLD(int cur_node, int cost, int prev)
{
    if(chain_head[chain_no] == -1)
        chain_head[chain_no] = cur_node;
    chain_indx[cur_node] = chain_no;
    pos_in_arr[cur_node] = now;
    arr[now++] = cost;
    int schild = -1, ncost, i, v;
    for(i = 0; i < SZ(adj[cur_node]); i++)
    {
        v = adj[cur_node][i];
        if(v == prev) continue;
        if(schild == -1 || child[schild] < child[v])
        {
            schild = v;
            ncost = costs[cur_node][i];
        }
    }
    if(schild != -1)
        HLD(schild, ncost, cur_node);
    for(i = 0; i < SZ(adj[cur_node]); i++)
    {
        v = adj[cur_node][i];
        if(v == prev) continue;
        if(schild != v)
        {
            chain_no++;
            HLD(v, costs[cur_node][i], cur_node);
        }
    }
}

void dfs(int cur, int prev, int d)
{
    par[cur][0] = prev;
    depth[cur] = d;
    child[cur] = 1;
    for(int i = 0; i < SZ(adj[cur]); i++)
    {
        int v = adj[cur][i];
        if(v == prev) continue;
        dfs(v, cur, d + 1);
        child[cur] += child[v];
    }
}

void init(int n)
{
    now = chain_no = 0;
    edges.clear();
    for(int i = 0; i < n; i++)
    {
        adj[i].clear();
        costs[i].clear();
        chain_head[i] = -1;
        for(int j = 0; j < LN; j++)
            par[i][j] = -1;
    }
}

int main()
{
    int test, n, i, u, v, c;
    char str[10];
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        init(n);
        for(i = 1; i < n; i++)
        {
            scanf("%d %d %d", &u, &v, &c);
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
            costs[u].pb(c);
            costs[v].pb(c);
            edges.pb(edge(u, v, c));
        }
        dfs(root, -1, 0);
        HLD(root, -1, -1);
        build(0, now, 1);
        process(n);
        while(scanf(" %s", str) == 1 && str[0] != 'D')
        {
            scanf("%d %d", &u, &v);
            if(str[0] == 'Q')
                printf("%d\n", query(u-1, v-1));
            else
                change(u-1, v);
        }
    }
    return 0;
}

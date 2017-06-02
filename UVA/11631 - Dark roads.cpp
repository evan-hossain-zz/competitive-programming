#include <bits/stdc++.h>

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

using namespace std;

struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> e;
int par[200005];
int find_set(int node);
long long mst(int n)
{
    int cnt = n - 1;
    long long ans = 0;
    sort(e.begin(), e.end());
    for(int i = 0; i < e.size() && cnt; i++)
    {
        int u = find_set(e[i].u);
        int v = find_set(e[i].v);
        if(u != v)
        {
            par[u] = v;
            cnt--;
            ans += e[i].w;
        }
    }
    return ans;
}

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

int main()
{
    edge t;
    int m, n, i, x, y, z;
    long long total;
    while(scanf("%d %d", &m, &n) == 2 && m)
    {
        total = 0;
        for(i = 0; i < m; i++)
            par[i] = i;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            t.u = x, t.v = y, t.w = z;
            total += t.w;
            e.pub(t);
        }
        cout << total - mst(m) << endl;
        e.clear();
    }
    return 0;
}

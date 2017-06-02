#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

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
int par[1000005];

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

int mst(int n)
{
    int ret = 0, cnt = n - 1, i;
    sort(e.begin(), e.end());
    for(i = 1; i <= n; i++)
        par[i] = i;
    for(i = 0; i < e.size() && cnt; i++)
    {
        int u = find_set(e[i].u);
        int v = find_set(e[i].v);
        if(u != v)
        {
            par[u] = v;
            ret += e[i].w;
            cnt--;
        }
    }
    return ret;
}

int main()
{
    int n, k, m, i, j, ans = 0;
    edge t;
    while(scanf("%d", &n) == 1)
    {
        if(ans)
        {
            printf("\n");
            e.clear();
        }
        ans = 0;
        for(i = 1; i < n; i++)
        {
            scanf("%d %d %d", &t.u, &t.v, &t.w);
            ans += t.w;
        }
        printf("%d\n", ans);
        scanf("%d", &k);
        for(i = 0; i < k; i++)
        {
            scanf("%d %d %d", &t.u, &t.v, &t.w);
            e.pub(t);
        }
        scanf("%d", &m);
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &t.u, &t.v, &t.w);
            e.pub(t);
        }
        printf("%d\n", min(ans, mst(n)));
    }
    return 0;
}

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return p.w < w;
    }
};

vector <edge> e;

int par[105];

int find_set(int node);
int mst(int n);

int main()
{
    int test, n, m, i, j, kase;
    edge t;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
            par[i] = i;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &t.u, &t.v, &t.w);
            e.pub(t);
        }
        printf("Case #%d: %d\n", kase, mst(n));
        e.clear();
    }
    return 0;
}

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

int mst(int n)
{
    sort(e.begin(), e.end());
    int cnt = n - 1, ans = 30000;
    for(int i = 0; i < e.size() && cnt; i++)
    {
        int u = find_set(e[i].u);
        int v = find_set(e[i].v);
        if(u != v)
        {
            par[u] = v;
            ans = min(ans, e[i].w);
            cnt--;
        }
    }
    return ans;
}

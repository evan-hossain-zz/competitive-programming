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
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 10010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

bool color[SZ];

vector <int> adj[SZ];
vector <int> heads;

void dfs(int u);

int main()
{
    int t, n, m, i, a, b, cnt;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++)
    {
        scanf("%d %d",& n, &m);
        for(i = 1; i <= n; i++)
            adj[i].clear();
        heads.clear();
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].pub(b);
        }
        memset(color, 0, sizeof color);
        cnt = 0;
        for(i = 1; i <= n; i++)
        {
            if(!color[i])
            {
                heads.pub(i);
                color[i] = true;
                dfs(i);
            }
        }
        memset(color, 0, sizeof color);
        for(i = heads.size() - 1; i >= 0; i--)
        {
            if(!color[heads[i]])
                color[heads[i]] = true, cnt++, dfs(heads[i]);
        }
        printf("Case %d: %d\n", kase, cnt);
    }
    return 0;
}

void dfs(int u)
{
    int i, v;
    for(i = 0; i < adj[u].size(); i++)
    {
        v = adj[u][i];
        if(!color[v])
            color[v] = true, dfs(v);
    }
}

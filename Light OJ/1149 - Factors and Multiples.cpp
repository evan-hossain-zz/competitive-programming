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
#define SZ 110

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

LL par[SZ];
bool color[SZ];

vector <LL> adj[SZ];

LL BMP(LL n, LL m);
LL dfs(LL u);

int main()
{
    LL test, n, m, i, j, a;
    scanf("%lld", &test);
    for(int kase = 1; kase <= test; kase++)
    {
        scanf("%lld", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%lld", &par[i]);
            adj[i].clear();
        }
        scanf("%lld", &m);
        for(i = 0; i < m; i++)
        {
            scanf("%lld", &a);
            for(j = 0; j < n; j++)
            {
                if(a == 0 || (par[j] && a % par[j] == 0))
                    adj[j].pub(i);
            }
        }
        printf("Case %d: %lld\n", kase, BMP(n, m));
    }
    return 0;
}

LL BMP(LL n, LL m)
{
    LL ret = 0;
    memset(par, -1, sizeof par);
    for(int i = 0; i < n; i++)
    {
        memset(color, 0, sizeof color);
        if(dfs(i)) ret++;
    }
    return ret;
}

LL dfs(LL u)
{
    if(color[u]) return false;
    color[u] = true;
    for(int i = 0; i < adj[u].size(); i++)
    {
        LL v = adj[u][i];
        if(par[v] == -1 || dfs(par[v]))
        {
            par[v] = u;
            return 1;
        }
    }
    return 0;
}

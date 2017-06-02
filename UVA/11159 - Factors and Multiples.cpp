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
#define SZ 101

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int par[SZ];
bool color[SZ];

vector <int> adj[SZ];

int BMP(int n, int m);
int dfs(int u);

int main()
{
    int test, n, m, i, j, a;
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &par[i]);
            adj[i].clear();
        }
        scanf("%d", &m);
        for(i = 0; i < m; i++)
        {
            scanf("%d", &a);
            for(j = 0; j < n; j++)
            {
                if(a == 0 || (par[j] && a % par[j] == 0))
                    adj[j].pub(i);
            }
        }
        printf("Case %d: %d\n", kase, BMP(n, m));
    }
    return 0;
}

int BMP(int n, int m)
{
    int ret = 0;
    memset(par, -1, sizeof par);
    for(int i = 0; i < n; i++)
    {
        memset(color, 0, sizeof color);
        if(dfs(i)) ret++;
    }
    return ret;
}

int dfs(int u)
{
    if(color[u]) return false;
    color[u] = true;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(par[v] == -1 || dfs(par[v]))
        {
            par[v] = u;
            return 1;
        }
    }
    return 0;
}

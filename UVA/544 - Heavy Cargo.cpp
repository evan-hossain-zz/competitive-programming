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

string s, ss;
map <string, int> m;

int grid[220][220];

int main()
{
    int n, r, i, j, wg, kase = 0, k, cnt;
    while(scanf("%d %d", &n, &r) == 2 && (n | r))
    {
        cnt = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                grid[i][j] = -1;
            grid[i][i] = 0;
        }
        for(i = 0; i < r; i++)
        {
            cin >> s >> ss >> wg;
            if(m.find(s) == m.end())
                m[s] = cnt++;
            if(m.find(ss) == m.end())
                m[ss] = cnt++;
            grid[m[s]][m[ss]] = grid[m[ss]][m[s]] = wg;
        }
        for(k = 0; k < n; k++)
        {
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                grid[i][j] = max(grid[i][j], min(grid[i][k], grid[k][j]));
            }
        }
        cin >> s >> ss;
        printf("Scenario #%d\n", ++kase);
        printf("%d tons\n\n", grid[m[s]][m[ss]]);
        m.clear();
    }
    return 0;
}













/*
int find_set(int node);
void mst(int n);
void dfs(int x);

        mst(n);
        printf("Scenario #%d\n", ++kase);
        printf("%d tons\n\n", y);
        for(i = 0; i < n; i++)
            vc[i].clear();
        e.clear();
        m.clear();
    }
    return 0;
}

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

void mst(int n)
{
    sort(e.begin(), e.end());
    int u, v, i, got = 0;
    for(i = 0; i < cnt; i++)
        par[i] = i;
    cnt = n - 1;
    for(i = 0; i < e.size() && cnt; i++)
    {
        u = find_set(e[i].u);
        v = find_set(e[i].v);
        if(u != v)
        {
            par[u] = v;
            path[u][v] = path[v][u] = e[i].w;
            vc[u].pub(v);
            vc[v].pub(u);
            cnt--;
        }
    }
    dfs(start);
}

void dfs(int x)
{
    int p;
    for(p = 0; p < vc[x].size(); p++)
    {
        if(path[x][vc[x][p]] != -1)
        {
            y = min(y, path[x][vc[x][p]]);
            path[x][vc[x][p]] = path[vc[x][p]][x] = -1;
            if(vc[x][p] == end || x == end)
                return;
            else
                dfs(vc[x][p]);
        }
    }
}*/


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
#define infinity 2147483
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};

using namespace std;

int grid[205][205], st = -1, color[205], en = -1, cnt = 1;
vector <int> v[205];

void init(int n);
void floyed(int n);
void dfs(int n);
void arekdfs(int n);
void lastdfs(int n);
int find_big(int n);

int main()
{
    int n, m, a, b, w, i, j;

    cin >> n >> m;
    init(n);
    for(i = 1; i <= m; i++)
    {
        cin >> a >> b >> w;
        grid[a][b] = grid[b][a] = w;
        v[a].pub(b);
        v[b].pub(a);
    }
    floyed(n);
    dfs(a);
    for(i = 0; i <= n; i++)
        color[i] = 0;
//    arekdfs(st);
//    lastdfs(st);
//    cout << st << ' ' << en << ' ' << cnt << ' ' << grid[st][en] << endl;
        printf("%lf\n", (double)find_big(n) / 2);
    return 0;
}

void init(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            grid[i][j] = infinity;
        grid[i][i] = 0;
    }
}

void floyed(int n)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
    }
}

void dfs(int n)
{
    color[n] = 1;
    int i, j;
    for(i = 0; i < v[n].size(); i++)
    {
        if(color[v[n][i]] == 0)
        {
            dfs(v[n][i]);
        }
    }
    if(st == -1)
        st = n;
}

void arekdfs(int n)
{
    color[n] = 1;
    int i, j;
    for(i = 0; i < v[n].size(); i++)
    {
        if(color[v[n][i]] == 0)
        {
            arekdfs(v[n][i]);
        }
    }
    if(en == -1)
        en = n;
}

void lastdfs(int n)
{
    cnt++;
    color[n] = 1;
    int i, j;
    for(i = 0; i < v[n].size(); i++)
    {
        if(color[v[n][i]] == 0)
        {
            if(v[n][i] == en)
                return;
            lastdfs(v[n][i]);
        }
    }
}

int find_big(int n)
{
    int i, j, m = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(grid[i][j] < infinity)
                m = max(grid[i][j], m);
        }
    }
    return m;
}

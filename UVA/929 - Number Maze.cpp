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
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

struct info
{
    struct ct
    {
        int r, c;
    }city;
    int cost;
    bool operator < (const info &p) const
    {
        return p.cost < cost;
    }
};

int grid[1005][1005], d[1005][1005], n, m;

void dijkstra(void);
void initialize(int n, int m);

int main()
{
    int test, i, j;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);
        initialize(n, m);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                scanf("%d", &grid[i][j]);
        dijkstra();
        printf("%d\n", d[n][m]);
    }
    return 0;
}

void initialize(int n, int m)
{
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            d[i][j] = infinity;
    return;
}

void dijkstra(void)
{
    int p;
    info u, v;
    u.city.r = u.city.c = 1, u.cost = grid[1][1];
    d[1][1] = grid[1][1];
    priority_queue <info> q;
    q.push(u);
    while(!q.empty())
    {
        u = q.top(), q.pop();
        int ucost = d[u.city.r][u.city.c];
        for(p = 0; p < 4; p++)
        {
            int nr = u.city.r + row[p];
            int nc = u.city.c + col[p];
            if(nr > 0 && nr <= n && nc > 0 && nc <= m)
            {
                v.city.r = nr, v.city.c = nc, v.cost = grid[nr][nc] + ucost;
                if(d[v.city.r][v.city.c] > v.cost)
                {
                    d[v.city.r][v.city.c] = v.cost;
                    q.push(v);
                }
            }
        }
    }
    return;
}

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
#define infinity 21474836
#define LL long long
#define Pi acos(-1)
#define SZ 10050

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct distedge
{
    int city, cost, used_notun;
    bool operator < (const distedge &a) const
    {
        return a.cost < cost;
    }
};

struct edge
{
    int city, cost, notun;
};

vector <edge> roads[SZ];
int dist[SZ][12], d;

void initialize(int n)
{
    for(int i = 0; i <= n; i++)
    {
        roads[i].clear();
        for(int j = 0; j < 12; j++)
            dist[i][j] = infinity;
    }
}
int dijkstra(int start, int finish);

int main()
{
    int u, v, cost, k, n, m, i, j, test, kase;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        scanf("%d %d %d %d", &n, &m, &k, &d);
        initialize(n);
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &cost);
            roads[u].pub(edge{v, cost, 0});
        }
        for(i = 0; i < k; i++)
        {
            scanf("%d %d %d", &u, &v, &cost);
            roads[u].pub(edge{v, cost, 1});
        }
        int ans = dijkstra(0, n - 1);
        if(ans >= infinity)
            printf("Case %d: Impossible\n", kase);
        else
            printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}


int dijkstra(int start, int finish)
{
    priority_queue <distedge> pq;
    distedge u, v;
    u.city = u.cost = u.used_notun = dist[0][0] = 0;
    pq.push(u);
    while(!pq.empty())
    {
        u = pq.top(), pq.pop();
        int ucost = dist[u.city][u.used_notun];
        if(u.city == finish)
            return ucost;
        for(int i = 0; i < roads[u.city].size(); i++)
        {
            v.city = roads[u.city][i].city , v.cost =  roads[u.city][i].cost + ucost , v.used_notun = u.used_notun + roads[u.city][i].notun;
            if(v.used_notun <= d)
            {
                if(v.cost < dist[v.city][v.used_notun])
                {
                    dist[v.city][v.used_notun] = v.cost;
                    pq.push(v);
                }
            }
        }
    }
    return infinity;
}

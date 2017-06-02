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

struct info
{
    int city, dist;
    bool operator < (const info& p) const
    {
        return p.dist < dist;
    }
};

struct edge
{
    int a, cost;
};

vector <edge> e[20005];
int d[20005];
void initialize(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        e[i].clear();
        d[i] = infinity;
    }
    return;
}
void dijkstra(int start, int en)
{
    info u, v;
    u.city = start, u.dist = 0;
    d[start] = 0;
    priority_queue <info> q;
    q.push(u);
    while(!q.empty())
    {
        u = q.top(), q.pop();
        if(u.city == en)
        {
            while(!q.empty())
                q.pop();
            return;
        }
        int ucost = d[u.city];
        for(int i = 0; i < e[u.city].size(); i++)
        {
            v.city = e[u.city][i].a, v.dist = e[u.city][i].cost + ucost;
            if(d[v.city] > v.dist)
            {
                d[v.city] = v.dist;
                q.push(v);
            }
        }
    }
    return;
}

int main()
{
    int n, m, s, t, i, j, test, kase, a, b, c;
    edge ttt, tt;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        initialize(n);
        while(m--)
        {
            scanf("%d %d %d", &a, &b, &c);
            ttt.a = a, tt.a = b, ttt.cost = tt.cost = c;
            e[b].pub(ttt), e[a].pub(tt);
        }
        dijkstra(s, t);
        if(d[t] == infinity)
            printf("Case #%d: unreachable\n", kase);
        else
            printf("Case #%d: %d\n", kase, d[t]);
        }
        return 0;
}



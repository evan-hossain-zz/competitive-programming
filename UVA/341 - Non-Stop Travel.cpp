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

struct node
{
    int ct, dt;
};

vector <node> e[1000];
int d[11], par[11];

void initialize(int n);
void dijkstra(int start, int destination);
void find_par(int n);

int main()
{
    int n, i, m, start, destination, kase = 0;
    node t;
    while(scanf("%d", &n) == 1 && n)
        {
            initialize(n);
            for(i = 1; i <= n; i++)
                {
                    scanf("%d", &m);
                    while(m--)
                        {
                            scanf("%d %d", &t.ct, &t.dt);
                            e[i].pub(t);
                        }
                }
            scanf("%d %d", &start, &destination);
            dijkstra(start, destination);
            printf("Case %d: Path =", ++kase);
            if(start != destination)
                find_par(destination);
            else
                printf(" %d %d", start, destination);
            printf("; %d second delay\n", d[destination]);
        }
    return 0;
}

void initialize(int n)
{
    for(int i = 0; i <= n; i++)
        {
            e[i].clear();
            d[i] = infinity;
            par[i] = 0;
        }
    return;
}

void dijkstra(int start, int destination)
{
    info u, v;
    priority_queue <info> q;
    u.city = start, u.dist = 0;
    d[start] = 0;
    par[start] = 0;
    q.push(u);
    while(!q.empty())
        {
            u = q.top(),q.pop();
            if(u.city == destination)
                return;
            int udist = d[u.city];
            for(int i = 0; i < e[u.city].size(); i++)
                {
                    v.city = e[u.city][i].ct, v.dist = e[u.city][i].dt + udist;
                    if(d[v.city] > v.dist)
                        {
                            d[v.city] = v.dist;
                            par[v.city] = u.city;
                            q.push(v);
                        }
                }
        }
}

void find_par(int n)
{
    if(par[n] == 0)
    {
        printf(" %d", n);
        return;
    }
    find_par(par[n]);
    printf(" %d", n);
    return;
}

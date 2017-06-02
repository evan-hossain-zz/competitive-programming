#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define clr(arr, key) memset(arr, key, sizeof arr)
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 10010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;
vector <int> adj[SZ];
stack < pair<int, int> > s;
int discover[SZ], bedge[SZ], discovery_time, component;

void bcc(int node, int from)
{
    pair <int, int> e, cur;
    discover[node] = bedge[node] = discovery_time++;
    int i, connected = adj[node].size(), to;
    for(i = 0; i < connected; i++)
    {
        to = adj[node][i];
        if(to == from) continue;
        if(!discover[to])
        {
            s.push(make_pair(from, to));
            bcc(to, node);
            if(bedge[to] >= discover[node])
            {
                cur = make_pair(from, to);
                do
                {
                    e = s.top(), s.pop();
                }while(e != cur);
                component++;
            }
            bedge[node] = min(bedge[node], bedge[to]);
        }
        else if(discover[node] > discover[to])
        {
            s.push(make_pair(from, to));
            bedge[node] = min(discover[to], bedge[node]);
        }
    }
}

int main()
{
    int n, m, i, j, kase, test, a, b, arti_points;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        component = 0;
        discovery_time = 1;
        arti_points = 0;
        scanf("%d %d", &n, &m);
        for(i = 1; i <= n; i++)
            adj[i].clear(), discover[i] = bedge[i] = 0;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            a++, b++;
            adj[a].pub(b), adj[b].pub(a);
        }
        bcc(1, -1);
        printf("Case %d: %d\n", kase, component == 1? 0 : (component >> 1) + (component & 1));
    }
}

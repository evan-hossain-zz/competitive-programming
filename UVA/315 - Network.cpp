
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
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 110

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;
vector <int> adj[SZ];
int discover[SZ], bedge[SZ], discovery_time;
bool articulation_point[SZ];

void dfs_artpoint(int node, int from)
{
    articulation_point[node] = false;
    discover[node] = bedge[node] = discovery_time++;
    int i, connected = adj[node].size(), to, child = 0;
    for(i = 0; i < connected; i++)
    {
        to = adj[node][i];
        if(to == from) continue;
        if(!discover[to])
        {
            dfs_artpoint(to, node);
            child++;
            bedge[node] = min(bedge[node], bedge[to]);
            if(bedge[to] >= discover[node] && from != -1)
                articulation_point[node] = true;
        }
        else if(discover[node] > discover[to])
            bedge[node] = min(discover[to], bedge[node]);
    }
    if(from == -1 && child >= 2)
        articulation_point[node] = true;
}

int main()
{
    int n, i, u, v, j;
    string s;
    while(scanf("%d", &n) == 1 && n)
    {
        for(i = 1; i <= n; i++) adj[i].clear();
        clr(discover, 0); clr(bedge, 0);
        while(scanf("%d", &u) == 1 && u)
        {
            getline(cin, s);
            istringstream ss(s);
            while(ss >> v)
            {
                adj[u].pub(v);
                adj[v].pub(u);
            }
        }
        dfs_artpoint(1, -1);
        u = 0;
        for(i = 1; i <= n; i++)
            if(articulation_point[i]) u++;
        printf("%d\n", u);
    }
    return 0;
}

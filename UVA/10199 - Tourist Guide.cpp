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
bool arti[SZ];

void dfs_artpoint(int node, int from)
{
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
                arti[node] = true;
        }
        else if(discover[node] > discover[to])
            bedge[node] = min(discover[to], bedge[node]);
    }
    if(from == -1 && child >= 2)
        arti[node] = true;
}

map <string, int> stoi;
map <int, string> itos;
vector <string> ans;

int main()
{
    int n, m, i, j, map_no = 0;
    string u, v;
    while(scanf("%d", &n) == 1 && n)
    {
        clr(discover, 0), clr(bedge, 0), clr(arti, 0);
        ans.clear();
        for(i = 0; i <= n; i++) adj[i].clear();
        if(map_no) printf("\n");
        discovery_time = 1;
        for(i = 1; i <= n; i++)
        {
            cin >> u;
            stoi[u] = i;
            itos[i] = u;
        }
        scanf("%d", &m);
        for(i = 1; i <= m; i++)
        {
            cin >> u >> v;
            adj[stoi[u]].pub(stoi[v]);
            adj[stoi[v]].pub(stoi[u]);
        }
        for(i = 1; i <= n; i++)
            dfs_artpoint(i, -1);
        for(i = 1; i <= n; i++)
            if(arti[i]) ans.pub(itos[i]);
        sort(ans.begin(), ans.end());
        discovery_time = ans.size();
        printf("City map #%d: %d camera(s) found\n", ++map_no, discovery_time);
        for(i = 0; i < discovery_time; i++)
            cout << ans[i] << endl;
    }
    return 0;
}


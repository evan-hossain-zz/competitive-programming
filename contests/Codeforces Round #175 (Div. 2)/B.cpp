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
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int s, n, d, ans;
vector <int> adj[SZ];
int color[SZ];
queue <int> q;

int bfs(void);

int main()
{
    int i, j;
    cin >> n >> s >> d;
    for(i = 1; i <= n; i++)
    {
        cin >> j;
        adj[i].pub(j);
    }
    if(s == d)
        cout << 0;
    else
    {
        q.push(s);
        color[s] = 1;
        cout << bfs();
    }
    return 0;
}

int bfs(void)
{
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!color[v])
            {
                color[v] = color[u] + 1;
                if(v == d)
                    return color[v] - 1;
                q.push(v);
            }
        }
    }
    return -1;
}

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
#define SZ 10010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <int> adj[550];
int off[550], cur, com;
int visited[550];

void dfs(int u)
{
    com++;
//    cout << u << endl;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(off[v])
            continue;
        if(!visited[v])
        {
            visited[v] = 1;
            dfs(v);
        }
    }
}

int main()
{
    int n, m, k, l, r, i, j, cnt;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> l >> r;
        adj[l].pub(r);
        adj[r].pub(l);
    }
    cin >> k;
    for(i = 0; i < k; i++)
    {
        cnt = 0;
        memset(off, 0, sizeof off);
        memset(visited, 0, sizeof visited);
        cin >> l >> r;
        for(j = l; j <= r; j++)
        {
            off[j] = 1;
        }
        for(j = 1; j <= n; j++)
        {
            if(!visited[j])
            {
                visited[j] = 1;
                if(off[j])
                {
                    cnt++;
                    dfs(j);
                }
                else
                {
                    com = 0;
                    dfs(j);
                    if(com > 1)
                        cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


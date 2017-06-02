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
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 2000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <int> adj[SZ];
int cnt;
bool taken[SZ], wants[SZ];
vector <int> res[SZ];

void dfs(int person)
{
    res[cnt].pub(person);
    for(int i = 0; i < adj[person].size(); i++)
    {
        int v = adj[person][i];
        if(taken[v])
            continue;
        taken[v] = 1;
        dfs(v);
    }
}

int main()
{
    int n, m, a, b, i, j;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> a >> b;
        wants[a] = wants[b] = 1;
        adj[a].pub(b), adj[b].pub(a);
    }
    for(i = 1; i <= n; i++)
    {
        if(wants[i] && !taken[i] && !adj[i].empty())
        {
            taken[i] = 1;
            dfs(i);
            cnt++;
        }
    }
    for(i = 0; !res[i].empty(); i++)
    {
        if(res[i].size() > 3)
        {
            cout << -1 << endl;
            return 0;
        }
        if(res[i].size() < 3)
        {
            for(int j = 1; j <= n && res[i].size() < 3; j++)
            {
                if(taken[j] == 0)
                {
                    taken[j] = 1;
                    res[i].pub(j);
                }
            }
            if(res[i].size() < 3)
            {
                cout << -1;
                return 0;
            }
        }
    }
    int c = 0;
    for(i = 1; i <= n; i++)
        if(taken[i] == 0)
            c++;
    if(c % 3)
    {
        cout << -1;
        return 0;
    }
    for(i = 1; i <= n; i++)
    {
        if(taken[i] == 0)
        {
            taken[i] = 1;
            res[cnt].pub(i);
            if(res[cnt].size() == 3)
                cnt++;
        }
    }
    for(i = 0; !res[i].empty() ; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    return 0;
}


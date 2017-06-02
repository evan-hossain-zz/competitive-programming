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
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct intr
{
    LL a, b;
};

intr arr[300];
bool color[300];

vector <int> adj[300];

void dfs(int u)
{
    color[u] = 1;
    int i, v;
    for(i = 0; i < adj[u].size(); i++)
    {
        v = adj[u][i];
        if(!color[v])
            dfs(v);
    }
}

int main()
{
    int i, n, q, cnt, c, d, j;
    cin >> n;
    for(i = 1, cnt = 1; i <= n; i++)
    {
        cin >> q;
        if(q == 1)
        {
            cin >> arr[cnt].a >> arr[cnt].b;
            for(j = 1; j < cnt; j++)
            {
                if((arr[j].a < arr[cnt].a && arr[cnt].a < arr[j].b) ||
                        (arr[j].a < arr[cnt].b && arr[cnt].b < arr[j].b))
                    adj[cnt].pub(j);
                if((arr[cnt].a < arr[j].a && arr[j].a < arr[cnt].b) ||
                        (arr[cnt].a < arr[j].b && arr[j].b < arr[cnt].b))
                        adj[j].pub(cnt);
            }
            cnt++;
        }
        else
        {
            cin >> c >> d;
            cout << adj.size() << endl;
            clr(color, 0);
            dfs(c);
            if(color[d])
            cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
        return 0;
    }


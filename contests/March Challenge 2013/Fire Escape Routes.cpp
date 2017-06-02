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
#define LL long long int
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <int> connections[SZ];
bool color[SZ];
LL cnt, arr[SZ];

const LL mod = 1000000007;

void dfs(int start);

int main()
{
    int n, a, b, i, j, test, m;
    cin >> test;
    while(test--)
    {
        LL ans = 1;
        cin >> n >> m;
        for(i = 0; i < SZ; i++)
        {
            connections[i].clear();
            color[i] = 0;
            arr[i] = 0;
        }
        while(m--)
        {
            cin >> a >> b;
            connections[a].pub(b);
            connections[b].pub(a);
        }
        for(i = 1; i <= n; i++)
        {
            if(!color[i])
            {
                cnt = 1;
                color[i] = true;
                dfs(i);
                arr[i] = cnt;
            }
        }
        cnt = 0;
        ans = 1;
        for(i = 1; i <= n; i++)
        {
            if(arr[i])
            {
                cnt++;
                ans = ((arr[i] % mod) * (ans % mod)) % mod;
            }
        }
        cout << cnt << ' ' << ans << endl;
    }
    return 0;
}

void dfs(int start)
{
    int i;
    for(i = 0; i < connections[start].size(); i++)
    {
        if(!color[connections[start][i]])
        {
            cnt++;
            color[connections[start][i]] = true;
            dfs(connections[start][i]);
        }
    }
}

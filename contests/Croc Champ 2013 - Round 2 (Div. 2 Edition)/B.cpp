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
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

char arr[3 * SZ];
int n, k, dp[3 * SZ];

int dfs(int node)
{
    int &ret = dp[node];
    if(ret != -1)
        return ret;
    if(arr[node] == '#')
        return ret = 0;
    if(node >= n - 1)
        return ret = 1;
    for(int i = 1; i <= k; i++)
    {
        if(arr[node + i] == '.')
            if(dfs(node + i))
                return ret = 1;
    }
    return ret = 0;
}

int main()
{
    int i, j;
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    for(i = 0; i < n; i++)
        cin >> arr[i];
    if(dfs(0))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}


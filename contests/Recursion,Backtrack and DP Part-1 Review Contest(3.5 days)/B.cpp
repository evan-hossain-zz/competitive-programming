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
#define SZ 110

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int grid[2 * SZ][SZ], n;
int dp[2 * SZ][SZ];

int take_banana(int row, int col);

int main()
{
    int test, i, j, kase, tem;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        memset(dp, -1, sizeof(dp));
        memset(grid, 0, sizeof(grid));
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= i; j++)
                scanf("%d", &grid[i][j]);
        tem = n << 1;
        for(i = n + 1; i < tem; i++)
            for(j = 1; j <= tem - i; j++)
                scanf("%d", &grid[i][j]);
        take_banana(1, 1);
        printf("Case %d: %d\n", kase, dp[1][1]);
    }
    return 0;
}

int take_banana(int row, int col)
{
    if(grid[row][col] == 0)
        return 0;
    if(dp[row][col] != -1)
        return dp[row][col];
    int u;
    u = take_banana(row + 1, col);
    if(row < n)
        return dp[row][col] = max(u, take_banana(row + 1, col + 1)) + grid[row][col];
    else
        return dp[row][col] = max(u, take_banana(row + 1, col - 1)) + grid[row][col];
}

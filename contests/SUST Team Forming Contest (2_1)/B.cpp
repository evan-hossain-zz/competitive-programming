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
#define infinity 1 << 30
#define LL long long
#define Pi acos(-1)
#define SZ 110

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int grid[SZ][SZ];

void init(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            grid[i][j] = -infinity;
        grid[i][i] = 0;
    }
}

void floyd(int n)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1;  j <= n; j++)
                grid[i][j] = max(grid[i][j], grid[i][k] + grid[k][j]);
}

int main()
{
    int n, i, j, start, a, b, en, kase = 0, mx;
    while(cin >> n && n)
    {
        mx = -infinity;
        init(n);
        cin >> start;
        while(cin >> a >> b && (a | b))
            grid[a][b] = 1;
        floyd(n);
        for(i = 1; i <= n; i++)
        {
            if(grid[start][i] > mx)
            {
                mx = grid[start][i];
                en = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++kase, start, mx, en);
    }
    return 0;
}


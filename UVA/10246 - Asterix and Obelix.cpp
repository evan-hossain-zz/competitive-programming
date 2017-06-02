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
#define oo 214748
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int grid[81][81], feast[81][81], main_feast_cost[81];

void initialize(int n);
void floyed(int n);

int main()
{
    int i, c, r, q, a, b, cost, j;
    while(scanf("%d %d %d", &c, &r, &q) == 3 && (c | r | q))
        {
            initialize(c);
            for(i = 0; i < r; i++)
                {
                    scanf("%d %d %d", &a, &b, &cost);
                    grid[a][b] = grid[b][a] = cost;
                }
            for(i = 1; i <= c; i++)
                for(j = 1; j <= c; j++)
                    feast[i][j] = feast[j][i] = max(main_feast_cost[i], main_feast_cost[j]);
            floyed(c);
            for(i = 1; i <= c; i++)
            {
                for(j = 1; j <= c; j++)
                    cout << grid[i][j] << ' ';
                cout << endl;
            }
            for(i = 0; i < q; i++)
                {
                    scanf("%d %d", &a, &b);
                    if(grid[a][b] < oo)
                        printf("%d\n", grid[a][b]);
                    else
                        printf("-1\n");
                }
        }
    return 0;
}

void initialize(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
        {
            scanf("%d", &main_feast_cost[i]);
            for(j = 1; j <= n; j++)
                grid[i][j] = feast[i][j] = oo;
            grid[i][i] = 0;
        }
    return;
}

void floyed(int n)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
            {
                if(grid[i][j] < grid[i][k] + grid[k][j])
                    grid[i][j] += feast[i][j];
                else
                    grid[i][j] = grid[i][k] + grid[k][j] + max(grid[i][k], grid[k][j]);
            }
    return;
}

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
#define infinity 2147

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int grid[105][105];

void initialize(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            grid[i][j] = infinity;
    return;
}
void floyed(int n);

int main()
{
    int i, j, n, l, m, s;
    vector <int> v;
    while(scanf("%d", &n) == 1 && n)
        {
            initialize(n);
            while(scanf("%d", &l) == 1 && l)
            {
                while(scanf("%d", &m) == 1 && m)
                    grid[l][m] = 1;
            }
            floyed(n);
            scanf("%d", &l);
            while(l--)
            {
                scanf("%d", &s);
                for(i = 1; i <= n; i++)
                {
                    if(grid[s][i] == infinity)
                        v.pub(i);
                }
                printf("%d", v.size());
                for(i = 0; i < v.size(); i++)
                    printf(" %d", v[i]);
                printf("\n");
                v.clear();
            }
        }
    return 0;
}

void floyed(int n)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
    return;
}

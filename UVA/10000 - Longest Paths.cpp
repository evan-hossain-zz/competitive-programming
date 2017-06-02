#include <iostream>
#include <cstdio>

using namespace std;

int grid[105][105];
int main()
{
    int n, s, i, j, a, b, k;
    while(scanf("%d", &n) == 1 && n)
    {
        scanf("%d", &s);
        for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                    grid[i][j] = 100;
        while(scanf("%d %d", &a, &b) == 2 && (a || b))
        {
            grid[a][b] = 1;
        }
        for(k = 1; k <= n; k++)
            for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }

            for(i = 1; i <= n; i++)
                {for(j = 1; j <= n; j++)
                    printf("%4d ", grid[i][j]);
                    printf("\n");}
    }
}

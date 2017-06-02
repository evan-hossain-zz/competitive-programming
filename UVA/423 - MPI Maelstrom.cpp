// uva - 423


#include <iostream>
#include <cstdio>
#include <cstring>

#define infinity 60000000
using namespace std;

int main()
{
    int i, j, n, k, ans;
    char word[20];
    int grid[105][105];
    grid[0][0] = 0;
    while(scanf("%d", &n) == 1)
    {
        for(i = 1; i < n; i++)
        {
            for(j = 0; j < i; j++)
            {
                scanf(" %s", &word);
                if(strcmp(word, "x") == 0)
                    grid[i][j] = grid[j][i] = infinity;
                else
                {
                    sscanf(word, "%d", &grid[i][j]);
                    grid[j][i] = grid[i][j];
                }
            }
            grid[i][i] = 0;
        }
        ans = 0;
        for(k = 0; k < n; k++)
            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
            grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
        for(j = 0; j < n; j++)
            ans = max(ans, grid[0][j]);
        printf("%d\n", ans);
    }
    return 0;
}


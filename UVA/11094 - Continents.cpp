#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int m, n, cnt;
char grid[21][21], ch;
void dfs(int r, int c);

int main()
{
    int i, j, k, l, x, y, ans, fst, ma;
    while(scanf("%d %d", &m, &n) == 2)
    {
        ans = 0;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
                scanf(" %c", &grid[i][j]);
        }
        scanf("%d %d", &x, &y);
        ch = grid[x][y];
        grid[x][y] = 0;
        dfs(x, y);
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(grid[i][j] == ch)
                {
                    cnt = 1;
                    grid[i][j] = 0;
                    dfs(i, j);
                    ans = max(ans, cnt);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

void dfs(int r, int c)
{
    if(grid[r - 1][c] == ch)
    {
        cnt++;
        grid[r - 1][c] = 0;
        dfs(r - 1, c);
    }
    if(c - 1 >= 0 && grid[r][c - 1] == ch)
    {
        cnt++;
        grid[r][c - 1] = 0;
        dfs(r, c - 1);
    }
    if(c + 1 <  n && grid[r][c + 1] == ch)
    {
        if(grid[r][c + 1] == ch)
        {
            cnt++;
            grid[r][c + 1] = 0;
            dfs(r, c + 1);
        }
    }
    if(r + 1 < m && grid[r + 1][c] == ch)
    {
        cnt++;
        grid[r + 1][c] = 0;
        dfs(r + 1, c);

    }
    if(c == 0 && grid[r][n - 1] == ch)
    {
        cnt++;
        grid[r][n - 1] = 0;
        dfs(r, n - 1);
    }

    else if(c == n - 1 && grid[r][0] == ch)
    {
        cnt++;
        grid[r][0] = 0;
        dfs(r, 0);

    }
}

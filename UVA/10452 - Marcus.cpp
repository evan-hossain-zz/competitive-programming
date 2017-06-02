#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int row[3] = {0, -1, 0}, col[3] = {1, 0, -1}\
                                  , cnt, m, n, sr, sc, er, ec;
char grid[10][10];
string s = "IEHOVA#";

void dfs(int r, int c);

int main()
{
    int test, i, j;
    scanf("%d", &test);
    while(test--)
    {
        cnt = 0;
        scanf("%d %d", &m, &n);
        for(j = 0; j < n; j++)
        {
            scanf(" %c", &grid[0][j]);
            if(grid[0][j] == '#')
                er = 0, ec = j;
        }
        for(i = 1; i < m - 1; i++)
            for(j = 0; j < n; j++)
                scanf(" %c", &grid[i][j]);
        for(j = 0; j < n; j++)
        {
            scanf(" %c", &grid[i][j]);
            if(grid[i][j] == '@')
                sr = i, sc = j;
        }
        dfs(sr, sc);
        printf("\n");
    }
    return 0;
}

void dfs(int r, int c)
{
    int p, R, C;
    for(p = 0; p < 3; p++)
    {
        R = r + row[p];
        C = c + col[p];
        if((R >= 0 && R < m) &&
                (C >= 0 && C < n))
        {
            if(grid[R][C] == s[cnt])
            {
                if(cnt > 0)
                    printf(" ");
                switch(p)
                {
                case 0:
                    printf("right");
                    break;
                case 1:
                    printf("forth");
                    break;
                case 2:
                    printf("left");
                    break;
                }
                if(er == R && ec == C)
                    return;
                cnt++;
                dfs(R, C);
            }
        }
    }
}

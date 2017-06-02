#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

void dfs(int row, int col);

int m, cnt;
char str[700], grid[27][27], ch;
int main()
{
    int i, j, k, test, brk, ans;
    scanf("%d", &test);
    ch = getchar();
    while(test--)
    {
        cnt = ans = 0;
        brk = i = 0;
        while(scanf("%c", &ch) == 1)
        {
            if(ch == '\n' && brk == 1)  break;
            else if(ch == '\n')
                brk = 1;
            else
            {
                str[i++] = ch;
                brk = 0;
            }
        }
        str[i] = 0;
        m = sqrt(i);
        for(i = 0, k = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
                grid[i][j] = str[k++];
        }
        str[k] = 0;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    cnt = 1;
                    dfs(i, j);
                    ans = max(ans, cnt);
                }
            }
        }
        if(test != 0)
            printf("%d\n\n", ans);
        else
            printf("%d\n", ans);
    }
    return 0;
}

void dfs(int row, int col)
{
    int p, q;
    for(p = row - 1; p < row + 2; p++)
    {
        if(p >= 0 && p < m)
        {
            for(q = col - 1; q < col + 2; q++)
            {
                if(q >= 0 && q < m)
                {
                    if(grid[p][q] == '1')
                    {
                        grid[p][q] = '0';
                        cnt++;
                        dfs(p, q);
                    }
                }
            }
        }
    }
}

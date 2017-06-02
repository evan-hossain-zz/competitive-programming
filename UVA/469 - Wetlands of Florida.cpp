#include<cstdio>
#include<cstring>

int i, m, cnt, l = 1;
char grid[110][110], color[110][110];
void dfs(int r, int c);
int main()
{
    int j, a, b, tst;
    char str[110];
    scanf("%d", &tst);
    while(tst--)
    {
        i = 1;
        scanf(" %s", &str);
        m = strlen(str);
        for(j = 0; j < m; j++)
            grid[0][j] = str[j];
            getchar();
        while(gets(str))
        {
            l = strlen(str);
            if(l == 0)
                    break;
            if(str[0] == 'L' || str[0] == 'W')
            {
                for(j = 0; j < m; j++)
                    grid[i][j] = str[j];
                i++;
            }
            else if(str[0] >= '0' && str[0] <= '9')
            {
                sscanf(str, "%d %d", &a, &b);
                cnt = 0;
                memset(color, 0, 110*110);
                if(grid[a - 1][b - 1] == 'W')
                    dfs(a - 1, b - 1);
                printf("%d\n", cnt);
            }
        }
        if(tst != 0)
        printf("\n");
    }
    return 0;
}

void dfs(int r, int c)
{
    int p, q;
    for(p = r - 1; p <= r + 1; p++)
    {
        if(p >= 0 && p < i)
        {
            for(q = c - 1; q <= c + 1; q++)
            {
                if(q >= 0 && q < m)
                {
                    if(grid[p][q] == 'W' && color[p][q] == 0)
                    {
                        cnt++;
                        color[p][q] = 'L';
                        dfs(p, q);
                    }
                }
            }
        }
    }
}

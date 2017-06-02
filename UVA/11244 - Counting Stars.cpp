#include<iostream>
#include<cstdio>
#include<string>

char arr[110][110];
int m, n, temp;
void dfs(int row, int col);
int main()
{
    int i, j, l, cnt;
    while(scanf("%d %d", &m, &n) == 2 && m != 0)
    {
        cnt = 0;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
                scanf(" %c", &arr[i][j]);
        }
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(arr[i][j] == '*')
                {
                    temp = 0;
                    arr[i][j] = '.';
                    dfs(i, j);
                    if(temp == 1)
                        cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

void dfs(int row, int col)
{
    temp++;
    int p, q;
    for(p = row - 1; p <= row + 1; p++)
    {
        if(p >= 0 && p < m)
        {
            for(q = col - 1; q <= col + 1; q++)
            {
                if(q >= 0 && q < n)
                {
                    if(arr[p][q] == '*')
                    {
                        arr[p][q] = '.';
                        dfs(p, q);
                    }
                }
            }
        }
    }
}

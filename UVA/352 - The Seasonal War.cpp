#include<iostream>
#include<cstdio>
#include<string>

char arr[50][50];
int m;
void dfs(int row, int col);
int main()
{
    int i, j, kase = 0, cnt;
    while(scanf("%d", &m) == 1)
    {
        cnt = 0;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
                scanf(" %c", &arr[i][j]);
        }

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(arr[i][j] == '1')
                {
                    cnt++;
                    arr[i][j] = '0';
                    dfs(i, j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", ++kase, cnt);
    }
    return 0;
}

void dfs(int row, int col)
{
    int p, q;
    for(p = row - 1; p <= row + 1; p++)
    {
        if(p >= 0 && p < m)
        {
            for(q = col - 1; q <= col + 1; q++)
            {
                if(q >= 0 && q < m)
                {
                    if(arr[p][q] == '1')
                    {
                        arr[p][q] = '0';
                        dfs(p, q);
                    }
                }
            }
        }
    }
}


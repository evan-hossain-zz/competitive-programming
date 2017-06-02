#include<stdio.h>
#include<string.h>

char arr[500][500];
int n;
void dfs(int row, int col);
int main()
{
    int i, j, l, cnt, test, kase = 0;
    scanf("%d", &test);
    while(kase < test)
    {
        scanf("%d", &n);
        cnt = 0;
        for(i = 0; i < n; i++)
            scanf(" %s", arr[i]);
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(arr[i][j] == 'x')
                {
                    cnt++;
                    arr[i][j] = '.';
                    dfs(i, j);
                }
            }
        }
        printf("Case %d: %d\n", ++kase, cnt);
    }
    return 0;
}

void dfs(int row, int col)
{
    int p, q;
    for(p = row - 1; p <= row + 1; p++)
    {
        if(p >= 0 && p < n)
        {
            for(q = col - 1; q <= col + 1; q++)
            {
                if(q >= 0 && q < n)
                {
                    if(arr[p][q] != '.')
                    {
                        arr[p][q] = '.';
                        dfs(p, q);
                    }
                }
            }
        }
    }
}


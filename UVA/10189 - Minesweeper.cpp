#include<stdio.h>
#include<string.h>

#define counter(r, c) for(p = r - 1; p <= r + 1; p++)\
    {\
        if(p >= 0 && p < n)\
        {\
            for(q = c - 1; q <= c + 1; q++)\
            {\
                if(q >= 0 && q < m)\
                {\
                    if(grid[p][q] == '*')\
                        cnt++;\
                }\
            }\
        }\
    }
int m, n;
char grid[220][110];
int res[220][110], p, q, cnt;


int main()
{
    int i, j, kase = 0;
    while(scanf("%d %d", &n, &m) == 2 && (n || m))
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
                scanf(" %c", &grid[i][j]);
        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == '.')
                {
                    cnt = 0;
                    counter(i, j);
                    res[i][j] = cnt;
                }
                else
                    res[i][j] = -1;
            }
        }
        if(kase != 0)
            printf("\n");
        printf("Field #%d:\n", ++kase);
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(res[i][j] == -1)
                    printf("*");
                else
                    printf("%d", res[i][j]);
                res[i][j] = 0;
            }
            printf("\n");
        }
    }
    return 0;
}


#include<stdio.h>

int mat[10][10];

int main()
{
    int n, i, j, sum, kase, limit, cnt = 1, k, l;
    while(scanf("%d", &n) == 1 && n)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);
        }

        printf("Case %d:", cnt++);
        if(n % 2 == 0)
            limit = n / 2;
        else
            limit = n / 2 + 1;
        for(kase = 1, i = 0; kase <= limit; kase++, n--, i++)
        {
            sum = 0;
            for(k = i; k < n; k++)
            {
                if(k == i)
                    sum += mat[i][k];
                else
                    sum += mat[i][k] + mat[k][i];
            }

            l = n - 1;
            for(k = l; k > i; k--)
            {
                if(k == l)
                    sum += mat[k][l];
                else
                    sum += mat[k][l] + mat[l][k];
            }
            printf(" %d", sum);
        }
        printf("\n");
    }
    return 0;
}


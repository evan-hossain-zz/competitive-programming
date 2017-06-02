#include<stdio.h>

int main()
{
    int weights[33];
    int p, q, n, i, tst, res, j, cnt;
    scanf("%d", &tst);
    for(j = 1; j <= tst; j++)
    {
        res = 0;
        scanf("%d %d %d", &n, &p , &q);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &weights[i]);
        }
        for(i = 0; i < n; i++)
        {
            if(i >= p || weights[i]+res > q)
                break;
            else
                res += weights[i];
        }
        printf("Case %d: %d\n", j, i);
    }
    return 0;
}

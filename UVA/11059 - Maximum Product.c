#include<stdio.h>

int main()
{
    int i, tst, cnt = 0, flag, n;
    long long res, rsn;
    while(scanf("%d", &tst) == 1)
    {
        res = rsn = 1;
        flag = 0;
        for(i = 0; i < tst; i++)
        {
            scanf("%d", &n);
            if(n > 0)
            {
                res *= n;
                flag++;
            }
        }
        if(flag == 0)
            res = 0;
        printf("Case #%d: The maximum product is %lld\n\n", ++cnt, res);
    }
    return 0;
}

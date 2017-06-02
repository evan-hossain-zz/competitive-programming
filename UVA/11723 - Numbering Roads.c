#include<stdio.h>

int main()
{
    int r, n, i;
    for(i = 1;i <= 100000; i++)
    {
        scanf("%d %d", &r, &n);
        if(r == 0)
            break;
        else if(n == 0 || r / n > 26)
            printf("Case %d: impossible\n", i);
        else
        {
            if(r % n == 0)
                printf("Case %d: %d\n", i, (r / n) - 1);
            else
                printf("Case %d: %d\n", i, (r / n));
        }
    }
    return 0;
}

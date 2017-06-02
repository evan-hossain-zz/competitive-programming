#include<stdio.h>

int main()
{
    long long n, m, ans[1000];
    int i, j, flag;
    while(scanf("%lld %lld", &n, &m) == 2)
    {
        if(n < 2 || m < 2 || (n < m))
        {
            printf("Boring!\n");
            continue;
        }
        i = flag = 0;
        while(1)
        {
            if(n % m != 0)
            {
                printf("Boring!\n");
                flag = 1;
                break;
            }
            else
                ans[i++] = n;
            n = n / m;
            if(n == 1)
            {
                ans[i++] = n;
                break;
            }
        }
        if(flag == 0)
        {
            for(j = 0; j < i - 1; j++)
                printf("%lld ", ans[j]);
            printf("%lld\n", ans[i - 1]);
        }
    }
    return 0;
}

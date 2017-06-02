#include<stdio.h>

int main()
{
    int i, j, tst;
    long long n, in;
    scanf("%d", &tst);
    for(i = 1; i <= tst; i++)
    {
        scanf("%lld", &n);
        in = n;
        j = 0;
        while(1)
        {
            if(n == 1)
            {
                printf("Case #%d: %lld is a Happy number.\n", i, in);
                break;
            }
            if(n < 10)
                n = n * n;
            if(n < 10)
            {
                printf("Case #%d: %lld is an Unhappy number.\n", i, in);
                break;
            }
            else
            {
                while(n)
                {
                    j += (n % 10)*(n % 10);
                    n = (n / 10);
                }
                if(j < 10)
                {
                    if(j == 1)
                    {
                        printf("Case #%d: %lld is a Happy number.\n", i, in);
                        break;
                    }
                    else
                    {
                        printf("Case #%d: %lld is an Unhappy number.\n", i, in);
                        break;
                    }
                }
                else
                {
                    n = j;
                    j = 0;
                    continue;
                }
            }
        }
    }
    return 0;
}

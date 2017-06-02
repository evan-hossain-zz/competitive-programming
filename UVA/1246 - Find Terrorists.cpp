#include <stdio.h>
#include <math.h>

char primes[65];
int dp[10010];

int divisors(int a)
{
    if(dp[a] != 0)
        return dp[a];
    int cnt = 1, i, n, ret = 1;
    n = a;
    while(!(n & 1))
    {
        cnt++;
        n = n >> 1;
    }
    ret *= cnt;
    for(i = 3; n >= i; i += 2)
    {
        cnt = 1;
        while(n % i == 0)
        {
            cnt++;
            n = n / i;
        }
        ret *= cnt;
    }
    if(n > 1)
        ret = ret << 1;
    dp[a] = ret;
    return dp[a];
}
int main()
{
    int l, h, n, i, j;
    primes[1] = 1;
    for(i = 4; i <= 65; i += 2)
        primes[i] = 1;
    for(i = 2; i < 65 / i; i++)
    {
        if(primes[i] != 1)
        {
            for(j = 2; j * i < 65; j++)
                primes[i * j] = 1;
        }
    }
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &l, &h);
        i = 0;
        while(l <= h)
        {
            if(primes[divisors(l)] == 1)
                l++;
            else
                {
                    if(i == 1)
                        printf(" ");
                    i = 1;
                    printf("%d", l);
                    l++;
                }
        }
        if(i == 0)
            printf("-1");
        printf("\n");
    }
    return 0;
}


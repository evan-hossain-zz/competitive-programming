#include<stdio.h>
#include<math.h>

char primes[32000];

int main()
{
    int i, j;
    primes[1] = 1;
    for(i = 4; i <= 32000; i += 2)
        primes[i] = 1;
    for(i = 2; i < 32000 / i; i++)
    {
        if(primes[i] != 1)
        {
            for(j = 2; j * i < 32000; j++)
                primes[i * j] = 1;
        }
    }
    double cnt, res, limit;
    long long n, num;
    while(scanf("%lld", &n) == 1 && n)
    {
        if(n == 1)
        {
            printf("0\n");
            continue;
        }
        cnt = 0;
        res = n;
        while(!(n & 1))
        {
            n = n >> 1;
            if(cnt == 0)
                res *= (1 - (1 / (double)2));
            cnt++;
        }
        for(i = 3; i * i <= n; i += 2)
        {
            if(primes[i] != 1)
            {
                cnt = 0;
                while(n % i == 0)
                {
                    n = n / i;
                    if(cnt == 0)
                        res *= (1 - (1 / (double)i));
                    cnt++;
                }
            }
        }
        if(n > 1)
            res *= (1 - (1 / (double)(n)));
        printf("%.lf\n", res);
    }
    return 0;
}

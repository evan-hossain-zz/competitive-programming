#include<stdio.h>

char primes[1000050];
int main()
{
    int i, j, n, cnt, lmt, p;
    double ans;
    for(i = 4; i <= 1000050; i += 2)
        primes[i] = '1';
    for(i = 2; i < 1000050 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 1000050; j++)
                primes[i * j] = '1';
        }
    }
    while(scanf("%d", &n) == 1 && n)
    {
        printf("%d : ", n);
        p = 0;
        cnt = 0;
        if(primes[n] == 0)
            printf("1\n");
        else
        {
            while(n % 2 == 0)
            {
                if(p == 0) cnt++;
                p++;
                n = n >> 1;
            }
            for(i = 3; i <= n; i += 2)
            {
                if(primes[i] == 0)
                {
                    p = 0;
                    while(n % i == 0)
                    {
                        if(p == 0) cnt++;
                        p++;
                        n = n / i;
                        if(n == 1) break;
                    }
                }
                if(n == 1) break;
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}

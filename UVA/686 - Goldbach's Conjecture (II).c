#include<stdio.h>

char primes[35000];
int main()
{
    int i, j, cnt, n;
    for(i = 4; i <= 35000; i += 2)
        primes[i] = '1';
    for(i = 2; i < 35000 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 35000; j++)
                primes[i * j] = '1';
        }
    }
    while(scanf("%d", &n) == 1 && n)
    {
        cnt = 0;
        if(n == 4)
        {
            printf("1\n");
            continue;
        }
        for(i = 3; i <= n >> 1; i += 2)
        {
            if(primes[n - i] == 0 && primes[i] == 0)
                cnt++;
        }
            printf("%d\n", cnt);
    }
    return 0;
}


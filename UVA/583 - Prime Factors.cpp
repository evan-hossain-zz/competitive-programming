#include<stdio.h>
#include<math.h>

char primes[46350];

int main()
{
    int i, j;
    primes[1] = '1';
    for(i = 4; i <= 46350; i += 2)
        primes[i] = '1';
    for(i = 2; i < 46350 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 46350; j++)
                primes[i * j] = '1';
        }
    }
    int n, limit;
    while(scanf("%d", &n) == 1 && n)
    {
        if(n < 0)
        {
            n *= -1;
            printf("-%d = -1 x ", n);
        }
        else if(n == 1)
        {
            printf("1 =\n");
            continue;
        }
        else
            printf("%d = ", n);
        limit = sqrt(n);
        while(!(n & 1))
        {
            n = n >> 1;
            if(n == 1)
                printf("2\n");
            else
                printf("2 x ");
        }
        for(i = 3; i <= limit; i += 2)
        {
            if(primes[i] != '1')
            {
                while(n % i == 0)
                {
                    n /= i;
                    if(n == 1)
                        printf("%d\n", i);
                    else
                        printf("%d x ", i);
                }
            }
        }
        if(n > 1)
            printf("%d\n", n);
    }
    return 0;
}

#include<stdio.h>

char primes[1000001];
int main()
{
    int i, j;
    for(i = 4; i <= 1000001; i += 2)
        primes[i] = '1';
    for(i = 2; i < 1000001 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 1000001; j++)
                primes[i * j] = '1';
        }
    }
    int n, flag;
    while(scanf("%d", &n) == 1 && n)
    {
        flag = 0;
        for(i = 3; i <= n / 2; i += 2)
        {
            if(primes[n - i] == 0 && primes[i] == 0)
            {
                printf("%d = %d + %d\n", n, i, n - i);
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}

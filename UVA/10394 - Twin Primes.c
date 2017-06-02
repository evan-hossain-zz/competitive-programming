#include<stdio.h>

char primes[19000000];
int twins[100001];
int main()
{
    int i, j, n;
    double ans;
    for(i = 4; i <= 19000000; i += 2)
        primes[i] = '1';
    for(i = 2; i < 19000000 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 19000000; j++)
                primes[i * j] = '1';
        }
    }
    for(i = 3, j = 1; j < 100001; i++)
    {
        if(primes[i] == 0 && primes[i + 2] == 0)
                twins[j++] = i;
    }
    while(scanf("%d", &n) == 1)
        printf("(%d, %d)\n", twins[n], twins[n] + 2);
    return 0;
}

#include<stdio.h>
#include<math.h>

char primes[1000000], reverse[1000000];
int main()
{
    int i, j, n, cnt, k;
    for(i = 4; i <= 1000000; i += 2)
        primes[i] = '1';
    for(i = 3; i < 1000000000000llu / i; i = i + 2)
    {
        for(j = i * i; j < 1000000000000llu / j; j += 2 * i)
        {
            if(primes[j] == '\0')
                primes[j] = '1';
        }
    }
    while(scanf("%d", &n) == 1)
    {
        if(primes[n] == '1')
            printf("%d is not prime.\n", n);
        else if(n > 9)
        {
            k = n;
            cnt = 0;
            j = 1;
            for(i = 0; ; ++i)
            {
                cnt++;
                j = k / 10;
                reverse[i] = k % 10 + '0';
                if(j == 0)
                {
                    reverse[i] = k + '0';
                    break;
                }
                k = j;
            }
            cnt = cnt - 1;
            j = 0;
            for(i = 0; cnt >= 0; cnt--)
            {
                j += (reverse[i++] - '0') * pow(10, cnt);

            }
            if(primes[j] == '\0' && j != n)
                printf("%d is emirp.\n", n);
            else
                printf("%d is prime.\n", n);
        }
        else
            printf("%d is prime.\n", n);
    }
    return 0;
}

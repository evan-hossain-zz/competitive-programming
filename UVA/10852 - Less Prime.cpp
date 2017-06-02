#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

char primes[10050];
int main()
{
    int i, j, k, l, p, n, x, tst;
    for(i = 4; i < 10050; i += 2)
        primes[i] = 1;
    l = sqrt(10050);
    for(i = 3; i < l + 1; i += 2)
    {
        if(primes[i] != 1)
        {
            for(j = 3; i * j < 10050; j += 2)
                primes[i * j] = 1;
        }
    }
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d", &n);
        for(i = (n >> 1) + 1; i <= n; i++)
        {
            if(primes[i] != 1)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}

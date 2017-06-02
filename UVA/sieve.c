#include<stdio.h>

bool primes[1000000];

int sieve()
{
    int i, j;
    primes[1] = 1;
    for(i = 4; i <= 1000000; i += 2)
        primes[i] = 1;
    for(i = 3; i < 1000000 / i; i += 2)
    {
        if(primes[i] != 1)
        {
            for(j = 2; j * i < 1000000; j++)
                primes[i * j] = 1;
        }
    }
}

int main()
{
    sieve();
    return 0;
}


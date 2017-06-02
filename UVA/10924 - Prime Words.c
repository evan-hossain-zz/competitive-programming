#include<stdio.h>

char primes[1100];
int main()
{
    int i, j, sum = 0;
    for(i = 4; i <= 1100; i += 2)
        primes[i] = '1';
    for(i = 2; i < 1100 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 1100; j++)
                primes[i * j] = '1';
        }
    }
    char ch;
    while(scanf("%c", &ch) == 1)
    {
        if(ch == '\n')
        {
            if(primes[sum] == '1')
                printf("It is not a prime word.\n");
            else
                printf("It is a prime word.\n");
                sum = 0;
        }
        else
        {
            if(ch >= 'A' && ch <= 'Z')
                sum += ch - 38;
            else
                sum += ch - 96;
        }
    }
    return 0;
}

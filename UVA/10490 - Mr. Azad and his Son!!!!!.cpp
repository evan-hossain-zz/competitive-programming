#include<cstdio>
#include<string.h>

char primes[32];
char ans[32][20] = {"0", "1", "6", "28", "0",\
"496", "0", "8128", "0", "0","0", "0", "0",\
"33550336", "0", "0", "0", "8589869056", "0",\
"137438691328", "0", "0", "0","0", "0", "0", "0",\
"0", "0", "0", "0", "2305843008139952128"};

int main()
{
    int i, j;
    for(i = 4; i <= 32; i += 2)
        primes[i] = '1';
    for(i = 2; i < 32 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 32; j++)
                primes[i * j] = '1';
        }
    }
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        if(primes[n] == '1')
            printf("Given number is NOT prime! \
NO perfect number is available.\n");
        else if(strcmp(ans[n], "0") == 0)
            printf("Given number is prime. But, \
NO perfect number is available.\n");
        else
            printf("Perfect: %s!\n", ans[n]);
    }
    return 0;
}

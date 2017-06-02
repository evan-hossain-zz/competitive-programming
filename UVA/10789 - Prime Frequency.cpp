#include<cstdio>
#include<cstring>

char primes[2002], str[2005];
int main()
{
    int i, j, test, ans[125], l, flag;
    primes[0] = primes[1] = 1;
    for(i = 4; i < 2003; i += 2)
        primes[i] = 1;
    for(i = 3; i < 45; i++)
    {
        if(primes[i] != 1)
        {
            for(j = 2; i * j < 2003; j++)
                primes[i * j] = 1;
        }
    }
    scanf("%d", &test);
    i = 0;
    while(test--)
    {
        flag = 0;
        int ans[125] = {0};
        scanf(" %s", str);
        l = strlen(str);
        while(l--)
            ans[str[l]]++;
        printf("Case %d: ", ++i);
        l = 0;
        for(j = 48; j < 123; j++)
        {
            if(primes[ans[j]] != 1)
            {
                printf("%c", j);
                flag = 1;
            }
        }
        if(flag == 0)
            printf("empty");
        printf("\n");
    }
    return 0;
}

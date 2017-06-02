#include<cstdio>

char primes[1000001];
int dp[1000000], cnt;
int main()
{
    int i, j;
    for(i = 4; i <= 1000001; i += 2)
        primes[i] = 1;
    for(i = 2; i < 1000001 / i; i++)
    {
        if(primes[i] != 1)
        {
            for(j = 2; j * i < 1000001; j++)
                primes[i * j] = 1;
        }
    }
    int tst, t1, t2, temp, sum;
    t1 = 2;
    while(1)
    {
        if(primes[t1] != 1)
        {
            sum = 0;
            temp = t1;
            while(1)
            {
                sum += temp % 10;
                temp = temp / 10;
                if(temp == 0)
                    break;
            }
            if(primes[sum] != 1)
                cnt++;
        }
        dp[t1] = cnt;
        t1++;
        if(t1 > 1000000) break;
    }
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d %d", &t1, &t2);
        printf("%d\n", dp[t2] - dp[t1 - 1]);
    }
    return 0;
}

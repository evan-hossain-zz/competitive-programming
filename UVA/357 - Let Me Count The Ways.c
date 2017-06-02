#include<stdio.h>
#include<string.h>

int coins[5] = {1, 5 , 10, 25, 50};
int main()
{
    int n, m, i, j, cents, flag = 0, k;
    while(scanf("%d", &n) == 1)
    {
        long long dp[30005] = {1};
        for(i = 0; i < 5; i++)
        {
            for(j = coins[i], k = 0; j <= n; j++, k++)
                dp[j] += dp[k];
        }
        printf("There are %lld ways to produce %d cents change. \n", dp[n], n);
    }
    return 0;
}

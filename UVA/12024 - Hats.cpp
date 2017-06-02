#include<cstdio>

int dp[15];
double ans;
int fact(int n);

int main()
{
    int i, j, tst, t;
    scanf("%d", &tst);
    while(tst--)
    {
        ans = 0;
        scanf("%d", &t);
        for(i = 0; i <= t; i++)
        {
            if(i % 2 == 0)
                ans += (1 / (double)fact(i));
            else
                ans -= (1 / (double)fact(i));
        }
        printf("%.lf/%d\n", ans * (double)fact(t), fact(t));
    }
    return 0;
}

int fact(int n)
{
    if(n <= 0 || n == 1)
        return 1;
    else if(dp[n] != 0)
        return dp[n];
    else
    {
        dp[n] = n * fact(n - 1);
        return dp[n];
    }
}

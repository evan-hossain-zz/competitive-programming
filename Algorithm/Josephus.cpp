int dp[SZ][SZ];
int find_survivour(int n, int k)
{
    if(n == 1)
        return 1;
    if(dp[n][k])
        return dp[n][k];
    return dp[n][k] = ((find_survivour(n - 1, k) + k - 1) % n) + 1;
}

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        cout << find_survivour(n, k) << endl;
    }
    return 0;
}


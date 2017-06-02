int arr[SZ][SZ];

int max_sum(int n, int r)
{
    int i, j, m = 0, sum = 0;
    for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= r; j++)
                    arr[i][j] += arr[i][j - 1];
        }
    for(int c1 = 1; c1 <= r; c1++)
        {
            for(int c2 = c1; c2 <= r; c2++)
                {
                    sum = 0;
                    for(int r = 1; r <= n; r++)
                        {
                            sum += (arr[r][c2] - arr[r][c1 - 1]);
                            if(sum < 0)
                                sum = 0;
                            else if(sum > m)
                                m = sum;
                        }
                }
        }
    return m;
}

int main()
{
    int n, i, j, k;
    while(scanf("%d %d", &n, &r) == 2 && n)
        {
            for(i = 0; i < n; i++)
                arr[i][0] = arr[0][i] = 0;
            for(i = 1; i <= n; i++)
                {
                    for(j = 1; j <= r; j++)
                        scanf("%d", &arr[i][j]);
                }
            printf("%d\n", max_sum(n, r));
        }
    return 0;
}

#include<cstdio>

int queue[52];
int main()
{
    int j, k, n, ans, i, cnt;
    while(scanf("%d", &n) == 1 && n)
    {
        ans = 1;
        int queue[52] = {0};
        cnt = 0;
        for(i = 0; i < n; i++)
            queue[i] = i + 1;
        printf("Discarded cards:");
        while(n != 1)
        {
            if(cnt == 0)
                printf(" %d", queue[0]);
            else
                printf(", %d", queue[0]);
            ans = queue[1];
            if(queue[2] == 0) break;
            for(j = 2; ; j++)
            {
                queue[j - 2] = queue[j];
                if(queue[j] == 0) break;
                queue[j] = 0;
            }
            queue[j-2] = ans;
            cnt = 1;
        }
        printf("\nRemaining card: %d\n", ans);
    }
    return 0;
}

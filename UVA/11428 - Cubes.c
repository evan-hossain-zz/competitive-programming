#include<stdio.h>

int main()
{
    register int i, cnt, j;
    int n;
    while(scanf("%d", &n) == 1 && n != 0)
    {
        cnt = 0;
        for(i = 0; i <= 100; ++i)
        {
            for(j = 0; j < i; ++j)
            {
                if(n == i*i*i - j*j*j)
                {
                    cnt++;
                    break;
                }
            }
            if(cnt != 0)
                break;
        }
        if(cnt == 0)
            printf("No solution\n");
        else
            printf("%d %d\n", i, j);
    }
    return 0;
}

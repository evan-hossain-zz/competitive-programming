#include<stdio.h>

int main()
{
    int i, n, res;

    while(scanf("%d", &n) == 1 && n != 0)
    {
        res = 0;
        for(i = 1; i <= n; i++)
        {
            res = res + (i * i);
        }
        printf("%d\n", res);
    }
    return 0;
}

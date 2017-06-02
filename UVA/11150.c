#include<stdio.h>

int main()
{
    int res, n, i, j, p;

    while(scanf("%d", &n) == 1)
    {
        j = 0;
        i = n;
        res = 0;
        p = n;
        while(i)
        {
            i = n / 3;
            j = n % 3;
            n = i + j;
            res = res + i;
        }
        printf("%d\n", res + j - 1 + p);
    }
    return 0;
}


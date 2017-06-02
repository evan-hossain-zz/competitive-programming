#include<stdio.h>

int main()
{
    int res, n, i, j;

    while(scanf("%d", &n) == 1 && n != 0)
    {
        j = 0;
        i = n;
        res = 0;
        while(i)
        {
            i = n / 5;
            j = n % 5;
            n = i + j;
            res = res + i;
        }
        printf("%d\n", res + j - 1);
    }
    return 0;
}

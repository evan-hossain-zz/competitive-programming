#include<stdio.h>

int main()
{
    int res, n, i, j, e, f, l, tst;
    scanf("%d", &tst);

    while(tst--)
    {
        scanf("%d %d %d", &e, &f, &l);
        j = 0;
        n = e + f;
        i = n;
        res = 0;
        while(i)
        {
            i = n / l;
            j = n % l;
            n = i + j;
            res = res + i;
        }
        printf("%d\n", res);
    }
    return 0;
}


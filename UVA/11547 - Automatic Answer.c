#include<stdio.h>


int main()
{
    int tst, n;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d", &n);
        n = n * 567;
        n = n / 9;
        n = n + 7492;
        n = n * 235;
        n = n / 47;
        n = n - 498;
        n = n /10;
        n = n % 10;
        if(n < 0)
            n = -n;
        printf("%d\n", n);
    }
    return 0;
}


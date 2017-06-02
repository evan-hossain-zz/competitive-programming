#include<stdio.h>

int main()
{
    int tst, x;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d", &x);
        if(x % 2 == 0)
            printf("%d %d\n", x / 2, x / 2);
        else
            printf("%d %d\n", x / 2, x / 2 + 1);
    }
    return 0;
}

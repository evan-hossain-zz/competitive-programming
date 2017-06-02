#include<stdio.h>

int main()
{
    int i, tst, s, d, a, b;
    scanf("%d", &tst);
    for(i = 0; i < tst; i++)
    {
        scanf("%d %d", &s, &d);
        a = (s + d);
        b = (s - d);
        if(s < d || (a % 2) != 0 || (b % 2) != 0)
            printf("impossible\n");
        else
            printf("%d %d\n", a / 2, b / 2);
    }
    return 0;
}

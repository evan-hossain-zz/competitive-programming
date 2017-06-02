#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) == 2)
    {
        if(a == -1 && b == -1) break;
        a = abs(a - b);
        if(a < 50)
            printf("%d\n", a);
        else
            printf("%d\n", 100 - a);
    }
    return 0;
}

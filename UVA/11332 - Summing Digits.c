#include<stdio.h>

int main()
{
    int n, div;
    while(scanf("%d", &n) == 1 && n != 0)
    {
        div = 1;
        while(div)
        {
            div = n / 10;
            n = (n%10)* (n % 10);
        }
        printf("%d\n", n);
    }
    return 0;
}

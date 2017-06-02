#include<stdio.h>

int main()
{
    int a, b, c, i, temp;

    while(scanf("%d %d %d", &a, &b, &c) == 3)
    {
        if(a == 0 && b == 0 && c == 0)
            break;
        if(a > b && a > c)
        {
            temp = a;
            a = c;
            c = temp;
        }
        else if(b > a && b > c)
        {
            temp = b;
            b = c;
            c = temp;
        }
        if(a <= 0 || b <= 0 || c <= 0)
            printf("wrong\n");

        else if(a * a + b * b == c * c)
            printf("right\n");

        else
            printf("wrong\n");
    }
    return 0;
}

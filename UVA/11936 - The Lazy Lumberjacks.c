#include<stdio.h>

int main()
{
    int n, a, b, c;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a + b <= c || b + c <= a || c + a <= b)
            printf("Wrong!!\n");
        else
            printf("OK\n");
    }
    return 0;
}

#include<stdio.h>

int f91(int x);

int main()
{
    int i, res, n;
    while(scanf("%d", &n) && n != 0)
    {
        res = f91(n);
        printf("f91(%d) = %d\n", n, res);
    }
    return 0;
}

int f91(int x)
{
    if (x <= 100)
    {
        x = f91(x + 11);
        return (f91(x));
    }
    else if(x >= 101)
        return (x - 10);
}

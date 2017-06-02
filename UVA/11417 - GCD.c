#include<stdio.h>

int gcd(int a, int b);

int main()
{
    int i, j, n, g;
    while(scanf("%d", &n) == 1 && n != 0)
    {
        g = 0;
        for(i=1; i < n; i++)
        {
            for(j = i + 1; j <= n; j++)
                g += gcd(i, j);
        }
        printf("%d\n", g);
    }
    return 0;
}

int gcd(int a, int b)
{
    if(b % a == 0)
        return a;
    else
        return gcd(b, a % b);
}

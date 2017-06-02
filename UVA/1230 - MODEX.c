#include<stdio.h>

int m, res = 1;
int mod(int b, int p);
int main()
{
    int b, p, tst, n;
    while(scanf("%d", &tst) == 1 && tst)
    {
        while(tst--)
        {
            scanf("%d %d %d", &b, &p, &m);
            printf("%d\n", mod(b, p));
        }
    }
    return 0;
}

int mod(int b, int p)
{
    if(p == 0) return 1;
    if(p % 2 == 0)
    {
        res = mod(b, p / 2) % m;
        return ((res % m) * (res % m)) % m;
    }
    else
        return ((b % m) * mod(b, p - 1) % m) % m;
}


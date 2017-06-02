#include<stdio.h>

int min(int x, int y, int z);

int main()
{
    int tst_cs, t1, t2, fnl, atdnc, ct1, ct2, ct3, i, j, res;
    double avg;
    scanf("%d", &tst_cs);

    for(i = 1; i <= tst_cs; i++)
    {
        scanf("%d %d %d %d %d %d %d", &t1, &t2, &fnl, &atdnc, &ct1, &ct2, &ct3);
        avg = min(ct1, ct2, ct3);
        res = t1 + t2 + fnl + atdnc + avg;
        if(res >= 90)
            printf("Case %d: A\n", i);
        else if(res >= 80 && res < 90)
            printf("Case %d: B\n", i);
        else if(res >= 70 && res < 80)
            printf("Case %d: C\n", i);
        else if(res >= 60 && res < 70)
            printf("Case %d: D\n", i);
        else
            printf("Case %d: F\n", i);
    }
    return 0;
}

int min(int x, int y, int z)
{
    if(x > y && z > y)
        return ((x + z) / 2);
    else if(y > x && z > x)
        return ((y + z) / 2);
    else if(x > z && y > z)
        return ((x + y) / 2);
    else if(x == y)
        return ((x + z) / 2);
    else if(x == z)
        return ((x + y) / 2);
    else if(y == z)
        return ((z + x) / 2);
    else
        return (x / 2);
}

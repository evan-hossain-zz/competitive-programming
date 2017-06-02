#include<stdio.h>
#include<math.h>

int main()
{
    int tst, i;
    double d, v, u;
    scanf("%d", &tst);
    for(i = 1; i <= tst; ++i)
    {
        scanf("%lf %lf %lf", &d, &v, &u);
        d = d * ((1 / sqrt(u * u - v * v)) - (1 / u));
        if(v == 0 || u == 0 || u <= v)
            printf("Case %d: can't determine\n", i);

        else
            printf("Case %d: %.3lf\n", i, d);
    }
    return 0;
}

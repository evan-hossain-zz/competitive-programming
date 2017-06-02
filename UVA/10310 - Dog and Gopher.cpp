#include<cstdio>
#include<cmath>

int main()
{
    double x, y, tx, ty, gx, gy, dx, dy;
    int n, flag;
    while(scanf("%d", &n) == 1)
    {
        flag = 0;
        scanf("%lf %lf %lf %lf", &gx, &gy, &dx, &dy);
        while(n--)
        {
            scanf("%lf %lf", &tx, &ty);
            if(flag == 0 && ((sqrt((tx - gx) * (tx - gx)
            + (ty - gy) * (ty - gy)) * 2)
            <=sqrt((tx - dx) * (tx - dx) + (ty - dy) * (ty - dy))))
            {
                x = tx;
                y = ty;
                flag = 1;
            }
        }
        if(flag == 1)
            printf("The gopher can escape through \
the hole at (%.3lf,%.3lf).\n", x, y);
        else
            printf("The gopher cannot escape.\n");
    }
    return 0;
}

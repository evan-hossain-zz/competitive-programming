#include<stdio.h>
#include<math.h>
#define PI (2 * acos(0)) / 180

int main()
{
    double res, h1, l, w, h, ang;
    while(scanf("%lf %lf %lf %lf", &l, &w, &h, &ang) == 4)
    {
        ang = 90 - ang;
        ang = tan(PI * ang);
        if(l / ang > h)
            printf("%.3lf mL\n", h * ang * w * h * .5);
        else if(ang)
        {
            h1 = h - (l / ang);
            printf("%.3lf mL\n", .5 * (h + h1) * l * w);
        }
        else
            printf("%.3lf mL\n", l * h * w);
    }
    return 0;
}

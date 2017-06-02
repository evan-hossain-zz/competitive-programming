#include<stdio.h>
#include<math.h>

int main()
{
    double u, v, w, res;
    while(scanf("%lf %lf %lf", &u, &v, &w) == 3)
    {
        res = (sqrt(2 * (u*u*v*v+v*v*w*w+w*w*u*u) - (u*u*u*u+v*v*v*v+w*w*w*w))) / 3;
        if(res > 0)
            printf("%.3lf\n", res);
        else
            printf("-1.000\n");
    }
    return 0;
}

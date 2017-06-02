#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 4.0/3.142

int main()
{
    double d, v, D;
    while(scanf("%lf %lf", &D, &v) == 2.0)
    {
        if(D == 0 && v == 0)
            break;
        else
        {
            v = D * D * D - (v * PI);
        d = pow(v, 1.0/3.0);
        printf("%.3lf\n", d);
        }
    }
    return 0;
}

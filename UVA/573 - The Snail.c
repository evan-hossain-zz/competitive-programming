#include<stdio.h>

int main()
{
    double h, d, f, u, tc, ip;
    char flag;
    register int day;
    while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f) == 4
          && h != 0.0)
    {
        f = u * (f / 100);
        day = ip = 0;
        while(1)
        {
            day++;
            tc = u + ip;
            if(tc > h)
            {
                flag = 1;
                break;
            }
            ip = tc - d;
            if(ip < 0)
            {
                flag = 0;
                break;
            }
            else if(ip > h)
            {
                flag = 1;
                break;
            }
            if(u >= f)
                u = u - f;
        }
        if(flag == 0)
            printf("failure on day %d\n", day);
        else
            printf("success on day %d\n", day);
    }
    return 0;
}

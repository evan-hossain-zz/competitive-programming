#include<stdio.h>
#include<math.h>
#define PI 2 * acos(0)


int main()
{
    int i = 0, j, k, test;
    double ans, s, area_of_rctngl, kon, x1, x2, r1, y1, y2, r2, dis;
    scanf("%d", &test);
    while(test--)
    {
        kon = 0.0;
        ans = 0.0;
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
        dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        if(dis < r1)
        {
            printf("Case %d: %lf\n", ++i, PI * r2 * r2);
            continue;
        }
        else if(dis < r2)
        {
            printf("Case %d: %lf\n", ++i, PI * r1 * r1);
            continue;
        }
        else if(dis >= (r1 + r2))
        {
            printf("Case %d: %lf\n", ++i, ans);
            continue;
        }
        s = (r1 + r2 + dis) / 2.0;
        area_of_rctngl = sqrt(s * (s - r1) * (s - r2) * (s - dis)) * 2.0;
        kon = acos((r1 * r1 + dis * dis - r2 * r2) / (2 * r1 * dis)) * 2.0;
        ans = r1 * r1 * kon / 2.0;
        kon = acos((r2 * r2 + dis * dis - r1 * r1) / (2 * r2 * dis)) * 2.0;
        ans += (r2 * r2 * kon / 2.0) - area_of_rctngl;
        printf("Case %d: %lf\n", ++i, ans);
    }
    return 0;
}

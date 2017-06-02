#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int n;
    double xy[10002][2], ans, temp;
    register int j, k, i;
    while(scanf("%d", &n) == 1 && n)
    {
        ans = 100000000.0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < 2; j++)
            {
                scanf("%lf", &xy[i][j]);
            }
        }
        for(i = 0; i < n - 1; i++)
        {
            for(k = i; k < n - 1; k++)
            {
                for(j = 0; j < 1; j++)
                {
                    temp = (xy[i][j] - xy[k + 1][j]) *
                           (xy[i][j] - xy[k + 1][j]) + (xy[i][j + 1] -
                                                        xy[k + 1][j + 1]) * (xy[i][j + 1] - xy[k + 1][j + 1]);
                    if(temp < ans)
                        ans = temp;
//                    printf("%d %d %lf\n", i, k + 1, temp);
                }
            }
        }
//        printf("%lf\n", ans);
        ans = sqrt(ans);
//        printf("%lf\n", ans);
        if (ans < 10000.0 || fabs(ans - 10000.0) > 1e-7)
            printf("%.4lf\n", ans);
        else
            printf("INFINITY\n");
    }
    return 0;
}

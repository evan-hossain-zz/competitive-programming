#include<stdio.h>

int main()
{
    int m, h[101], n, i, set = 0, sum;
    while(scanf("%d", &n) == 1 && n != 0)
    {
        sum = m = 0;
        printf("Set #%d\n", ++set);
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &h[i]);
            sum += h[i];
            m++;
        }
        m = sum / m;
        sum = 0;
        for(i = 0; i < n; ++i)
        {
            if(h[i] > m)
                sum += h[i] - m;
        }
        printf("The minimum number of moves is %d.\n\n", sum);
    }
    return 0;
}

#include<cstdio>

int main()
{
    int n, b, h, w, p, a, i, j, k, min, ans;

    while(scanf("%d %d %d %d", &n, &b, &h, &w) == 4)
    {
        i = 0;
        int week[15] = {0};
        ans = 100000010;
        while(i < h)
        {
            j = 0;
            scanf("%d", &p);
            min = n * p;
            while(j < w)
            {
                scanf("%d", &week[j]);
                if(b >= min && n <= week[j] && min < ans)
                    ans = min;
                j++;
            }
            i++;
        }
        if(ans == 100000010)
            printf("stay home\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}

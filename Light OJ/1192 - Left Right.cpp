#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int i, n, k, arr[220], kase, t, g, w;
    scanf("%d", &t);
    for(kase = 1; kase <= t; kase++)
    {
        scanf("%d", &n);
        scanf("%d %d", &g, &w);
        int ans = (abs(g - w) - 1);
        for(i = 1; i < n; i++)
        {
            scanf("%d %d", &g, &w);
            ans ^= (abs(g - w) - 1);
        }
        if(ans)
            printf("Case %d: Alice\n", kase);
        else
            printf("Case %d: Bob\n", kase);
    }
    return 0;
}

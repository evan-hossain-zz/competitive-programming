#include<stdio.h>
#include<math.h>

int main()
{
    int s, e, i, cnt;
    float r;
    while(scanf("%d %d", &s, &e) == 2)
    {
        if(s == 0 && e == 0)
            break;
        cnt = 0;
        for(i = s; i <= e; i++)
        {
            r = sqrt(i);
            if(r - (int)r == 0)
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

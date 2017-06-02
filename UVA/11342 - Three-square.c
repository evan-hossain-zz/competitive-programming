#include<stdio.h>
#include<math.h>

int main()
{
    register int cnt, b, c, d, s;
    int n , tst;
    scanf("%d", &tst);
    while(tst--)
    {
        cnt = 0;
        scanf("%d", &n);
        if(n % 8 == 7)
            printf("-1\n");
        else
        {
            s = sqrt(n);
            for(b = 0; b <= s; ++b)
            {
                for(c = b; c <= s; ++c)
                {
                    for(d = c; d <= s; ++d)
                    {
                        if(n == b*b+c*c+d*d)
                        {
                            cnt++;
                            break;
                        }
                    }
                    if(cnt > 0)
                        break;
                }
                if(cnt > 0)
                    break;
            }

            if(cnt == 0)
                printf("-1\n");
            else
                printf("%d %d %d\n", b, c, d);
        }
    }
    return 0;
}


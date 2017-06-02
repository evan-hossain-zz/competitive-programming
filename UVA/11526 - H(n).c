#include<stdio.h>
#include<math.h>

int main()
{
    long long cnt, sum, agerta, notunta;
    int i, kase, n, limit;
    scanf("%d", &kase);
    while(kase--)
    {
        sum = 0;
        scanf("%d", &n);
        limit = sqrt(n);
        agerta = n;
        for(i = 1; i <= limit; i++)
        {
            if(limit == (n / i))
            {
                sum += limit;
                break;
            }
            notunta = n / (i + 1);
            sum += (n / i) + (agerta - notunta) * i;
            agerta = notunta;
        }
        printf("%lld\n", sum);
    }
    return 0;
}

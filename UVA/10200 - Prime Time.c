#include<stdio.h>
#include<math.h>

char primes[10001];

int main()
{
    int i, a, b, prime, p, num, c, cnt;
    double ans;
    for(i = 0; i < 10001; i++)
    {
        num = i * i + i + 41;
        if(num & 2 == 0)
            primes[i] = 1;
        else
        {
            p = sqrt(num);
            for(c = 3; c <= p; c += 2)
            {
                if(num % c == 0)
                    primes[i] = 1;
            }
        }
    }
    while(scanf("%d %d", &a, &b) == 2)
    {
        prime = 0;
        for(i = a; i <= b; ++i)
        {
            if(primes[i] == 0)
                prime++;
        }
        ans = (double) prime / (i - a) * 100 + 1e-8;
        printf("%.2lf\n", ans);
    }
    return 0;
}



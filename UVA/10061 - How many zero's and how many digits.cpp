#include<cstdio>
#include<cmath>

char primes[800];

int main()
{
    int num, i, j, base, limit, div, n;
    long long cnt, min;
    double bas, digit;
    primes[1] = '1';
    for(i = 4; i <= 800; i += 2)
        primes[i] = '1';
    for(i = 2; i < 800 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 800; j++)
                primes[i * j] = '1';
        }
    }
    while(scanf("%d %d", &num, &base) == 2)
    {
        cnt = 0;
        div = 1;
        digit = 0;
        min = 80000;
        limit = sqrt(base);
        bas = base;
        if(primes[base] != '1')
        {
            div = base;
            min = 1;
        }
        else
        {
            while(!(base & 1))
            {
                base = base >> 1;
                cnt++;
            }
            min = cnt;
            div = 2;
            for(i = 3; i <= limit && base >= i; i += 2)
            {
                cnt = 0;
                if(primes[i] != '1')
                {
                    while(base % i == 0)
                    {
                        base /= i;
                        cnt++;
                    }
                    if(num / i < (num / div))
                    {
                        min = cnt;
                        div = i;
                    }
                }
            }
            if(primes[base] != '1')
            {
                div = base;
                min = 1;
            }
        }
        for(i = num; i > 1; i--)
            digit += (log(i) / log(bas)) + 1e-9;
        cnt = 0;
        num = num / div;
        while(num)
        {
            cnt += num;
            num = num / div;
        }
        printf("%lld %lld\n", cnt / min, (long long)(digit + 1e-9) + 1 );
    }
    return 0;
}

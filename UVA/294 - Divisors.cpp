#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

char primes[32000];
int main()
{
    int i, j, k, test, t1, t2, temp, ans, cnt, limit, max, num;
    for(i = 4; i <= 32000; i += 2)
        primes[i] = '1';
    for(i = 2; i < 32000 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 32000; j++)
                primes[i * j] = '1';
        }
    }
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &t1, &t2);
        printf("Between %d and %d,", t1, t2);
        ans = 1;
        max = 0;
        limit = sqrt(t2) + 1;
        while(1)
        {
            cnt = 0;
            ans = 1;
            temp = t1;
            while(!(temp & 1))
            {
                temp = (temp >> 1);
                cnt++;
            }
            ans *= (cnt + 1);
            cnt = 0;
            for(i = 3; i <= limit; i += 2)
            {
                cnt = 0;
                if(primes[i] != '1')
                {
                    while(temp % i == 0)
                    {
                        temp = temp / i;
                        cnt++;
                    }
                    ans *= (cnt + 1);
                }
            }
            if(ans > max)
            {
                max = ans;
                num = t1;
            }
            if(t1 == t2) break;
            t1++;
        }
        if(max == 1 && t2 > 1) max = 2;
        else if(t2 == 1) max = 1;
        printf(" %d has a maximum of %d divisors.\n", num, max);
    }
    return 0;
}

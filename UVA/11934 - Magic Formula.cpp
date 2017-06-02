#include <iostream>
#include <cstdio>

using namespace std;

long long a, b, c, d, l;
long long ans;
long long func(void);

int main()
{
    while(scanf("%lld %lld %lld %lld %lld",\
                 &a, &b, &c, &d, &l) == 5)
    {
        if(a == 0 && b == 0 && c == 0 && d == 0 && l == 0)
            break;
        printf("%lld\n", func());
    }
    return 0;
}

long long func(void)
{
    long long cnt = 0;
    do
    {
        ans = a * l * l + b * l + c;
        if(ans % d == 0)
            cnt++;
    }while(l--);
    return cnt;
}

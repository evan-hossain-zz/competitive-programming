#include<stdio.h>

int main()
{
    long long n1, n2;
    int carry, cnt, mod;
    while(scanf("%lld %lld", &n1, &n2) == 2 && (n1 || n2))
    {
        carry = cnt = 0;
        while(n1||n2)
        {
            mod = n1 % 10 + n2 % 10 + carry;
            carry = 0;
            if(mod > 9)
            {
                carry = 1;
                cnt++;
            }
            n1 = n1 / 10;
            n2 = n2 / 10;
        }
        if(cnt == 0)
            printf("No carry operation.\n");
        else if(cnt == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", cnt);
    }
    return 0;
}

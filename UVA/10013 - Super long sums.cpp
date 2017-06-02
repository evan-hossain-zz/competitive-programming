#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

char num1[1000010], num2[1000010], res[1000010];
int main()
{
    int a, b, i, j, test, n, carry, r, temp;
    scanf("%d", &test);
    while(test--)
    {
        i = carry = 0;
        scanf("%d", &n);
        while(i < n)
            scanf(" %c %c", &num1[i++], &num2[i]);
        num1[i] = num2[i] = 0;
        i--;
        r = 0;
        for(; i >= 0; i--)
        {
            temp = num2[i] - '0' + num1[i] - '0' + carry;
            carry = 0;
            if(temp > 9)
            {
                res[r++] = temp % 10 + '0';
                carry = 1;
            }
            else
                res[r++] = temp + '0';
        }
        if(carry == 1)
            res[r] = '1';
        else
            r--;
        for(i = r; i >= 0; i--)
            printf("%c", res[i]);
            printf("\n");
        if(test != 0)
            printf("\n");
    }
    return 0;
}

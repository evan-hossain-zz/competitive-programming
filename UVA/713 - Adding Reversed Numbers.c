#include<stdio.h>
#include<string.h>

int main()
{
    char s1[220], s2[220], temp1[220], temp2[220], res[220];
    int i, j, k, l1, l2, carry, temp, test, l;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%s %s", s1, s2);
        l1 = strlen(s1);
        l2 = strlen(s2);
        for(i = l1 - 1, j = 0; i >= 0; i--)
            temp1[j++] = s1[i];
        temp1[j] = 0;
        for(i = l2 - 1, j = 0; i >= 0; i--)
            temp2[j++] = s2[i];
        temp2[j] = 0;
        if(l1 < l2) l = l2;
        else l = l1;
        l1 = l1 - 1;
        l2 = l2 - 1;
        carry = i = 0;
        while(1)
        {
            temp = temp1[l1] - '0' + temp2[l2] - '0' + carry;
            carry = 0;
            if(temp > 9)
            {
                res[i] = temp % 10 + '0';
                carry = 1;
            }
            else
                res[i] = temp + '0';
            i++;
            l--;
            if(l == 0) break;
            if(l1 == 0)
                temp1[l1] = '0';
            else
                l1--;
            if(l2 == 0)
                temp2[l2] = '0';
            else
                l2--;
        }
        if(carry == 1) res[i++] = '1';
        res[i] = 0;
        l1 = strlen(res);
        temp = 0;
        for(i = 0; i < l1; i++)
        {
            if(res[i] == '0' && temp == 0)
                ;
            else
            {
                printf("%c", res[i]);
                temp = 1;
                res[i] = 0;
            }
        }
        printf("\n");
    }
    return 0;
}

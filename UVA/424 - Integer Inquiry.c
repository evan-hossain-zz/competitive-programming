#include<stdio.h>
#include<string.h>

char res[1000], add[1000];

int main()
{
    int i, l, temp, max = 0, carry = 0;
    memset(res, '0', 1000);
    while(scanf(" %s", add) == 1)
    {
        if(strcmp(add, "0") == 0) break;
        l = strlen(add);
        i = 0;
        while(l--)
        {
            temp = (add[l] - '0') + (res[i] - '0') + carry;
            carry = 0;
            if(temp > 9)
            {
                res[i] = (temp % 10) + '0';
                carry = 1;
            }
            else
            {
                res[i] = temp + '0';
                carry = 0;
            }
            i++;
            if(l == 0)
            {
                while(1)
                {
                    temp = res[i] - '0' + carry;
                    if(temp == 0) break;
                    carry = 0;
                    if(temp > 9)
                    {
                        res[i] = (temp % 10) + '0';
                        carry = 1;
                    }
                    else
                        res[i] = temp + '0';
                    i++;
                }
            }
        }
        if(max < i) max = i;
    }
    while(max)
        printf("%c",res[--max]);
    printf("\n");
    return 0;
}

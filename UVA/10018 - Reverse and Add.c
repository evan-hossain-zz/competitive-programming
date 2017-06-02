#include<stdio.h>
#include<string.h>

int cnt, i, l;
int check_palindrome(char test[], int length);
int main()
{
    char num[15], rev[15], palin[15];
    int j, temp, test, carry, flag;
    scanf("%d", &test);
    while(test--)
    {
        cnt = flag = 0;
        scanf(" %s", num);
        while(1)
        {
            cnt++;
            carry = 0;
            l = strlen(num);
            for(i = l - 1, j = 0; i >= 0; i--, j++)
                rev[j] = num[i];
            rev[j] = 0;
            for(i = l - 1, j = 0; i >= 0; i--)
            {
                temp = num[i] - '0' + rev[i] - '0' + carry;
                carry = 0;
                if(temp > 9)
                {
                    palin[j++] = temp % 10 + '0';
                    carry = 1;
                }
                else
                    palin[j++] = temp + '0';
            }
            if(carry == 1)
            {
                palin[j++] = '1';
                palin[j] = 0;
                l = l + 1;
            }
            else
                palin[j] = 0;
            for(i = l - 1, j = 0; i >= 0; i--, j++)
                num[j] = palin[i];
            num[j] = 0;
            flag = check_palindrome(num, l);
            if(flag == 1)
            {
                i = 0;
                printf("%d %s\n", cnt, palin);
                break;
            }
        }
    }
    return 0;
}

int check_palindrome(char test[], int length)
{
    if(length == 1)
        return 1;
    int t = length;
    if(i == l << 1)
        return 1;
    else if(test[l - t] == test[t - 1])
    {
        i++;
        check_palindrome(test, (t - 1));
    }
    else
        return 0;
}

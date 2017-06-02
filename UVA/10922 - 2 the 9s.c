#include<stdio.h>
#include<string.h>

int main()
{
    int i, l, sum, cnt;
    char s[1100], temp[1100], flag;
    while(scanf("%s", s) == 1)
    {
        if(strcmp(s, "0") == 0) break;
        flag = 0;
        cnt = 1;
        strcpy(temp, s);
        while(1)
        {
            l = strlen(temp);
            sum = i = 0;
            while(l--)
                sum += temp[l] - '0';
            if(sum % 9 != 0)
            {
                flag = 1;
                break;
            }
            if(sum > 9)
            {
                cnt++;
                while(sum)
                {
                    temp[i++] = sum % 10 + '0';
                    sum = sum / 10;
                }
                temp[i] = 0;
            }
            else
                break;
        }
    if(flag == 1)
        printf("%s is not a multiple of 9.\n", s);
    else
        printf("%s is a multiple of 9 and has 9-degree %d.\n"\
               , s, cnt);
    }
    return 0;
}



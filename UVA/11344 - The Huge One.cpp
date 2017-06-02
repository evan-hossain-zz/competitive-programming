#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    int test, i, k, l, n, num, fault, sum;
    char number[10010];
    cin >> test;
    while(test--)
    {
        scanf(" %s", number);
        l = strlen(number);
        cin >> n;
        fault = 0;
        while(n--)
        {
            cin >> num;
            switch(num)
            {
            case 1:
                break;
            case 2:
                if((number[l - 1] - '0') % 2 != 0)
                    fault = 1;
                break;
            case 3:
                sum = 0;
                for(i = 0; i < l; i++)
                    sum += (number[i] - '0');
                if(sum % 3 != 0)
                    fault = 1;
                break;
            case 4:
                sum = 0;
                for(i = 0; i < l; i++)
                    sum = (sum * 10 + number[i] - '0') % 4;
                if(sum % 4 != 0)
                    fault = 1;
                break;
            case 5:
                if((number[l - 1] == '0') ||
                        (number[l - 1] == '5'))
                    fault = 0;
                else
                    fault = 1;
                break;
            case 6:
                sum = 0;
                for(i = 0; i < l; i++)
                    sum = (sum * 10 + number[i] - '0') % 6;
                if(sum % 6 != 0)
                    fault = 1;
                break;
            case 7:
                sum = 0;
                for(i = 0; i < l; i++)
                    sum = (sum * 10 + number[i] - '0') % 7;
                if(sum % 7 != 0)
                    fault = 1;
                break;
            case 8:
                sum = 0;
                for(i = 0; i < l; i++)
                    sum = (sum * 10 + number[i] - '0') % 8;
                if(sum % 8 != 0)
                    fault = 1;
                break;
            case 9:
                sum = 0;
                for(i = 0; i < l; i++)
                    sum += (number[i] - '0');
                if(sum % 9 != 0)
                    fault = 1;
                break;
            case 10:
                if(number[l - 1] != '0')
                    fault = 1;
                break;
            case 11:
                sum = 0;
                for(i = 0; i < l; i++)
                {
                    if(i % 2 == 0)
                        sum += (number[i] - '0');
                    else
                        sum -= (number[i] - '0');
                }
                if(sum % 11 != 0)
                    fault = 1;
                break;
            case 12:
                sum = 0;
                for(i = 0; i < l; i++)
                    sum = (sum * 10 + number[i] - '0') % 12;
                if(sum % 12 != 0)
                    fault = 1;
                break;
            }
        }
        if(fault == 1)
            printf("%s - Simple.\n", number);
        else
            printf("%s - Wonderful.\n", number);
    }
    return 0;
}

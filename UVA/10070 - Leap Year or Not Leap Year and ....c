#include<stdio.h>
#include<string.h>
#include<math.h>


int main()
{
    char year[1000000];
    int i, j, l, lp, hulu, bulu, flag, n = 0;
    while(scanf("%s", year) == 1)
    {
        if(n > 0)
            printf("\n");
        n++;
        hulu = bulu = flag = lp = j = 0;
        l = strlen(year);
        if(year[l -1] != '0' || year[l - 2] != '0')
        {
            for(i = l - 1; i >= l - 2; --i)
            {
                lp += (year[i] - '0') * pow(10, j++);
            }
        }
        else if(year[l - 1] == '0' && year[l - 2] == '0')
        {
            for(i = l - 3; i >= l - 4; --i)
            {
                lp += (year[i] - '0') * pow(10, j++);
            }
        }
        lp = lp % 4;
        if(lp == 0)
        {
            printf("This is leap year.\n");
            flag = 1;
        }
        j = 0;
        for(i = 0; i < l; ++i)
        {
            j += year[i] - '0';
        }
        if(year[l - 1] == '5' || year[l - 1] == '0')
            hulu = 1;
        if(j % 3 == 0 && hulu == 1)
        {
            printf("This is huluculu festival year.\n");
            flag = 1;
        }
        if(lp == 0 && hulu == 1)
        {
            for(i = 0; i < l; ++i)
            {
                if(i % 2 == 0)
                    bulu += year[i] - '0';
                else
                    bulu -= year[i] - '0';
            }
            if(bulu % 11 == 0)
            {
                printf("This is bulukulu festival year.\n");
                flag = 1;
            }
        }
        if(flag == 0)
            printf("This is an ordinary year.\n");
    }
    return 0;
}

#include<stdio.h>
#include<string.h>

int main()
{
    char credit[25];
    int i, j, tst, k, res, temp[17];
    scanf("%d", &tst);
    while(tst--)
    {
        scanf(" %[^\n]", credit);
        k = strlen(credit);
        res = 0;
        for(i = 0, j = 0; i < k; i++, j++)
        {
            if(credit[i] == ' ')
            {
                j--;
                continue;
            }
            else
                temp[j] = credit[i] - '0';
        }

        for(i = 0, j = 1; j < 16; i = i + 2, j = j + 2)
        {
            credit[i] = 2 * temp[i];
            if(credit[i] > 9)
                res += (credit[i] / 10) + (credit[i] % 10);
            else
                res += credit[i];

            res += temp[j];
        }

        if(res % 10 == 0)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }
    return 0;

}

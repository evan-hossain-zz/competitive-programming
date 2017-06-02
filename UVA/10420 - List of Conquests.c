#include<stdio.h>
#include<string.h>

int main()
{
    char country[2000][80], temp[80];
    int i = 0, j, k, l, m, n, test, item, cnt;
    scanf("%d\n", &test);
    while(i < test)
    {
        gets(temp);
        sscanf(temp, " %s", country[i++]);
    }
    for(item = 0; item < test - 1; item++)
    {
        for(j = item + 1; j < test; j++)
        {
            if(strcmp(country[item], country[j]) > 0)
            {
                strcpy(temp, country[item]);
                strcpy(country[item], country[j]);
                strcpy(country[j], temp);
            }
        }
    }
    for(i = 0; i < test; i += cnt)
    {
        cnt = 1;
        for(j = i + 1; j < test; j++)
        {
            if(strcmp(country[i], country[j]) == 0)
                cnt++;
        }
        printf("%s %d\n", country[i], cnt);
    }
    return 0;
}

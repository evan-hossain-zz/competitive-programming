#include<stdio.h>
#include<string.h>


typedef struct
{
    char name[13];
    int accnt;
} info;

info group[11];

int main()
{
    int i, j, k, no_of_frnds, amount, frnds, l, flag = 0;
    char find_name[13];
    while(scanf("%d", &no_of_frnds) == 1)
    {
        if(flag != 0)
            printf("\n");
        flag++;
        for(i = 0; i < no_of_frnds; i++)
        {
            scanf(" %s", group[i].name);
            group[i].accnt = 0;
        }
        k = no_of_frnds;
        while(k--)
        {
            scanf(" %s", find_name);
            for(i = 0; i < no_of_frnds; i++)
            {
                if(strcmp(group[i].name, find_name) == 0)
                {
                    scanf("%d %d", &amount, &frnds);
                    if(frnds != 0)
                    {
                        group[i].accnt += (amount % frnds) - amount;
                        for(l = 0; l < frnds; l++)
                        {
                            scanf(" %s", find_name);
                            for(j = 0; j < no_of_frnds; j++)
                            {
                                if(strcmp(group[j].name, find_name) == 0)
                                {
                                    group[j].accnt += (amount / frnds);
                                    break;
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
        for(i = 0; i < no_of_frnds; i++)
            printf("%s %d\n", group[i].name, group[i].accnt);
    }
    return 0;
}

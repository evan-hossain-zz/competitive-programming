#include<stdio.h>
#include<string.h>

int main()
{
    char judge[50], team[50], test[50];
    int i, n, tst, j;
    scanf("%d", &n);
    for(tst = 1; tst <= n; tst++)
    {
        char c = getchar();
        scanf("%[^\n] %[^\n]", team, judge);
        if(strcmp(team, judge) == 0)
            printf("Case %d: Yes\n", tst);
        else
        {
            for(i = 0, j = 0; team[i] != '\0'; i++)
            {
                if(team[i] == ' ')
                    continue;
                else
                {
                    test[j] = team[i];
                    j++;
                }
            }
            test[j] = '\0';
            if(strcmp(test, judge) == 0)
                printf("Case %d: Output Format Error\n", tst);
            else
                printf("Case %d: Wrong Answer\n", tst);
        }
    }
    return 0;
}

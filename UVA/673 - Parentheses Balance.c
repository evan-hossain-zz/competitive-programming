#include<stdio.h>


int main()
{
    char braces[130];
    int tst, i, flag = 0;
    scanf("%d\n", &tst);
    while(tst--)
    {
        braces[0] = braces[1] = '\0';
        i = 1;
        flag = 0;
        while((braces[i] = getchar()) != '\n')
        {
            if(braces[i] == ']')
            {
                if(braces[i - 1] == '[')
                {
                    braces[i] = braces[i - 1] = '\0';
                    --i;
                }
                else
                {
                    flag = 1;
                    ++i;
                }
            }
            else if(braces[i] == ')')
            {
                if(braces[i - 1] == '(')
                {
                    braces[i] = '\0';
                    braces[i - 1] = '\0';
                    --i;
                }
                else
                {
                    flag = 1;
                    ++i;
                }
            }
            else if(braces[i] == '(' || braces[i] == '[')
                ++i;
        }
        if(braces[1] != 10 || flag == 1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}

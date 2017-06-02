#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int main()
{
    char line[1200], ch;
    int i, l, flag;
    while(gets(line))
    {
        flag = 0;
        if(strcmp(line, "*") == 0) break;
        l = strlen(line);
        for(i = 0; i < l; i++)
        {
            if(line[i] != ' ')
            {
                ch = tolower(line[i]);
                break;
            }
        }
        for(i = 0; i < l - 1; i++)
        {
            if(line[i] == ' ')
            {
                if(tolower(line[i + 1]) != ch)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}

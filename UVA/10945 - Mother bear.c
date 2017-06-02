#include<stdio.h>
#include<string.h>

int i, l, j;
char s[1000], test[1000];

void check_palindrome(char temp[], int length);
int main()
{
    while(gets(s))
    {
        if(strcmp(s, "DONE") == 0) break;
        l = strlen(s);
        for(i = 0, j = 0; i < l; i++)
        {
            s[i] = tolower(s[i]);
            if(s[i] >= 'a' && s[i] <= 'z')
                test[j++] = s[i];
        }
            test[j] = 0;
            i = 0;
            l = strlen(test);
            check_palindrome(test, l);

    }
    return 0;
}

void check_palindrome(char test[], int length)
{
    int t = length;
    if(i == l / 2)
        printf("You won't be eaten!\n");
    else if(test[l - t] == test[t - 1])
    {
        i++;
        check_palindrome(test, (t - 1));
    }
    else
        printf("Uh oh..\n");
}

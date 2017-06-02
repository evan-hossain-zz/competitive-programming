#include<stdio.h>
#include<string.h>

int main()
{
    char lang[15];
    int i = 0;
    while(scanf(" %[^\n]", lang) == 1)
    {
        if(strcmp(lang, "#") == 0)
            break;
        ++i;
        if (strcmp(lang, "HELLO") == 0)
            printf("Case %d: ENGLISH\n", i);
        else if (strcmp(lang, "HOLA") == 0)
            printf("Case %d: SPANISH\n", i);
        else if (strcmp(lang, "HALLO") == 0)
            printf("Case %d: GERMAN\n", i);
        else if (strcmp(lang, "BONJOUR") == 0)
            printf("Case %d: FRENCH\n", i);
        else if (strcmp(lang, "CIAO") == 0)
            printf("Case %d: ITALIAN\n", i);
        else if (strcmp(lang, "ZDRAVSTVUJTE") == 0)
            printf("Case %d: RUSSIAN\n", i);
        else
            printf("Case %d: UNKNOWN\n", i);
    }
    return 0;
}

#include<stdio.h>

int main()
{
    int i;
    char tele[31];

    while(scanf(" %[^\n]", tele) == 1)
    {
        for(i = 0; tele[i] != '\0'; i++)
        {
            if(tele[i] == 'A' || tele[i] == 'B' || tele[i] == 'C')
                printf("2");
            else if(tele[i] == 'D' || tele[i] == 'E' || tele[i] == 'F')
                printf("3");
            else if(tele[i] == 'G' || tele[i] == 'H' || tele[i] == 'I')
                printf("4");
            else if(tele[i] == 'J' || tele[i] == 'K' || tele[i] == 'L')
                printf("5");
            else if(tele[i] == 'M' || tele[i] == 'N' || tele[i] == 'O')
                printf("6");
            else if(tele[i] == 'P' || tele[i] == 'Q' || tele[i] == 'R' || tele[i] == 'S')
                printf("7");
            else if(tele[i] == 'T' || tele[i] == 'U' || tele[i] == 'V')
                printf("8");
            else if(tele[i] == 'W' || tele[i] == 'X' || tele[i] == 'Y' || tele[i] == 'Z')
                printf("9");
            else
                printf("%c", tele[i]);
        }
        printf("\n");
    }
    return 0;
}

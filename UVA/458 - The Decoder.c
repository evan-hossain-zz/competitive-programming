#include<stdio.h>

int main()
{
    char data[100];
    int i;
    while(scanf(" %[^\n]", data) == 1)
    {
        for(i = 0; data[i] != '\0'; i++)
        {
            printf("%c", data[i]-7);
        }
        printf("\n");
    }
    return 0;
}

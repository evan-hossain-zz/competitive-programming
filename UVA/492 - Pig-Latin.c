#include<stdio.h>
#include<string.h>

int main()
{
    char ch;
    int i, j;
    while(scanf("%c", &ch) == 1)
    {
        char words[80] = {0};
        if((ch >= 65 && ch <= 90) ||
                (ch >= 97 && ch <= 122))
        {
            if(ch == 'a' || ch == 'e' || ch == 'i'
                    || ch == 'o' || ch == 'u' ||
                    ch == 'A' || ch == 'E' || ch == 'I'||
                    ch == 'O' || ch == 'U')
            {
                scanf("%[a-zA-Z]", words);
                printf("%c%say", ch, words);
            }
            else
            {
                scanf("%[a-zA-Z]", words);
                printf("%s%cay", words, ch);
            }
        }
        else
            putchar(ch);
    }
    return 0;
}

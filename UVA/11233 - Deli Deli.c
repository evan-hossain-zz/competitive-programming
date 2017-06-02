#include<stdio.h>
#include<string.h>

typedef struct
{
    char singular[25], plural[25];
} stored;
int main()
{
    stored iwords[25];
    char words[25];
    int i, j, k, l, len, n, flag;
    scanf("%d %d", &l, &n);
    i = 0;
    while(i < l)
        scanf(" %s %s", iwords[i++].singular, iwords[i].plural);
    while(n--)
    {
        scanf(" %s", words);
        len = strlen(words);
        i = flag =0;
        while(i < l)
        {
            if(strcmp(words, iwords[i].singular) == 0)
            {
                printf("%s\n", iwords[i].plural);
                flag = 1;
                break;
            }
            i++;
        }
        if(flag == 1) continue;
        if(words[len - 1] == 'y')
        {
            if(words[len - 2] == 'a' || words[len - 2] == 'e' ||
                words[len - 2] == 'i' || words[len - 2] == 'o' ||
                words[len - 2] == 'u')
                printf("%ss\n", words);
            else
            {
                words[len - 1] = 0;
                printf("%sies\n", words);
            }
        }
        else if(words[len - 1] == 'o' || words[len - 1] == 's' ||
                words[len - 1] == 'x' || (words[len - 1] == 'h' &&
                words[len - 2] == 'c') || (words[len - 1] == 'h' &&
                words[len - 2] == 's'))
            printf("%ses\n", words);
        else
            printf("%ss\n", words);

    }
    return 0;
}

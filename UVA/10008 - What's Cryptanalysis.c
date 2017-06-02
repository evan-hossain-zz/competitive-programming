#include<stdio.h>
#include<string.h>
#include<ctype.h>

int comp(const void *a, const void *b)
{
    int *p = (int *) a;
    int *q = (int *) b;
    return (*q - *p);
}
int alphbt[26], cpy[26];

int main()
{
    register int len, i, l;
    int tst;
    scanf("%d", &tst);
    char ch[1000];
    while(tst--)
    {
        scanf(" %[^\n]", ch);
        l = 0;
        len = strlen(ch);
        for(i = 0; i < len; ++i)
        {
            switch(tolower(ch[i]))
            {
            case ('a'):
            {
                alphbt[0]++;
                break;
            }
            case ('b'):
            {
                alphbt[1]++;
                break;
            }
            case ('c'):
            {
                alphbt[2]++;
                break;
            }
            case ('d'):
            {
                alphbt[3]++;
                break;
            }
            case ('e'):
            {
                alphbt[4]++;
                break;
            }
            case ('f'):
            {
                alphbt[5]++;
                break;
            }
            case ('g'):
            {
                alphbt[6]++;
                break;
            }
            case ('h'):
            {
                alphbt[7]++;
                break;
            }
            case ('i'):
            {
                alphbt[8]++;
                break;
            }
            case ('j'):
            {
                alphbt[9]++;
                break;
            }
            case ('k'):
            {
                alphbt[10]++;
                break;
            }
            case ('l'):
            {
                alphbt[11]++;
                break;
            }
            case ('m'):
            {
                alphbt[12]++;
                break;
            }
            case ('n'):
            {
                alphbt[13]++;
                break;
            }
            case ('o'):
            {
                alphbt[14]++;
                break;
            }
            case ('p'):
            {
                alphbt[15]++;
                break;
            }
            case ('q'):
            {
                alphbt[16]++;
                break;
            }
            case ('r'):
            {
                alphbt[17]++;
                break;
            }
            case ('s'):
            {
                alphbt[18]++;
                break;
            }
            case ('t'):
            {
                alphbt[19]++;
                break;
            }
            case ('u'):
            {
                alphbt[20]++;
                break;
            }
            case ('v'):
            {
                alphbt[21]++;
                break;
            }
            case ('w'):
            {
                alphbt[22]++;
                break;
            }
            case ('x'):
            {
                alphbt[23]++;
                break;
            }
            case ('y'):
            {
                alphbt[24]++;
                break;
            }
            case ('z'):
            {
                alphbt[25]++;
                break;
            }
            }
        }

    }
    for(i = 0; i < 26; i++)
        cpy[i] = alphbt[i];
    qsort(alphbt, 26, sizeof(int), comp);
    for(i = 0;i < 26;)
    {
        len = 0;
        if(alphbt[i] == 0) break;
        for(l = 0; l < 26; l++)
        {
            if(cpy[l] == alphbt[i])
            {
                printf("%c %d\n", l + 65, alphbt[i]);
                len++;
            }
        }
        i = i + len;

    }
    return 0;
}

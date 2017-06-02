#include<stdio.h>
#include<string.h>
#include<ctype.h>



int main()
{
    register int l, i, max;
    int tst;
    char ch[1000];
    scanf("%d\n", &tst);
    while(tst--)
    {
        scanf(" %[^\n]", ch);
        l = 0;
        int alphbt[26] ={0};
        l = strlen(ch);
        for(i = 0; i < l; ++i)
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
            default:
                break;
            }
        }
        max = alphbt[0];
        for(i = 0; i < 26; i++)
        {
            if(max < alphbt[i])
                max = alphbt[i];
        }

        for(l = 0; l < 26; l++)
        {
            if(alphbt[l] == max)
            {
                printf("%c", l + 97);
            }
        }
        printf("\n");

    }
    return 0;
}

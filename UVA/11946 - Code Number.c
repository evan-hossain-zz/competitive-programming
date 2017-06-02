#include<stdio.h>
#include<string.h>

int main()
{
    char ch[100];
    int tst, i, l;
    scanf("%d\n", &tst);
    while(tst--)
    {
        while(gets(ch))
        {
            l = strlen(ch);
            if(l == 0)
                break;
            for(i = 0; i < l;)
            {
                switch(ch[i])
                {
                case '0':
                {
                    putchar('O');
                    i++;
                    break;
                }
                case '1':
                {
                    putchar('I');
                    i++;
                    break;
                }
                case '2':
                {
                    putchar('Z');
                    i++;
                    break;
                }
                case '3':
                {
                    putchar('E');
                    i++;
                    break;
                }
                case '4':
                {
                    putchar('A');
                    i++;
                    break;
                }
                case '5':
                {
                    putchar('S');
                    i++;
                    break;
                }
                case '6':
                {
                    putchar('G');
                    i++;
                    break;
                }
                case '7':
                {
                    putchar('T');
                    i++;
                    break;
                }
                case '8':
                {
                    putchar('B');
                    i++;
                    break;
                }
                case '9':
                {
                    putchar('P');
                    i++;
                    break;
                }

                default:
                {
                    putchar(ch[i]);
                    i++;
                    break;
                }
                }
            }
            printf("\n");
        }
            if(tst != 0)
                printf("\n");

    }
    return 0;
}

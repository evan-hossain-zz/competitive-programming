#include<stdio.h>

int main()
{
    char ch, flag = 0;
    while(scanf("%c", &ch) == 1)
    {
        if(ch == '\n')
        {
            printf("\n");
            flag = 0;
        }
        else
        {
            switch(ch)
            {
            case 'B':
            case 'F':
            case 'P':
            case 'V':
                if(flag != 1)
                    printf("1");
                flag = 1;
                break;
            case 'C':
            case 'G':
            case 'J':
            case 'K':
            case 'Q':
            case 'S':
            case 'X':
            case 'Z':
                if(flag != 2)
                    printf("2");
                flag = 2;
                break;
            case 'D':
            case 'T':
                if(flag != 3)
                    printf("3");
                flag = 3;
                break;
            case 'L':
                if(flag != 4)
                    printf("4");
                flag = 4;
                break;
            case 'M':
            case 'N':
                if(flag != 5)
                    printf("5");
                flag = 5;
                break;
            case 'R':
                if(flag != 6)
                    printf("6");
                flag = 6;
                break;
            default:
                flag = 0;
                break;
            }
        }
    }
    return 0;
}

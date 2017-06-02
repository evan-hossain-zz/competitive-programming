#include<stdio.h>
#include<string.h>


int main()
{
    char tape[600];
    int i, j, res;
    while(gets(tape))
    {
        res = 0;
        i = strlen(tape);
        for(j = 0; j < i; j++)
        {
            switch(tape[j])
            {
            case ' ':
            {
                res <<= 1;
                break;
            }
            case 'o':
            {
                res = (res << 1) + 1;
                break;
            }
            }
        }
        if(res != 0)
            printf("%c", res);
    }
    return 0;
}

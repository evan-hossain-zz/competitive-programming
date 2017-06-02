#include<stdio.h>
#include<string.h>

char message[1060], input[1060];
int main()
{
    int i, j, l, num = 0, div;
    while(gets(input))
    {
        num = j = 0;
        l = strlen(input);
        for(i = l - 1; i >= 0; i--)
        {
            if(input[i] >= '0' && input[i] <= '9')
            {
                num += input[i] - '0';
                if(num >= 32)
                {
                    message[j++] = num;
                    num = 0;
                }
                else
                    num *= 10;
            }
            else
            {
                div = input[i];
                do
                {
                    message[j++] = (div % 10) + '0';
                    div = div / 10;
                }
                while(div);
            }
            message[j] = '\0';
        }
        printf("%s\n", message);
        memset(message, 0, 1060);
    }
    return 0;
}

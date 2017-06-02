#include<stdio.h>
#include<string.h>

int main()
{
    char array[1002];
    long long sum;
    int i, l;
    while(scanf(" %[^\n]", array) == 1)
    {
        if(strcmp(array, "0") == 0)
            break;
        l = strlen(array);
        sum = 0;
        for(i = 0; i < l; ++i)
        {
            if(i % 2 == 0)
                sum += array[i] - '0';
            else
                sum -= array[i] - '0';
        }
        if(sum % 11 == 0)
            printf("%s is a multiple of 11.\n", array);
        else
            printf("%s is not a multiple of 11.\n", array);
    }
    return 0;
}

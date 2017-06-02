#include<stdio.h>

int main()
{
    int i, j;
    for(i = 2;i > 1;i++)
        {
            if(i % 2 == 0)
                j++;
            else if(i % 3 == 0)
                j++;
            else if(i % 5 == 0)
                j++;
            if(j == 10)
                break;
        }
        printf("%d", i);
        return 0;
}

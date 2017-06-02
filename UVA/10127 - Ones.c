#include<stdio.h>

int main()
{
    int n, i, j, store;
    while(scanf("%d", &n) == 1)
    {
        i = 1;
        store = 1;
        while(1)
        {
            i = i * 10 + 1;
            j = i % n;
            store += 1;
            if(j == 0)
                break;
            else
                i = j;
        }
        printf("%d\n", store);
    }
    return 0;
}

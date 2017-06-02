#include <iostream>
#include <cstdio>

using namespace std;

long long arr[20];

void generate(void)
{
    arr[0] = 1;
    for(int i = 1; i < 20; i++)
        arr[i] = ((((i - 1)  << 1)+ 1) << 1) * arr[i - 1] / ((i - 1) + 2);
    return;
}

int main()
{
    generate();
    long long n;
    int i;
    while(scanf("%lld", &n) == 1)
    {
        for(i = 1; i < 20 && n; i++)
        {
            if(arr[i] == n)
            {
                printf("%d\n", i);
                break;
            }
        }
        if(arr[i] != n)
            printf("0\n");
    }
    return 0;
}

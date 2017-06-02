#include<stdio.h>
#include<string.h>

int a, b, c, d, e, f, n;
long long arr[1000000];
int fn(int n);
int main()
{
    int i, j, k, cases, caseno = 0;
    scanf("%d", &cases);
    while(cases-- )
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset(arr, -1, sizeof(int) * 1000000);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}

int fn(int n)
{
    if(n == 0)
        arr[n] = a;
    else if(n == 1)
        arr[n] = b;
    else if(n == 2)
        arr[n] = c;
    else if(n == 3)
        arr[n] = d;
    else if(n == 4)
        arr[n] = e;
    else if(n == 5)
        arr[n] = f;
    else if(arr[n] != -1)
        arr[n] = arr[n];
    else
        arr[n] = (fn(n - 1) + fn(n - 2) + fn(n - 3) + fn(n - 4) + fn(n - 5) + fn(n - 6));
    return arr[n] % 10000007;
}

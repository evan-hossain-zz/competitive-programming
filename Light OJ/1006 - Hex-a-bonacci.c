#include<stdio.h>
#include<string.h>
#include <iostream>

int a, b, c, d, e, f, n, array[10005];
int fn(int n);
int main()
{
    int i, j, k, cases, caseno = 0;
    scanf("%d", &cases);
    while(cases-- )
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset(array, -1, sizeof(int) * 10005);
        printf("Case %d: %d\n", ++caseno, fn(n) % 100057);
    }
    return 0;
}

int fn(int n)
{
    cout << n << endl;
    if(n == 0)
        return array[n] = a;
    if(n == 1)
        return array[n] = b;
    if(n == 2)
        return array[n] = c;
    if(n == 3)
        return array[n] = d;
    if(n == 4)
        return array[n] = e;
    if(n == 5)
        return array[n] = f;
    if(array[n] != -1)
        return array[n];
    else
        return array[n] = (fn(n - 1) + fn(n - 2) + fn(n - 3) + fn(n - 4) + fn(n - 5) + fn(n - 6));
}

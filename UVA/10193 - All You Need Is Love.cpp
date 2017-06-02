#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int to_bin(int len, char ara[]);
int gcd(int a, int b);

int main()
{
    char arr1[35], arr2[35];
    int ans, test, kase = 0, l1, l2;
    cin >> test;
    while(kase < test)
    {
        scanf(" %s %s", arr1, arr2);
        l1 = strlen(arr1);
        l2 = strlen(arr2);
        l1 = to_bin(l1, arr1);
        l2 = to_bin(l2, arr2);
        ans = gcd(l1, l2);
        if(ans == 1)
            printf("Pair #%d: Love is not all you need!\n", ++kase);
        else
            printf("Pair #%d: All you need is love!\n", ++kase);
    }
    return 0;
}

int to_bin(int len, char ara[])
{
    int i = 0, sum = 0;
    while(i < len)
    {
        if(ara[i++] == '0')
            sum = sum << 1;
        else
            sum = (sum << 1) + 1;
    }
    return sum;
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

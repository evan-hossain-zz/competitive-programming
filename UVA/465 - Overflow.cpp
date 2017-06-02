#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    char sign, a[1000], b[1000];
    int l1, l2, i;
    long double num1, num2, res;
    while(scanf(" %s %c %s", &a, &sign, &b) == 3)
    {
        printf("%s %c %s\n", a, sign, b);
        num1 = num2 = 0;
        l1 = strlen(a);
        l2 = strlen(b);
        num1 = atof(a);
        num2 = atof(b);
        if(num1 > 2147483647)
            printf("first number too big\n");
        if(num2 > 2147483647)
            printf("second number too big\n");
        if(sign == '+')
        {
            if(num1 + num2 > 2147483647)
                printf("result too big\n");
        }
        else if(sign == '*')
        {
            if(num1 * num2 > 2147483647)
                printf("result too big\n");
        }
    }
    return 0;
}

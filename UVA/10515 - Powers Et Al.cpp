#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int lst_digit, res, mod, store[6], str;
    char b[110], p[110];
    while(scanf(" %s %s", &b, &p) == 2)
    {
        if(strcmp(b, "0") == 0 && strcmp(p, "0") == 0)
            break;
        if(strcmp(p, "0") == 0)
        {
            printf("1\n");
            continue;
        }
        res = 0;
        lst_digit = b[strlen(b) - 1] - '0';
        if(lst_digit == 2 || lst_digit == 3 ||
           lst_digit == 7 || lst_digit == 8)
            mod = 4;
        else if(lst_digit == 4 || lst_digit == 9)
            mod = 2;
        else
        {
            printf("%d\n", lst_digit);
            continue;
        }
        for(int i = 1; i <= mod; i++)
        {
            str = pow(lst_digit, i);
            store[i] = str % 10;
        }
        if(strlen(p) > 1)
        {
            res = 10 * (p[strlen(p) - 2] - '0') + p[strlen(p) - 1] - '0';
            str = res % mod;
            if(!str)
                printf("%d\n", store[mod]);
            else
                printf("%d\n", store[str]);
        }
        else
        {
            sscanf(p, "%d", &res);
            str = res % mod;
            if(!str)
                printf("%d\n", store[mod]);
            else
                printf("%d\n", store[str]);
        }
    }
    return 0;
}

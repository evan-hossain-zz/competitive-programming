#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
char primes[101];
int main()
{
    int n, i, div, input, cnt, j;
    for(i = 4; i <= 101; i += 2)
        primes[i] = '1';
    for(i = 2; i < 101 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 101; j++)
                primes[i * j] = '1';
        }
    }
    while(cin >> n && n)
    {
        input = n;
        printf("%3d! =", input);
        cnt = 0;
        while(n)
        {
            n = n >> 1;
            cnt += n;
        }
        printf("%3d", cnt);
        n = input;
        cnt = 0;
        for(i = 3; input >= i; i += 2)
        {
            if(i == 49 && input > 52)
            {
                printf("\n      ");
            }
            if(primes[i] != '1')
            {
                n = input;
                cnt = 0;
                while(n)
                {
                    n = n / i;
                    cnt += n;
                }
                printf("%3d", cnt);
            }
        }

        cout << endl;
    }
    return 0;
}

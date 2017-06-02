#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

char primes[1000000];
int prime[1500];
int res[1000000];

void sieve(void)
{
    int cnt = 0, i, j;
    primes[0] = primes[1] = '1';
    for(i = 4; i <= 1000000; i += 2)
        primes[i] = '1';
    for(i = 2; i < 1000000 / i; i++)
    {
        if(primes[i] != '1')
        {
            prime[cnt++] = i;
            for(j = 2; j * i < 1000000; j++)
                primes[i * j] = '1';
        }
    }
}

int NOD(int n);

int main()
{
    int N, prev = 1, count = 1;
    sieve();
    res[0] = 0;
    res[1] = 1;
    while(prev <= 1000000)
    {
        int b=prev;
        prev = prev + NOD(prev);
        for(int k = b; k < prev; k++)
            res[k] = count;
        count++;
    }
    int test, a, b;
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
    {
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", kase, res[b] - res[a - 1]);
    }
    return 0;
}

int NOD(int n)
{
    int ret = 1, div = 0;
    int limit = sqrt(n);
    for(int i = 0; prime[i] <= limit; i++)
    {
        div = 0;
        while(n % prime[i] == 0)
        {
            div++;
            n /= prime[i];
        }
        ret *= (div + 1);
        if(div)
            limit = sqrt(n);
    }
    if(n > 1)
        ret *= 2;
    return ret;
}

#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <int> primes;
bool not_prime[SZ];
int factors[SZ];

void sieve()
{
    primes.pub(2);
    int i, j, limit = sqrt(SZ);
    not_prime[1] = 1;
    for(i = 4; i <= SZ; i += 2)
        not_prime[i] = 1;
    for(i = 3; i <= limit; i += 2)
    {
        if(!not_prime[i])
        {
            primes.pub(i);
            for(j =2; j * i <= SZ; j++)
                not_prime[i * j] = 1;
        }
    }
}

int mat[6][SZ];

int main()
{
    sieve();
    int i, j, k, a, b, ps = primes.size(), t, num;
    for(i = 2; i < SZ; i++)
    {
        t  = num = i;
        for(j = 0; j < ps; j++)
        {
            if(t % primes[j] == 0)
            {
                factors[num]++;
                while(t % primes[j] == 0)
                    t /= primes[j];
            }
        }
        if(t != 1)
            factors[num]++;
    }
    for(i = 2; i < SZ; i++)
    {
        if(factors[i] < 6)
            mat[factors[i]][i] = 1;
    }
    for(i = 1; i < 6; i++)
    {
        for(j = 3; j < SZ; j++)
            mat[i][j] += mat[i][j - 1];
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &a, &b, &k);
        printf("%d\n", mat[k][b] - mat[k][a - 1]);
    }
    return 0;
}


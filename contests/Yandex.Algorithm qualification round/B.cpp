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
#define SZ 400000010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <int> prims;

bool primes[40010];
int sieve()
{
    int i, j;
//    int cnt = 0;
    primes[1] = 1;
    prims.pub(2);
    for(i = 4; i <= 40010; i += 2)
        primes[i] = 1;
    for(i = 3; i < 40010 / i; i += 2)
    {
        if(primes[i] != 1)
        {
            for(j = 2; j * i < 40010; j++)
                primes[i * j] = 1;
        }
    }
    for(i = 0; i < 40010; i++)
        if(primes[i] == 0)
            prims.pub(i);
}

bool isprime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

vector <LL> values;

int main()
{
    sieve();
    int i, j, k, sz = prims.size() - 1, n;
    cin >> n;
    for(i = 0; i < sz; i++)
    {
        for(j = i + 1; j < sz; j++)
        {
            int res = (prims[i] * prims[j]) + 1;
            double d = sqrt(res);
            k = (int) d;
            if(d - k == 0 && k <= n && k > 1)
                values.pub(k);
        }
    }
    sort(values.begin(), values.end());
    for(i = 0; i < values.size(); i++)
    {
        if(values[i] <= n)
            cout << values[i] << endl;
        else
            break;
    }
    return 0;
}


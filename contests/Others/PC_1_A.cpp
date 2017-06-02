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

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

char primes[1001];
struct info{
    int num;
    int div;
};

vector <info> v;

void generate(int n);
void sieve(void)
{

    int i, j;
    for(i = 4; i <= 1001; i += 2)
        primes[i] = '1';
    for(i = 2; i < 1001 / i; i++)
    {
        if(primes[i] != '1')
        {
            for(j = 2; j * i < 1001; j++)
                primes[i * j] = '1';
        }
    }
}

bool comp(const info &a, const info &b)
{
    if(a.div == b.div)
        return a.num > b.num;
    else
        return a.div < b.div;
}

int main()
{
    sieve();
    int i, test, n;
    for(i = 1; i < 1001; i++)
        generate(i);
    sort(v.begin(), v.end(), comp);
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
    {
        scanf("%d", &n);
        cout << "Case " << kase << ": " << v[n - 1].num << endl;
    }
    return 0;
}

void generate(int n)
{
    info x;
    x.num = n;
    int res = 1, cnt = 0;
    while(n % 2 == 0)
    {
        n /= 2;
        cnt++;
    }
    if(cnt)
        res *= (cnt + 1);
    int l = sqrt(n);
    for(int i = 3; i <= l; i++)
    {
        cnt = 0;
        while(n % i == 0)
        {
            n /= i;
            cnt++;
        }
        if(cnt)
            res *= (cnt + 1);
    }
    if(n > 1)
        res *= 2;
    x.div = res;
    v.pub(x);
}

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    printf("%d", 'Z');
    int i, n, x, y, mn = 10000000, a, b, j;
    double p, q, r = SZ;
    cin >> x >> y >> n;
    if(x == 0)
    {
        cout << "0/" << y;
        return 0;
    }
    for(i = n; i > 0; i--)
    {
        for(j = x; j >= sqrt(x); j--)
        {
            if(gcd(i, j) == 1)
            {
                p = (double)j/i;
                q = (double)x / y;
                if(abs(p - q) <= r)
                {
                    a = j;
                    b = i;
                    r = abs(p - q);
                }
            }
        }
    }
    cout << a << '/' << b;
    return 0;
}


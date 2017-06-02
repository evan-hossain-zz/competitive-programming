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
#define infinity 2147483647
#define LL long long

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

LL ub(LL n)
{
    return (n * ( n + 1)) >> 1;
}

int main()
{
    LL up, down, inp, n;
    while(scanf("%lld", &inp) == 1)
    {
        n = ceil((-1 + ceil(sqrt(1 + 8 * inp))) / 2);
        up = ub(n) - inp + 1;
        down = n - up + 1;
        printf("%lld/%lld\n", up, down);
    }
    return 0;
}

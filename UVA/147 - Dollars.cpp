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
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
LL nway[30001];

void make(int curntcent, int coin);

int main()
{
    int i, n, a, b;
    double d;
    nway[0] = 1;
    for(i = 0; i < 11; i++)
        make(coins[i], coins[i]);
    while(scanf("%d.%d", &a, &b) == 2 && (a | b))
    {
        n = a * 100 + b;
        printf("%3d.%02d%17lld\n", a, b, nway[n]);
    }
    return 0;
}

void make(int curntcent, int coin)
{
    if(curntcent > 30000)
        return;
    nway[curntcent] += nway[curntcent - coin];
    make(curntcent + 5, coin);
}


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

int coins[21] = {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331,\
 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};

LL nway[10001];

void make(int curntcent, int coin);

int main()
{
    int i, n;
    nway[0] = 1;
    for(i = 0; i < 21; i++)
        make(coins[i], coins[i]);
    while(scanf("%d", &n) == 1)
        printf("%lld\n", nway[n]);
    return 0;
}

void make(int curntcent, int coin)
{
    if(curntcent > 10000)
        return;
    nway[curntcent] += nway[curntcent - coin];
    make(curntcent + 1, coin);
}

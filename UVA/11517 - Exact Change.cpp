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
#define infinity 214748364
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct info
{
    int cents, coin;
};

info ans;

int coins[101], total_coins, bill, dp[30001];

void make(int i, int total, int coin_taken);

int main()
{
    int test, i, j;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &bill, &total_coins);
        for(i = 0; i < total_coins; i++)
            scanf("%d", &coins[i]);
        dp[0] = 0;
        for(i = 1; i < 30001; i++)
            dp[i] = infinity;
        for(i = 0; i < total_coins; i++)
        {
            for(j = bill; j >= 0; j--)
                dp[coins[i] + j] = min(dp[coins[i] + j], dp[j] + 1);
        }
        for(i = bill; ; i++)
        {
            if(dp[i] < infinity)
            {
                printf("%d %d\n", i, dp[i]);
                break;
            }
        }
    }
    return 0;
}


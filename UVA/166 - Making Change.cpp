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

int coinss[6] = {5, 10, 20, 50, 100, 200}, ways[10001], coins[6], mn, dam;

void calculate(void);
void backtrack(int indx, int sum);

int main()
{
    calculate();
    int a, b, mn;
    while(scanf("%d %d %d %d %d %d %d.%d", &coins[0], &coins[1],\
                 &coins[2], &coins[3], &coins[4], &coins[5], &a,  &b) == 8)
    {
        mn = infinity;
        dam = a * 10 + b;
        cout << dam << endl;
        cout << ways[5] << ' ' << ways[95];
        backtrack(0, 0);
        printf("%3d\n", mn);
    }
    return 0;
}

void calculate(void)
{
    int i, j;
    ways[0] = 1;
    for(i = 0; i < 6; i++)
    {
        for(j = coinss[i]; j < 10001; j += 5)
            ways[j] = min(ways[j], ways[j - coinss[i]]);
    }
}

void backtrack(int indx, int sum)
{
    cout << sum << endl;
    if(indx > 5)
        return;
    if(coins[indx] == 0)
    {
        backtrack(indx + 1, sum);
        return;
    }
    sum += coinss[indx];
    coins[indx]--;
    if(sum > dam)
        mn = min(mn, ways[sum] + ways[sum - dam]);
    else
        mn = min(mn, ways[sum] + ways[dam - sum]);
    //backtrack(indx, 0);
    backtrack(indx, sum);
}

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

int coins[6] = {2, 4}, nway[9];

void make(int kototk, int coin);

int main()
{
    int i, j;
    nway[0] = 1;
    for(i = 0; i < 2; i++)
        make(coins[i], coins[i]);
    for(i = 0; i < 9; i++)
        cout << nway[i] << ' ';
    return 0;
}

void make(int kototk, int coin)
{
    if(kototk > 8)
        return;
    nway[kototk] += nway[kototk - coin];
    make(kototk + 1, coin);
}

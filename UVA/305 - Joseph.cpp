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
#define SZ 100000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int kharap, paisi;

int dp[28][SZ];

void find_survivour(int n, int k);

int main()
{
    int n, k, i;
    while(scanf("%d", &k) == 1)
    {
        for(i = k + 1; paisi; i++)
        {
            kharap = k;
            find_survivour(k << 1, i);
            if(kharap == 0)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}

void find_survivour(int n, int k)
{
    if(n <= k)
        return;
    kharap--;
   find_survivour(n - 1, k) + k - 1) % n;
}


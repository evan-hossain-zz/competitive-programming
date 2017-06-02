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
#define SZ 10010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int coins[110], nways[SZ];

int main()
{
    int n, i, k, j, test;
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
    {
        memset(nways, 0, sizeof(nways));
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; i++)
            scanf("%d", &coins[i]);
        nways[0] = 1;
        for(i = 0; i < n; i++)
        {
            for(j = coins[i]; j <= k; j++)
                nways[j] = (nways[j] + nways[j - coins[i]]) % 100000007;
        }
        printf("Case %d: %d\n", kase, nways[k] % 100000007);
    }
    return 0;
}



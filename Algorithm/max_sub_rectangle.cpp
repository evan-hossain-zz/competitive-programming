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
#define SZ 1000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[SZ][SZ];

int max_sum(int n);

int main()
{
    int n, i, j, k;
    while(scanf("%d", &n) == 1 && n)
        {
            for(i = 0; i < n; i++)
                arr[i][0] = arr[0][i] = 0;
            for(i = 1; i <= n; i++)
                {
                    for(j = 1; j <= n; j++)
                        scanf("%d", &arr[i][j]);
                }
            printf("%d\n", max_sum(n));
        }
    return 0;
}

int max_sum(int n)
{
    int i, j, res, m = 0;
    for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                {
                    arr[i][j] += arr[i - 1][j];
                }
        }
    for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                {
                    arr[i][j] += arr[i][j - 1];
                }
        }
    for(int r1 = 1; r1 <= n; r1++)
        {
            for(int r2 = r1; r2 <= n; r2++)
                {
                    for(int c1 = 1; c1 <= n; c1++)
                        {
                            for(int c2 = c1; c2 <= n; c2++)
                                {
                                    res = arr[r2][c2] - arr[r1 - 1][c2] - arr[r2][c1 - 1] + arr[r1 -1][c1 - 1];
                                    m = max(res, m);
                                }
                        }
                }
        }
    return m;
}

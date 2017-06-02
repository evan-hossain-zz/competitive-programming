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
bool comp(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    int n, m, k, i, mx = 0, arr[1000];
    while(scanf("%d %d %d", &n, &m, &k) == 3)
    {
        int res = 0;
        for(i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
        sort(&arr[0], &arr[n], comp);
        int j = k;
        for(i = 0; j; i++)
        {
            j--;
            res += arr[i];
            if(res >= m || (m - res) <= j)
                break;
        }
        if(res + j < m)
            printf("-1\n");
        else
            printf("%d\n", i + 1);
    }
    return 0;
}


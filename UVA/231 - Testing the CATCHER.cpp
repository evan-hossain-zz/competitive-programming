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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[10000], I[10000];

int lis(int *data, int n);

int main()
{
    int n, i, kase = 0;
    while(scanf("%d", &arr[0]) == 1 && arr[0] != -1)
    {
        i = 1;
        while(scanf("%d", &arr[i]) == 1 && arr[i] != -1)
            i++;
        if(kase)
            printf("\n");
        printf("Test #%d:\n", ++kase);
        printf("  maximum possible interceptions: %d\n", lis(arr, i));
    }
    return 0;
}

int lis(int *data, int n)
{
    int i, len = 0, mid, low, high;
    I[0] = -infinity;
    for(i = 1; i < n; i++)
        I[i] = infinity;
    for(i = 0; i < n; i++)
    {
        low = 0, high = len;
        while(low <= high)
        {
            mid = low + high >> 1;
            if(I[mid] > data[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = data[i];
        if(low > len)
            len = low;
    }
    return len;
}

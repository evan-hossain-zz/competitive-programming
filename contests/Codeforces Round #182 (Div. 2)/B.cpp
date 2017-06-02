#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010
#define for(i, a, n) for(i = a; i <= n; i++)

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[SZ];

int main()
{
    int n, v, m, i, t, c, pos = 0, mid, high, low, res;
    cin >> n >> m;
    for(i, 1, n)
    {
        cin >> t >> c;
        arr[i] = (t * c) + pos;
        pos = arr[i];
    }
    for(i, 1, m)
    {
        cin >> c;
        high = n, low = 1;
        while(low < high)
        {
            mid = (high + low) / 2;
            if(c > arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if(arr[high] >= c)
            cout << high;
        else if(arr[low] >= c)
            cout << low;
        else if(arr[high + 1] >= c)
            cout << high + 1;
        else if(arr[low - 1] >= c)
            cout << low - 1;
        cout << endl;
    }
    return 0;
}


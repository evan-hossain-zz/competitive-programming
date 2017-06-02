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

int main()
{
    int n, k, arr[100010], i, m = 0, mn = 100000;
    long long ans = 0;
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] < 0)
        m++;
    }
    if(k >= m)
    {
        for(i = 0; i < m; i++)
            if(arr[i] < 0)
            arr[i] = -arr[i];
        if((k - m) % 2 != 0 && (k - m) > 0)
        {
            for(i = 0; i < n; i++)
                mn = min(mn, arr[i]);
        }
    }
    else
    {
        for(i = 0; i < k; i++)
            if(arr[i] < 0)
            arr[i] = -arr[i];
    }
    for(i = 0; i < n; i++)
        ans += arr[i];
    if(mn != 100000)
        cout << ans - 2 * mn << endl;
    else
        cout << ans << endl;
    return 0;
}


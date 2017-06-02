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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[200], fcum[200], bcum[200];

int main()
{
    int i, j,k, n, mx = 0;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    fcum[0] = arr[0];
    for(i = 0; i < n; i++)
        fcum[i + 1] = fcum[i] + arr[i + 1];
    bcum[n - 1] = arr[n - 1];
    for(i = n; i > 0; i--)
        bcum[i - 1] = bcum[i] + arr[i - 1];
//    for(i = 0; i < n; i++)
//        cout << fcum[i] << ' ';
//    cout << endl;
//    for(i = 0; i < n; i++)
//        cout << bcum[i] << ' ';
    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            int sum = 0, t = j;
            for(k = i; k <= j; k++)
                sum += (1 - arr[k]);
            sum += fcum[i - 1] + bcum[j + 1];
            mx = max(sum, mx);
        }
    }
    cout << mx << endl;
    return 0;
}


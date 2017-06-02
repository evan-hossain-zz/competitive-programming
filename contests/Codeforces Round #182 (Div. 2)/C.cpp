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

int arr[SZ], n;

int recur(int indx, int taken, int sum)
{
    if(indx + 1 >= 2 * n)
        return sum;
    int case1 = recur(indx + 1, taken, sum + arr[indx + 1]);
    int case2 = -infinity;
    if(taken < n)
        case2 = recur(indx + 1, taken + 1, sum - arr[indx + 1]);
    return max(case1, case2);
}

int main()
{
    int i, res = -infinity;
    cin >> n;
    for(i = 1; i < 2 * n; i++)
        cin >> arr[i];
    res = max(recur(1, 1, arr[1]), recur(1, 1, -arr[1]));
    cout << res << endl;
    return 0;
}


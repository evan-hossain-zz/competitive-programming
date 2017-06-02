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
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

LL func(LL a)
{
    return a / 2;
}

int main()
{
    LL arr[SZ], m;
    int n, i, cnt = 0;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if((arr[i] == 0 && arr[j] == 0)
            || (func(2 * arr[i]) == func(arr[j]))
            || (func(2 *arr[i] + 1) == func(arr[j]) + 1))
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}


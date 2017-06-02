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
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[500];

int main()
{
    int n, a, b, i, j;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    for(i = n + 1; i <= (n+n); i++)
        arr[i] = arr[i - n];
    cin >> a >> b;
    int p = 0, q = 0;
    for(i = min(a, b); i < max(a, b); i++)
    {
        p += arr[i];
    }
    for(i = max(a, b); i < n + min(a, b); i++)
        q += arr[i];
    cout << min(p, q);
    return 0;
}


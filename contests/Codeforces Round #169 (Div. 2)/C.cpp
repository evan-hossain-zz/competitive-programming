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
#define infinity 1000000010
#define LL long long int
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

LL arr[2 * SZ];
int tem[2 * SZ];

int main()
{
    int a, b, n, q, i;
    LL ans = 0;
    cin >> n >> q;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    for(i = 0; i < q; i++)
    {
        cin >> a >> b;
        tem[a]++;
        tem[b + 1]--;
    }
    for(i = 2; i <= n; i++)
        tem[i] += tem[i - 1];
    sort(tem, tem + n + 1);
    sort(arr, arr + n + 1);
    for(i = n; i > 0; i--)
        ans += (tem[i] * arr[i]);
    cout << ans;
    return 0;
}

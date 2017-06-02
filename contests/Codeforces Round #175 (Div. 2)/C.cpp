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
#define SZ 100020

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;
int arr[SZ * 3];

bool comp(const int &a, const int &b)
{
    return a < b;
}

int main()
{
    int n, i;
    LL cnt = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    sort(&arr[1], arr + n + 1, comp);
    for(i = 1; i <= n; i++)
    {
        cnt += abs(i - arr[i]);
    }
    cout << cnt;
    return 0;
}


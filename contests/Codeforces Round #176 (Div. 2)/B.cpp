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
#define infinity 2147483648LL
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

LL eval(LL n)
{
    return n * (n + 1) / 2 + 1;
}

int main()
{
    LL n, k, ans, low, high, mid, paisi, tot;
    cin >> n >> k;
    tot = eval(k - 1);
    low = 1, high = k, paisi = infinity;
    while(low <= high)
    {
        mid = low + high >> 1;
        ans = tot - eval(mid - 1) + 1;
        if(ans >= n)
        {
            low = mid + 1;
            paisi = k - mid;
        }
        else
            high = mid - 1;
    }
    if(paisi != infinity)
        cout << paisi << endl;
    else
        cout << -1;
    return 0;
}


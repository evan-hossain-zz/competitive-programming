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
#define SZ 20010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

string ans;
bool sit;
LL n, k;

void recur(int val, int divided)
{

    if(divided > k)
        return;
    if(val == 1)
    {
        if(divided == k)
            ans = "YES";
        return;
    }
    LL mul = val / pow(50, (k - divided));
    if(mul > 1)
    {
//        cout << val * mul << endl;
        return;
    }
    for(int i = 2; i < 51; i++)
    {
        if(sqrt(i) * sqrt(i) == i)
            continue;
        if(val % i == 0)
            recur(val / i, divided + 1);
    }
}

int main()
{
    int i, cnt  = 0, t;
    cin >> t;
    while(t--){
            ans = "NO";
        cin >> n >> k;
        recur(n, 0);
    cout << ans << endl;
    }
    return 0;
}


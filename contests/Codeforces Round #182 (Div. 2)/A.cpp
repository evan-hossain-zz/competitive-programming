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

int arr[2 * SZ];

int main()
{
    int n, i, cnt = 0, q, l, r, one = 0;
//    in;
//    out;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] < 1)
            cnt++;
        else
            one++;
    }
    for(i = 0; i < q; i++)
    {
        cin >> l >> r;
        int ran = r - l + 1;
        if(ran % 2)
            cout << 0 << endl;
        else
        {
            ran /= 2;
            if(ran <= cnt && ran <= one)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}


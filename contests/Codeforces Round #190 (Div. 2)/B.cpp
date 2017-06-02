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

int main()
{
    int r, g, b, cnt = 0, rem, R, G, B, r1;
    cin >> R >> G >> B;
    r1 = R / 3 + G / 3 + B / 3;
    int r2 = min(R, min(G, B));
    int ans = (R - r2) / 3 + (G - r2) / 3 + (B - r2) / 3 + r2 ;
    if((R - r2) % 3 == 2)
        cnt++;
    if((G - r2) % 3 == 2)
        cnt++;
    if((B - r2) % 3 == 2)
        cnt++;
    if(cnt == 2 && r2)
        ans++;
    cout << max(ans, r1);
    return 0;
}


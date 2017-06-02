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
int arr[10];

int main()
{
    int i, j;
    LL ans = 1, cnt = 0, q = 0;
    string s;
    cin >> s;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == '?')
            q++;
        else if(s[i] >= 'A' && s[i] <= 'J')
            arr[s[i] - 'A']++;
    }
    for(i = 0; i < 10; i++)
        if(arr[i] > 0)
            cnt++;
    for(i = cnt, j = 10; i > 0; i--, j--)
        ans *= j;
    for(i = q; i > 0; i--)
        ans *= 10;
    LL mul = 0;
    if(s[0] >= 'A' && s[0] <= 'J')
    {
        mul = 1;
        for(i = cnt, j = 9; i > 1; i--, j--)
            mul *= j;
        for(i = q; i > 0; i--)
            mul *= 10;
    }
    else if(s[0] == '?')
    {
        while(q > 18);
        mul = 1;
    for(i = cnt, j = 10; i > 0; i--, j--)
        mul *= j;
        for(i = q; i > 1; i--)
            mul *= 10;
    }
    cout << ans - mul << endl;
    return 0;
}


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
#define SZ 1000010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[SZ], cum[SZ];

int main()
{
    string s, a = "heavy", b = "metal";
    cin >> s;
    int i, j;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == 'h')
        {
            for(j = i; j < i + 5; j++)
            {
                if(s[j] != a[j - i])
                    break;
            }
            if(j == i + 5)
                arr[i] = 1;
        }
        else if(s[i] == 'm')
        {
            for(j = i; j < i + 5; j++)
            {
                if(s[j] != b[j - i])
                    break;
            }
            if(j == i + 5)
                arr[i] = 2;
        }
    }
    for(i = 0;i < s.size() - 1; i++)
    {
        if(arr[i] == 1)
            cum[i + 1] = cum[i] + 1;
        else
            cum[i + 1] = cum[i];
    }
    LL cnt = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(arr[i] == 2)
            cnt += cum[i];
//        cout << cum[i] << ' ';
    }
    cout << cnt << endl;
    return 0;
}


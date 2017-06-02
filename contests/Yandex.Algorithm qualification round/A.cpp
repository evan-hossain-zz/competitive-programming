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
#define SZ 1000000010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    int n, l, ti, di, fteam = 0, steam = 0;
    cin >> n >> l;
    for(int i = 0; i < n; i++)
    {
        cin >> ti >> di;
        if(ti == 1)
        {
            if(di == -1)
                fteam++;
            else if(di > l)
                fteam += 3;
            else
                fteam += 2;
        }
        else
        {
            if(di == -1)
                steam++;
            else if(di > l)
                steam += 3;
            else
                steam += 2;
        }
    }
    cout << fteam << ":" << steam << endl;
    return 0;
}


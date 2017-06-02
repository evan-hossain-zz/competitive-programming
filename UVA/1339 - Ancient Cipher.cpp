//#include <vector>
//#include <map>
//#include <set>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <bitset>
//#include <algorithm>
//#include <sstream>
//#include <iostream>
//#include <time.h>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <cstring>
//#include <iomanip>
#include <bits/stdc++.h>

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

int main()
{
    int i, j;
    string a, b;
    int up[30], down[30];
    while(cin >> a >> b)
    {
        if(a.size() != b.size())
        {
            cout << "NO\n";
            continue;
        }
        clr(up, 0);
        clr(down, 0);
        for(i = 0; i < a.size(); i++)
        {
//            cout << a[i] << b[i] << endl;
            up[a[i] - 'A']++;
            down[b[i] - 'A']++;
        }
        sort(up, up + 30);
        sort(down, down + 30);
        for(i = 0; i < 30; i++)
        {
//            cout << up[i] << ' ' << down[i] << endl;
            if(up[i] != down[i])
                break;
        }
        if(i == 30)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}


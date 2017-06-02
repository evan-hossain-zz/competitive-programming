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

#define out freopen("number.out", "w", stdout);
#define in freopen("number.in", "r", stdin);
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
    in;
    out;
    string s;
    string tem, res = "99999999999999";
    while(cin >> s)
    {
        res = "99999999999999";
        int i, j, k, l;
        for(i = 0; i < s.size(); i++)
        {
            for(j = i + 1; j < s.size(); j++)
            {
                for(k = j + 1; k < s.size(); k++)
                {
                    for(l = k  + 1; l < s.size(); l++)
                    {
                        tem.clear();
                        tem += s[i];
                        tem += s[j];
                        tem += s[k];
                        tem += s[l];
//                        cout << tem << endl;
                        res = min(tem, res);
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}


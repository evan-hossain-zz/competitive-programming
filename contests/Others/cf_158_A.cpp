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
#define infinity 2147483647
#define LL long long

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    int b, n, i, j;
    string a;
    cin >> a >> b >> n;
    string na, nb, ns, ans = "0";
    for(j = 0; j < n;j ++)
    {
        for(i = 1; i < 10; i++)
        {
            ns = a + tostring(i);
            if(mod(ns,b) == 0)
            {
                ans = ns;
                a = ns;
                break;
            }
        }
    }
    if(ans != "0")
        cout << ans << endl;
    else
        cout << "-1" << endl;
    return 0;
}

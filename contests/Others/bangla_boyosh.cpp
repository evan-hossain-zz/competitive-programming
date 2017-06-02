#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#define infinity 21474

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

int daysinmonth(int n);
int ifleap(int n);

int main()
{
    int test, y, m, d, yy, mm, dd, leap, i, total = 0, now = 0;
    cin >> yy >> mm >> dd;
    now = dd + daysinmonth(mm - 1);
    if(mm > 11 && ifleap(yy))
        now++;
    cin >> test;
    while(test--)
        {
            cin >> y >> m >> d;
            if(y != yy)
                {
                    total = d + daysinmonth(m - 1);
                    if(m <= 11 && ifleap(y))
                        total--;
                    total = 365 - total + now;
                    for(i = y + 1; i < yy; i++)
                            total += 365 + ifleap(i);
                }
            else
                {
                    int pd = daysinmonth(mm - 1) + dd + ifleap(yy);
                    int nd = daysinmonth(m - 1) + d;
                    total = pd - nd;
                }
            cout << total << endl;
        }
    return 0;
}

int daysinmonth(int n)
{
    int ret = 0, i;
    for(i = 1; i <= n; i++)
        {
            if(i <= 5)
                ret += 31;
            else
                ret += 30;
        }
    return ret;
}

int ifleap(int n)
{
    if(n % 400 == 0)
        return 1;
    if(n % 100 == 0)
        return 0;
    if(n % 4 == 0)
        return 1;
    return 0;
}


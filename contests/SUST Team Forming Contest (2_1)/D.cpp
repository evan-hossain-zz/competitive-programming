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
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    int n, i, as, ds, a, b;
    cout << "Lumberjacks:\n";
    cin >> n;
    while(n--)
    {
        as = ds = 1;
        scanf("%d", &a);
        for(i = 1; i < 10; i++)
        {
            scanf("%d", &b);
            if(a > b)
                ds++;
            else
                as++;
            a = b;
        }
        if(as == 10 || ds == 10)
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }
    return 0;
}


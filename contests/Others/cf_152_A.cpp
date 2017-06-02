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

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

int rig[10005], lef[10005];

int main()
{
    int l, r, n, i, lo = 0, ro = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &l, &r);
        if(l == 0)
            lo++;
        if(r == 0)
            ro++;
    }
    cout << min(lo, n - lo) + min(ro, n - ro);
    return 0;
}

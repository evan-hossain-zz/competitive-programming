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
    int a, b, res = 0;
    cin >> a >> b;
    if(a > 1 && b == 0)
        res =(a - 1) * 4 + 1;
    else if(a == b && a > 0)
        res = (a - 1) * 4 + 1;
    else if(a == 0 && b > 0)
        res = (b- 1) * 4 + 2;
    else if(a == b && a < 0 && b > 0)
        res = (abs(b) - 1) * 4 + 2;
    else if(b == 0 && a < 0)
        res = (abs(a) - 1) * 4 + 3;
    else if(b == a && a < 0)
        res = (abs(a) - 1) * 4 + 3;
    return 0;
}


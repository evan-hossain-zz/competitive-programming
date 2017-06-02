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
#define Pi acos(-1) / 180
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    double a, b, c, d, e, f, kona, konb, konc, pori, area;
    int test, i;
    cin >> test;
    for(int kase = 1; kase <= test; kase++)
    {
        cin >> a >> b >> c;
        d = a + b;
        e = b + c;
        f = a + c;
        kona = acos((d * d + f * f - e * e) / (2 * d * f));
        konb = acos((d * d + e * e - f * f) / (2 * e * d));
        konc = acos((e * e + f * f - d * d) /(2 * e * f));
        pori = (d + e + f) / 2;
        area = sqrt(pori * (pori - d) * (pori - e) * (pori - f));
        d = area - ((a * a * kona / 2) + (b * b * konb / 2) + (c * c * konc / 2));
        printf("Case %d: %lf\n", kase, d);
    }
    return 0;
}


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
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    LL a, b, c;
    int test, kase;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        LL oti = max(a, max(b, c));
        oti = oti;
        LL ekbahu = min(a, min(b, c));
        ekbahu = ekbahu;
        LL opor = a + b + c - (ekbahu + oti);
        opor = opor;
//        cout << oti << ' ' << ekbahu << ' ' << opor << endl;
        if(oti * oti == ekbahu * ekbahu + opor * opor)
            printf("Case %d: yes\n", kase);
        else
            printf("Case %d: no\n", kase);
    }
    return 0;
}


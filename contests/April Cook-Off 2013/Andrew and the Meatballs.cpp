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
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <LL> v;

int main()
{
    int n, i, j, test;
    LL m, pi;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %lld", &n, &m);
        for(i = 0; i < n; i++)
        {
            scanf("%lld", &pi);
            v.pub(pi);
        }
        sort(v.rbegin(), v.rend());
        LL sum = 0;
        for(i = 0; i < n; i++)
        {
            sum += v[i];
            if(sum >= m)
                break;
        }
        if(i >= n)
            printf("-1\n");
        else
            printf("%d\n", i + 1);
        v.clear();
    }
    return 0;
}


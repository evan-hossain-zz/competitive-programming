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

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

vector <int> rp;

int main()
{
    int test, k, n, i, j, ager, notun;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &k);
        if(k == 1)
        {
            printf("%d\n", n);
            continue;
        }
        for(i = 2; i <= n && rp.size() < k; i += 2)
            rp.pub(i);
        if(rp.size() == k)
        {
            for(i = 0; i < rp.size() - 1; i++)
                printf("%d ", rp[i]);
            printf("%d\n", rp[i]);
        }
        else
            printf("-1");
        rp.clear();
    }
    return 0;
}

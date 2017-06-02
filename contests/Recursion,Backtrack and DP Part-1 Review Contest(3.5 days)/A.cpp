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
#define SZ 20

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int numbers, next, arr[SZ];
int subsets[1 << 15][20], ans[20], subinfo[1 << 15];

LL lcm(LL a, LL b);
LL gcd(LL a, LL b);
void generate_subset(int indx, int ansin);

int main()
{
//    out;
    int n, test, i, j;
    LL res;
    int baad;
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
    {
        next = baad = 0;
        memset(subinfo, 0, sizeof(subinfo));
        scanf("%d %d", &n, &numbers);
        for(i = 0; i < numbers; i++)
            scanf("%d", &arr[i]);
        generate_subset(0, 0);
        next--;
        for(i = 0; i < next; i++)
        {
            res = 1;
            for(j = 0; j < subinfo[i]; j++)
                res = lcm(res, subsets[i][j]);
            if(subinfo[i] & 1)
                    baad += n / res;
            else
                    baad -= n / res;
        }
        printf("Case %d: %d\n", kase, n - baad);
    }
    return 0;
}

void generate_subset(int indx, int ansin)
{
    if(indx >= numbers)
    {
        for(int i = 0; i < ansin ; i++)
            subsets[next][i] = ans[i];
        subinfo[next] = ansin;
        next++;
        return;
    }
    ans[ansin] = arr[indx];
    generate_subset(indx + 1, ansin + 1);
    generate_subset(indx + 1, ansin);
}

LL lcm(LL a, LL b)
{
    return (a * b) / gcd(a, b);
}

LL gcd(LL a, LL b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

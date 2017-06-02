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
#define SZ 2001

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int I[SZ], seq[SZ], LI[SZ], LD[SZ];

void input(void);
void lis(int n);
void lds(int n);

int main()
{
    int test, n, i, m;
    scanf("%d", &test);
    while(test--)
        {
            m = 0;
            scanf("%d", &n);
            for(i = n - 1; i >= 0; i--)
                scanf("%d", &seq[i]);
            lis(n);
            lds(n);
            for(i = 0; i < n; i++)
                //m = max(m, LI[i] + LD[i] - 1);
                printf("%d %d\n", LI[i], LD[i]);
            printf("%d\n", m);
        }
    return 0;
}

void lis(int n)
{
    int i, low, high, mid, len = 0;
    I[0] = -infinity;
    for(i = 1; i < n; i++)
        I[i] = infinity;
    for(i = 0; i < n; i++)
        {
            low = 0, high = len;
            while(low <= high)
                {
                    mid = low + high >> 1;
                    if(I[mid] < seq[i])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            I[low] = seq[i];
            LI[i] = low;
            if(low > len)
                len = low;
        }
    return;
}

void lds(int n)
{
    int i, low, high, mid, len = 0;
    for(i = 0; i < n; i++)
        I[i] = infinity;
    for(i = 0; i < n; i++)
        {
            low = 0, high = len;
            while(low <= high)
                {
                    mid = low + high >> 1;
                    if(I[mid] > seq[i])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            I[low] = seq[i];
            LD[i] = low;
            if(low > len)
                len = low;
        }
    return;
}

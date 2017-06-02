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
//#define LL long long
#define Pi acos(-1)
#define SZ 10001

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int LR[SZ], LL[SZ], I[SZ], seq[SZ], b[SZ];

void input(int n);
void flis(int n);
void blis(int n);

int main()
{
    int n, m, pos;
    while(scanf("%d", &n) == 1)
    {
        m = pos = -infinity;
        input(n);
        flis(n);
        blis(n);
        for(int i = 0; i < n; i++)
            m = max(m, min(LL[i], LR[i]));
        printf("%d\n", (m << 1) - 1);
    }
    return 0;
}

void input(int n)
{
    int i = 0, j = n - 1;
    while(i < n)
    {
        scanf("%d", &seq[i]);
        b[j--] = seq[i++];
    }
}

void flis(int n)
{
    int i, low, high, len = 0, mid;
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
        LL[i] = low;
        if(low > len)
            len = low;
    }
    return;
}

void blis(int n)
{
    int i, low, high, mid, len = 0, j;
    I[0] = -infinity;
    for(i = 1; i < n; i++)
        I[i] = infinity;
    for(i = 0, j = n - 1; i < n; i++, j--)
    {
        low = 0, high = len;
        while(low <= high)
        {
            mid = low + high >> 1;
            if(I[mid] < b[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = b[i];
        LR[j] = low;
        if(low > len)
            len = low;
    }
    return;
}

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
#define Pi 2*acos(0)

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct info
{
    int w, s;
}arr[1001];

struct info2
{
    int w, s, pos;
}tem[1001];

bool comp(const info2 &a, const info2 &b)
{
    return a.w > b.w;
}

int L[1001], I[1001];

void LIS(int n);
void printseq(int n, int len);

int main()
{
    int s, w, i = 0;
    while(scanf("%d %d", &arr[i].w, &arr[i].s) == 2)
    {
        tem[i].s = arr[i].s;
        tem[i].w = arr[i].w;
        tem[i].pos = i + 1;
        i++;
    }
    sort(&tem[0], &tem[i], comp);
    LIS(i);
    return 0;
}

void LIS(int n)
{
    int i, j, mid, low, high, length = 0;
    I[0] = -infinity;
    for(i = 1; i <= n; i++)
        I[i] = infinity;
    for(i = 0; i < n; i++)
    {
        low = 0, high = length;
        while(low <= high)
        {
            mid = low + high >> 1;
            if(I[mid] < tem[i].s)
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = tem[i].s;
        L[i] = low;
        if(low > length)
            length = low;
    }
    printseq(n, length);
}

void printseq(int n, int len)
{
    int i, j, pos, res[len], val = len, indx = 0;
    for(i = 0; i < n; i++)
    {
        if(L[i] == val)
        {
            pos = i;
            res[indx++] = tem[pos].pos;
            val--;
            break;
        }
    }
    for(i = pos - 1; i >= 0; i--)
    {
        if(L[i] == val && tem[pos].s > tem[i].s)
        {
            res[indx++] = tem[i].pos;
            val--;
            pos = i;
        }
    }
    printf("%d\n", indx);
    for(i = 0; i < indx; i++)
        printf("%d\n", res[i]);
}

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
#define SZ 1000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int L[SZ], I[SZ],seq[SZ], res[SZ];
char str[100];

void input(void);
void lis(int n);
void pri(int n, int len);

int main()
{
    input();
    return 0;
}

void input(void)
{
    int i = 0, test;
    scanf("%d", &test);
    getchar();
    getchar();
    while(test--)
    {
        i = 0;
        while(gets(str) && strlen(str))
        {
            sscanf(str, "%d", &seq[i]);
            i++;
        }
        lis(i);
        if(test)
            printf("\n");
    }
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
        L[i] = low;
        if(low > len)
            len = low;
    }
    printf("Max hits: %d\n", len);
    pri(n, len);
}

void pri(int n, int len)
{
    int pos, i, cur = len;
    for(i = 0; i < n; i++)
    {
        if(L[i] == cur)
        {
            pos = i;
            res[cur - 1] = seq[i];
            cur--;
            break;
        }
    }
    for(i = pos - 1; cur > 0 && i >= 0; i--)
    {
        if(L[i] == cur && seq[pos] > seq[i])
        {
            pos = i;
            res[cur - 1] = seq[i];
            cur--;
        }
    }
    for(i = 0; i < len; i++)
        printf("%d\n", res[i]);
}

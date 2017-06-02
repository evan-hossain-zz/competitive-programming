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

int main()
{
    int n, q, i, mid, beg, en, item, kase = 0;
    int arr[10010];
    while(scanf("%d %d", &n, &q) == 2 && (n | q))
    {
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        sort(&arr[0], &arr[n]);
        printf("CASE# %d:\n", ++kase);
        for(i = 0; i < q; i++)
        {
            scanf("%d", &item);
            beg = 0, en = n - 1;
            while(beg <= en)
            {
                mid = (beg + en) >> 1;
                if(arr[mid] < item)
                    beg = mid + 1;
                else if(arr[mid] > item)
                    en = mid - 1;
                else
                    break;
            }
            while(arr[mid - 1] == item)
                mid--;
            if(arr[mid] == item)
                printf("%d found at %d\n", item, mid + 1);
            else
                printf("%d not found\n", item);
        }
    }
    return 0;
}


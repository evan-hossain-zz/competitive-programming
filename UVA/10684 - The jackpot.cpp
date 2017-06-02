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
#define SZ 10010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

void input(int *data, int n);
int max_sum(int *data, int n);

int main()
{
    int n, arr[SZ], ans;
    while(scanf("%d", &n) == 1 && n)
    {
        input(arr, n);
        ans = max_sum(arr, n);
        if(ans > 0)
            printf("The maximum winning streak is %d.\n", ans);
        else
            printf("Losing streak.\n");
    }
    return 0;
}

void input(int *data, int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    return;
}

int max_sum(int *data, int n)
{
    int sum,start, en, i, tem, ret;
    sum = tem = start = en = ret = 0;
    for(i = 0; i < n; i++)
    {
        sum += data[i];
        if(sum < 0)
        {
            //tem = i + 1;
            sum = 0;
        }
        else if(sum > ret)
        {
            ret = sum;
//            en = i;
//            start = tem;
        }
    }
    return ret;
}

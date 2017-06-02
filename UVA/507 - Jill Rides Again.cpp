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
#define SZ 20020

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct info
{
    int start, en, sum;
};

void input(int *data, int n);
info max_sum(int *data, int n);

int main()
{
    int n, test, i, arr[SZ];
    info res;
    scanf("%d", &test);
    for(i = 1; i <= test; i++)
        {
            scanf("%d", &n);
            n--;
            input(arr, n);
            res = max_sum(arr, n);
            if(res.sum > 0)
                printf("The nicest part of route %d is between stops %d and %d\n", i, res.start + 1, res.en + 2);
            else
                printf("Route %d has no nice parts\n", i);
        }
    return 0;
}

void input(int *data, int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    return;
}

info max_sum(int *data, int n)
{
    int i, sum, tem;
    info ret;
    ret.en = ret.start = ret.sum = sum = tem = 0;
    for(i = 0; i < n; i++)
        {
            sum += data[i];
            if(sum < 0)
                {
                    tem = i + 1;
                    sum = 0;
                }
            else if(sum > ret.sum)
                {
                    ret.sum = sum;
                    ret.start = tem;
                    ret.en = i;
                }
            else if(sum == ret.sum && (ret.en - ret.start) < (i - tem))
                {
                    ret.start = tem;
                    ret.en = i;
                }
        }
    return ret;
}

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
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

double dp[110];
int value[110], n;

double call(int uthsilo, int curpos);

int main()
{
    int test, i;
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
        {
            for(int j = 0; j < 105; j++)
                dp[j] = 0;
            scanf("%d", &n);
            for(i = 0; i < n; i++)
                scanf("%d", &value[i]);
            call(0, 0);
            printf("Case %d: %lf\n", kase, dp[0]);
        }
    return 0;
}

double call(int uthsilo, int curpos)
{
    if(curpos >= n)
        return 0;
    if(dp[curpos] != 0)
        return dp[curpos];
    int cnt = 0;
    double sum = 0, tem;
    for(int i = 1; i < 7; i++)
        {
            tem = call(i, i + curpos);
            if(tem != 0)
                {
                    cnt++;
                    sum += tem;
                }
        }
    if(cnt)
        return dp[curpos] = sum / (double) cnt + value[curpos];
    else
        return dp[curpos] = sum + value[curpos];
}


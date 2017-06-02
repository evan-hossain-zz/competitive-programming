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

int arr[21][21];

int main()
{
    int in1[21], in2[21], i, j, n, tem[21];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &tem[i]);
    for(i = 0; i < n; i++)
        in1[tem[i] - 1] = i;
    while(scanf("%d", &tem[0]) == 1)
        {
            for(i = 1; i < n; i++)
                scanf("%d", &tem[i]);
            for(i = 0; i < n; i++)
                in2[tem[i] - 1] = i;
            for(i = 1; i <= n; i++)
                {
                    for(j = 1; j <= n; j++)
                        {
                            if(in1[i - 1] == in2[j - 1])
                                arr[i][j] = arr[i - 1][j - 1] + 1;
                            else
                                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                        }
                }
            printf("%d\n", arr[i - 1][j - 1]);
            for(i = 0; i <= n; i++)
                arr[i][0] = arr[0][i] = 0;
        }
    return 0;
}


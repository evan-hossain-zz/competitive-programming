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

int arr[105][105], arr1[105], arr2[105];

int main()
{
    int n1, n2, i, j, kase = 0;
    while(scanf("%d %d", &n1, &n2) == 2 && (n1 | n2))
        {
            for(i = 0; i < n1; i++)
                scanf("%d", &arr1[i]);
            for(i = 0; i < n2; i++)
                scanf("%d", &arr2[i]);
            for(i = 1; i <= n1; i++)
                {
                    for(j = 1; j <= n2; j++)
                        {
                            if(arr1[i - 1] == arr2[j - 1])
                                arr[i][j] = arr[i - 1][j - 1] + 1;
                            else
                                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                        }
                }
            printf("Twin Towers #%d\n", ++kase);
            printf("Number of Tiles : %d\n\n", arr[i - 1][j - 1]);
            j = max(n1, n2);
            for(i = 0; i <= j; i++)
                arr[i][0] = arr[0][i] = 0;
        }
    return 0;
}


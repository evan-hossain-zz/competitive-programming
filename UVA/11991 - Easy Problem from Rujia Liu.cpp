#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 1000010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <int> pos[SZ];
int arr[SZ];

int main()
{
    int n, i, k, num, m, indx, mx;
    while(scanf("%d %d", &n, &m) == 2)
    {
        for(indx = 1, mx = 0; indx <= n; indx++)
        {
            scanf("%d", &num);
            arr[num]++;
            mx = max(num, mx);
            pos[num].pub(indx);
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &k, &num);
            if(arr[num] < k)
                printf("0\n");
            else
                printf("%d\n", pos[num][k - 1]);
        }
        for(i = 1; i <= mx; i++)
            arr[i] = 0, pos[i].clear();
    }
    return 0;
}


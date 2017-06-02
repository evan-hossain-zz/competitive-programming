#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

int arr[105][105];
void initialize(int n);
void floyed(int n);

int main()
{
    int c, s, q, i, a, b, w, kase = 0;
    while(scanf("%d %d %d", &c, &s, &q) == 3 && (c | s))
    {
        initialize(c);
        for(i = 0; i < s; i++)
        {
            scanf("%d %d %d", &a, &b, &w);
            arr[a][b] = arr[b][a] = w;
        }
        floyed(c);
        if(kase)
            printf("\n");
        printf("Case #%d\n", ++kase);
        for(i = 0; i < q; i++)
        {
            scanf("%d %d", &a, &b);
            if(arr[a][b] == infinity)
                printf("no path\n");
            else
                printf("%d\n", arr[a][b]);
        }
    }
    return 0;
}

void initialize(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            arr[i][j] = infinity;
        arr[i][i] = 0;
    }
    return ;
}

void floyed(int n)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                arr[i][j] = min(arr[i][j], max(arr[i][k], arr[k][j]));
    return;
}


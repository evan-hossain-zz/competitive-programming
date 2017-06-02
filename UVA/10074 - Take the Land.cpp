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
#define SZ 110

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[SZ][SZ];

void input(int m, int n);
int max_sum(int m,int n);

int main()
{
    int n, m, i;
    while(scanf("%d %d", &m, &n) == 2 && (m | n))
    {
        input(m, n);
        printf("%d\n", max_sum(m, n));
    }
    return 0;
}

void input(int m, int n)
{
    int i, j, k;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &k);
            if(k)
                arr[i][j] = -11000;
            else
                arr[i][j] = 1;
        }
//    cout << endl;
//     for(i = 1; i <= m; i++)
//    {
//        for(j = 1; j <= n; j++)
//            cout << arr[i][j] << ' ';
//        cout << endl;
//    }
    return;
}

int max_sum(int m, int n)
{
    int i, mx = 0, j, c1,c2, r, sum;
    for(i = 0; i <= m; i++)
        arr[i][0] = 0;
    for(i = 0; i <= n; i++)
        arr[0][i] = 0;
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
            arr[i][j] += arr[i][j - 1];
    }
//    cout << endl;
//    for(i = 1; i <= m; i++)
//    {
//        for(j = 1; j <= n; j++)
//            cout << arr[i][j] << ' ';
//        cout << endl;
//    }
    for(c1 = 1; c1 <= n; c1++)
    {
        for(c2 = c1; c2 <= n; c2++)
        {
            sum = 0;
            for(r = 1; r <= m; r++)
            {
                sum += (arr[r][c2] - arr[r][c1 - 1]);
                if(sum < 0)
                    sum = 0;
                else if(sum > mx)
                    mx = sum;
            }
        }
    }
    return mx;
}

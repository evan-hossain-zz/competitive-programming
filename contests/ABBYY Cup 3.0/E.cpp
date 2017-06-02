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
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

LL mod = 1000000000;

LL arr[2 * SZ+10], fibon[2 * SZ+10];

LL fibo(int n)
{
    if(n < 2)
        return fibon[n] = 1;
    if(fibon[n] != -1)
        return fibon[n];
    return fibon[n] = (fibo(n - 1) + fibo(n - 2)) % mod;
}

int main()
{
    int n, m, i, j, a, b, q;
    clr(fibon, -1);
    fibo(2*SZ);
    while(cin >> n)
        cout << fibon[n] << endl;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    for(int k = 0; k < m; k++)
    {
        scanf("%d", &q);
        if(q == 1)
        {
            cin >> a >> b;
            arr[a] = b;
        }
        if(q == 2)
        {
            cin >> a >> b;
            LL sum = 0;
            for(j = 0; j <= b - a; j++)
            {
                LL tem = (arr[a + j] % mod) * (fibon[j] % mod) % mod;
                sum = (sum + tem) % mod;
            }
            cout << sum << endl;
        }
    }
    return 0;
}


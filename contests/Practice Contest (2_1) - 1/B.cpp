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

struct info
{
    int prime, pwr;
};

int arr[110];

bool isprime(int n)
{
    int i;
    for(i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
                return 0;
        }
    return 1;
}

int main()
{
    int n, i, div, j, test, kase;
    cin >> test;
    for(kase = 1; kase <= test; kase++)
        {
            memset(arr, 0, sizeof arr);
            cin >> n;
            for(i = 2; i <= n; i++)
                {
                    int pcnt = 0, tem = n;
                    if(isprime(i))
                        {
                            tem /= i;
                            while(tem)
                                {
                                    pcnt += tem;
                                    tem /= i;
                                }
                            arr[i] = pcnt;
                        }
                }
            printf("Case %d: %d = ", kase, n);
            if(arr[2] != 0)
                printf("2 (%d)", arr[2]);
            for(i = 3; i <= n; i++)
                {
                    if(arr[i] != 0)
                        printf(" * %d (%d)", i, arr[i]);
                }
                cout << endl;
        }
return 0;
}


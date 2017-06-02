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

int a, b, c, d, e, f;
long long dp[10010];

long long fn( int n )
{
    if( n == 0 ) return dp[n] = a;
    if( n == 1 ) return dp[n] = b;
    if( n == 2 ) return dp[n] = c;
    if( n == 3 ) return dp[n] = d;
    if( n == 4 ) return dp[n] = e;
    if( n == 5 ) return dp[n] = f;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ) % 10000007;
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        memset(dp, -1, sizeof dp);
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}



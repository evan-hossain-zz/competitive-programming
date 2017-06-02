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
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

bool isprime(int n)
{
    if(n <= 1)
        return false;
    int lim = sqrt(n);
    for(int i = 2; i <= lim; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, i, a, cnt = 0, res = 0, b, q, p;
    cin >> n;
    for(a = 4; a <= n; a++)
    {
//        cout << a << endl;
        int lim = a / 2;
        cnt = 0;
        for(i = 2; i <= lim; i++)
        {
            if(a % i == 0 && (a / i != i) && isprime(i))
                cnt++;
        }
        if(cnt == 2)
            res++;
    }
    cout << res << endl;
    return 0;
}


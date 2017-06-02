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

#define out freopen("proddiff.out", "w", stdout);
#define in freopen("proddiff.in", "r", stdin);
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

vector <int> divisors;
vector <int> res;
vector <int> tem;
int num, mx, color[50000], taken[25];

void factorize(int n)
{
    int i, j, k, limit = sqrt(n);
    for(i = 2; i <= limit; i++)
    {
        if(n % i == 0)
        {
            tem = n;
            while()
        }
    }
    if(n == 1);
    else if(n < 50000)
    {
        if(color[n] == 0)
            divisors.pub(n);
    }
    else
        divisors.pub(n);
    return;
}

int main()
{
//    in;
//    out;
    int n, i;
    while(cin >> n)
    {
        clr(taken, 0);
        mx = 0;
        num = n;
        factorize(n);
        cout << res.size() + 1 << endl;
        for(i = 0; i < res.size(); i++)
            cout << res[i] << ' ';
        cout << 1 << endl;
        res.clear();
    }
    return 0;
}



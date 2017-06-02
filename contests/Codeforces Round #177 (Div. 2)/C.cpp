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

int main()
{
    int n, k, i;
    string s;
    cin >> n >> k;
    if(k == 1)
    {
        if(n == 1)
            cout << "a";
        else
            cout << -1;
        return 0;
    }
    if(k > n)
    {
        cout << -1;
        return 0;
    }
    for(i = 1; i <= n - k; i += 2)
        cout << "ab";
    if(abs(n - k) % 2 == 1)
    {
        cout << 'a';
        for(i = 'c'; i < 'c' + k - 2; i++)
            printf("%c", i);
    }
    else
    {
        for(i = 'a'; i < 'a' + k; i++)
            printf("%c", i);
    }
    return 0;
}


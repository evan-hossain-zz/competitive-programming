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
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    vector <int> w;
    int n, k, i, dif, kase, a, b;
    scanf("%d", &kase);
    while(kase--)
    {
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; i++)
            cin >> dif, w.pub(dif);
        sort(w.begin(), w.end());
        a = b = 0;
        for(i = 0; i < n; i++)
        {
            if(i < k)
                a += w[i];
            else
                b += w[i];
        }
        dif = abs(a - b);
        a = b = 0;
        for(i = n - 1; i >= 0; i--)
        {
            if(i > n - k - 1)
                a += w[i];
            else
                b += w[i];
        }
        dif = max(dif, abs(a - b));
        printf("%d\n", dif);
        w.clear();
    }
    return 0;
}


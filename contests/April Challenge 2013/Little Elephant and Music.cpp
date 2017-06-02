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

#define out freopen("myoutput.txt", "w", stdout);
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

struct info
{
    int band, len;
} arr[SZ];
int mark[SZ];

bool comp(const info &a, const info &b)
{
    return a.len < b.len;
}

int main()
{
//    in;
//    out;
    int t, n, b, l, i, a, j, mc;
    scanf("%d", &t);
    while(t--)
    {
        map <int, int> m;
        mc = 0;
        memset(mark, 0, sizeof mark);
        LL sum;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &arr[i].len);
            if(m.find(a) == m.end())
                m[a] = mc++;
            arr[i].band = m[a];
        }
        sort(arr, arr + n, comp);
        LL cnt = 0, mul = m.size();
//        cout << mul << endl;
        sum = 0;
        for(i = 0; i < n; i++)
        {
            if(!mark[arr[i].band])
            {
                cnt++;
                mark[arr[i].band] = 1;
                sum += (cnt * (LL)arr[i].len);
//                cout << sum << endl;
            }
            else
                sum += (mul * (LL)arr[i].len);
        }
        printf("%lld\n", sum);
    }
    return 0;
}


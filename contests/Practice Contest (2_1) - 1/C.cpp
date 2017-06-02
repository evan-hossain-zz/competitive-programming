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
#define SZ 10010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    int indeg[SZ], a, b, n, m, test, cnt, i,mpc;
    cin >> test;
    for(int kase = 1; kase <= test; kase++)
    {
        map <int, int> mp;
        cin >> n >> m;
        cnt = mpc = 0;
        for(i = 1; i <= n; i++)
            indeg[i] = 0;
        while(m--)
        {
            cin >> a >> b;
            if(mp.find(a) == mp.end())
                mp[a] = ++mpc;

            if(mp.find(b) == mp.end())
                mp[b] = ++mpc;

            if(mp[a] != mp[b])
                indeg[mp[b]] = 1;
        }
        for(i = 1; i <= mpc; i++)
        {
            if(indeg[i] == 0)
                cnt++;
        }
        if(!cnt)
            printf("Case %d: 1\n", kase);
        else
            printf("Case %d: %d\n", kase, cnt);
    }
    return 0;
}


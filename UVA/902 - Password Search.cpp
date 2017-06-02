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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    string s;
    int n, m, i, limit, j;
    while(scanf("%d", &n) == 1)
    {
        map <string, int> mp;
        cin >> s;
        limit = s.size();
        m = 0;
        for(i = 0; i < limit; i++)
        {
            string t;
            for(j = i; j < n + i && j < limit; j++)
                t += s[j];
            mp[t]++;
            m = max(mp[t], m);
        }
        map <string, int> :: iterator it;
        for(it = mp.begin(); it != mp.end(); it++)
        {
            if(m == it ->second)
            {
                cout << it ->first << endl;
                break;
            }
        }
    }
    return 0;
}


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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int indeg[110];
vector <int> v[110];

int cnt;

void dfs(int start);

int main()
{
    //out;
    map <int , int> mp;
    int a, b, kase = 0, i, j, m;
    while(scanf("%d %d", &a, &b) == 2 && a >= 0)
        {
            if(a == 0 && b == 0)
            {
                printf("Case %d is a tree.\n", ++kase);
                continue;
            }
            m = cnt = 0;
            if(mp.find(a) == mp.end())
                mp[a] = m++;
            if(mp.find(b) == mp.end());
            mp[b] = m++;
            v[mp[a]].pub(mp[b]);
            indeg[mp[b]]++;
            while(scanf("%d %d", &a, &b) == 2 && (a | b))
                {
                    if(mp.find(a) == mp.end())
                        mp[a] = m++;
                    if(mp.find(b) == mp.end())
                        mp[b] = m++;
                    v[mp[a]].pub(mp[b]);
                    indeg[mp[b]]++;
                }
            for(i = 0; i < m; i++)
            {
                if(indeg[i] == 0)
                {
                    cnt = m;
                    dfs(i);
                    break;
                }
            }
            if(cnt == 1)
                printf("Case %d is a tree.\n", ++kase);
            else
                printf("Case %d is not a tree.\n", ++kase);
            for(i = 0; i < m; i++)
            {
                indeg[i] = 0;
                v[i].clear();
            }
            mp.clear();
        }
    return 0;
}

void dfs(int start)
{
    int i;
    for(i = 0; i < v[start].size(); i++)
    {
        if(indeg[v[start][i]] == 1)
        {
            indeg[v[start][i]] = 0;
            cnt--;
            dfs(v[start][i]);
        }
    }
}

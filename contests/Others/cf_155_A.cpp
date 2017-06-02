#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

vector <int> v[5005];

int main()
{
    in;
    out;
    int n, x, i, m, flag;
    while(scanf("%d", &n) == 1)
        {
            n *= 2;
            m = 0;
            for(i = 1; i <= n; i++)
                {
                    scanf("%d", &x);
                    m = max(m, x);
                    v[x].pub(i);
                }
            flag = 1;
            for(i = 1; i <= m; i++)
                {
                    if(v[i].size() % 2 != 0)
                        flag = 0;
                }
            if(flag == 0)
                printf("-1\n");
            else
                {
                    for(i = 1; i <= m && n; i++)
                        {
                            while(v[i].size() % 2 == 0 && v[i].size())
                                {
                                    int a = v[i][v[i].size() - 1];
                                    v[i].pob();
                                    int b = v[i][v[i].size() - 1];
                                    v[i].pob();
                                    printf("%d %d\n", a, b);
                                    n -= 2;
                                }
                        }
                }
            for(i = 1; i <= m; i++)
                v[i].clear();
        }
    return 0;
}


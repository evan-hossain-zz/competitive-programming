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

stack <string> st[52];

void keep(int indx);

int main()
{
    int i, j;
    string s;
    while(cin >> s && s != "#")
        {
            st[0].push(s);
            for(i = 1; i < 52; i++)
                {
                    cin >> s;
                    st[i].push(s);
                }
            for(i = 0; i < 52; i++)
                keep(i);
                //cout << st[i].top() << endl;
            for(i = 0; i < 52; i++)
                cout << st[i].size() << endl;
        }
    return 0;
}

void keep(int indx)
{
    int k;
    if(indx == 0 || st[indx].empty())
        return;
    if(indx > 2)
        {
            if((st[indx - 3].top()[0] == st[indx].top()[0]) ||
                    (st[indx - 3].top()[1] == st[indx].top()[1]))
                {
                    st[indx - 3].push(st[indx].top());
                    st[indx].pop();
                    if(st[indx].empty())
                        {
                            for(k = indx; !st[k + 1].empty(); k++)
                                st[k] = st[k + 1];
                            while(!st[k].empty())
                                st[k].pop();
                        }
                    keep(indx - 3);
                }
        }
    else if((st[indx - 1].top()[0] == st[indx].top()[0]) ||
            (st[indx - 1].top()[1] == st[indx].top()[1]))
        {
            st[indx - 1].push(st[indx].top());
            st[indx].pop();
            if(st[indx].empty())
                {
                    for(k = indx; !st[k + 1].empty(); k++)
                        st[k] = st[k + 1];
                    while(!st[k].empty())
                        st[k].pop();
                }
            keep(indx - 1);
        }
}

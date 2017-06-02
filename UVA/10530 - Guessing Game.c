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

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;


struct game
{
    int n;
    string s;
} in;

bool comp(const game &a, const game &b)
{
    return a.n < b.n;
}

vector <game> v;

int main()
{
    int num, res;
    string ss;
    game g;
    while(scanf("%d", &num) == 1 && num)
    {
        cin >> ss;
        if(ss == "right on");
        {
            res = true;
            sort(v.begin, v.end(), comp);
            for(i = 0; i < v.size(); i++)
            {
                if(v[i].s == "too high")
                {
                    if(v[i].n <= num)
                        res = false;
                }
                else
                {
                    if(v[i].n >= num)
                        res = false;
                }
            }
            if(res)
                printf("Stan may be honest\n");
            else
                printf("Stan is dishonest\n");
        }
        g.n = num;
        g.s = ss;
        v.pub(g);
    }
    return 0;
}

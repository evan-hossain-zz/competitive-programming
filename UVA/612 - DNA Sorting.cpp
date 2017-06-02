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

using namespace std;


struct node
{
    string s;
    int inversions;
};

int cnt;
bool comp(const char &a, const char &b)
{
    if(a < b)
        cnt++;
    return a < b;
}

bool comp2(const node &a, const node &b)
{
    return a.inversions < b.inversions;
}

int main()
{
    string str;
    vector <node> v;
    node t;
    int m, n, tst, i;
    scanf("%d", &tst);
    while(tst--)
        {
            scanf("%d %d", &m, &n);
            for(i = 0; i < n; i++)
                {
                    cin >> str;
                    t.s = str;
                    int l = str.size();
                    for(int j = 0; j < l - 1; j++)
                    {
                        for(int k = j + 1; k < l; k++)
                            if(str[j] > str[k])
                                cnt++;
                    }
                    t.inversions = cnt;
                    v.pub(t);
                    cnt = 0;
                }
            stable_sort(v.begin(), v.end(), comp2);
            for(i = 0; i < v.size(); i++)
                cout << v[i].s << endl;
            if(tst)
            {
                printf("\n");
                v.clear();
            }
        }
}

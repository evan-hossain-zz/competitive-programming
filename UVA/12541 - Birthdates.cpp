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

struct info
{
    string name;
    int dd, mm, yy;
};
vector <info> v;

bool comp(const info &a, const info &b)
{
    if(a.yy != b.yy)
        return a.yy < b.yy;
    if(a.mm != b.mm)
        return a.mm < b.mm;
    return a.dd < b.dd;
}

int main()
{
    int n;
    info i;
    while(scanf("%d", &n) == 1)
    {
        v.clear();
        while(n--)
        {
            cin >> i.name >> i.dd >> i.mm >> i.yy;
            v.pub(i);
        }
        sort(v.begin(), v.end(), comp);
        cout << v[v.size() - 1].name << endl << v[0].name << endl;
    }
    return 0;
}

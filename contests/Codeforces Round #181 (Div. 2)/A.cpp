#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <int> f;
vector <int> s;
vector <int> t;

int main()
{
    int n, i, m;
    cin >> n;
    while(n--)
    {
        cin >> m;
        if(m == 0)
            t.pub(0);
        else if(m < 0 && f.empty())
            f.pub(m);
        else if(m > 0 )
            s.pub(m);
        else
            t.pub(m);
    }
    sort(t.rbegin(), t.rend());
    if(s.size() == 0)
    {
        s.pub(t[t.size() - 1]);
        s.pub(t[t.size() - 2]);
        t.resize(t.size() - 2);
    }
    cout << f.size();
    for(i = 0; i < f.size(); i++)
        cout << ' ' << f[i];
    cout << endl << s.size();
    for(i = 0; i < s.size(); i++)
        cout << ' ' << s[i];
    cout << endl << t.size();
    for(i = 0; i < t.size(); i++)
        cout << ' ' << t[i];
    cout << endl;
    return 0;
}

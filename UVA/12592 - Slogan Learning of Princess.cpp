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
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    string a, b;
    char s[110], t[110];
    map<string, int> stringtoint;
    map<int, string> inttostring;
    int n, q, i, m = 0;
    scanf("%d ", &n);
    while(n--)
    {
        while(gets(s) && strlen(s) == 0);
        a = s;
        while(gets(t) && strlen(t) == 0);
        b = t;
        stringtoint[a] = m;
        inttostring[m] = b;
        m++;
    }
    scanf("%d ", &q);
    while(q--)
    {
        while(gets(s) && strlen(s) == 0);
        a = s;
        cout << inttostring[stringtoint[a]] << endl;
    }
    return 0;
}


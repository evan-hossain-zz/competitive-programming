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

map <char, int> mp;
int taken[21], n;
char arr[21];
vector <int> v[130];
vector <char> res;

void backtrack(char c);

int main()
{
    string a, b;
    char c, d;
    int n, i;
    while(getline(cin , a) && getline(cin, b))
        {
            i = 0;
            stringstream sa(a);
            while(sa >> arr[i])
                mp[arr[i]] = i++;
            stringstream sb(b);
            while(sb >> c >> d)
                v[d].pub(c);
            n = i;
            cout << n << endl;
            for(i = 0; i < n; i++)
                {
                    taken[i] = 1;
                    backtrack(arr[i]);
                }
            cout << " ic";
        }
    return 0;
}

void backtrack(char c)
{
    if(res.size() == n)
        {
            for(int k = 0; k < n; k++)
                cout << res[k];
            cout << endl;
            return;
        }
    for(int l = 0; l < v[c].size(); l++)
        {
            if(taken[mp[v[c][l]]] == 0)
            {
                taken[mp[c]] = 1;
                backtrack(v[c][l]);
            }
        }
    res.pub(c);
    for(int k = 0; k < n; k++)
        {
            if(taken[k] == 0)
                {
                    cout << k << endl;
                    taken[k] = 1;
                    backtrack(arr[k]);
                    res.pob();
                    taken[k] = 0;
                }
        }
}

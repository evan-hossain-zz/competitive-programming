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
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
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

int color[2000], ai[110], bi[110];

vector <int> bot[110];

int main()
{
    map <int, int> mp;
    int n, i, a, b, m = 0;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a >> b;
        ai[i] = a;
        bi[i] = b;
    }
    int cnt = 0;
    for(i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && ai[i] == bi[j])
                cnt++;
        }
    }
    cout << n - cnt << endl;
    return 0;
}


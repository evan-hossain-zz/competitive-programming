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
#define SZ 10010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[SZ];
vector <int> v;

int main()
{
    int n, i, pos, mn = infinity, cnt = 0, flag = 1;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(flag)
            v.pub(arr[i]);
        if(arr[i] == 1)
            flag = 0;
    }
    for(i = 0; i < v.size() - 1 ; i++)
    {
        if(v[i] > v[i + 1])
            cnt++;
    }
    cout << cnt << endl;
}


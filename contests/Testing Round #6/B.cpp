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

int arr[SZ  *2];
vector <int> ans;
stack <int> s;

int main()
{
    int n, k, i, j, a, l;
    cin >> n >> k;
    for(i = 1; i <= k; i++)
    {
        cin >> a >> l;
        arr[a] += 1;
        arr[a + l] -= 1;
    }
    cout << endl;
    for(i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
        cout << arr[i] << ' ';
    }
    cout << endl;
    for(i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ' ;
        if(arr[i] > arr[i] - 1)
            s.push(arr[i] - arr[i - 1]);
        else if(arr[i] < arr[i - 1])
        {
            int val = arr[i - 1] - arr[i];
            ans.pub(val);
            while(s.top() == val)
                s.pop();
        }
    }
    cout << ans.size() << endl;
    for(i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}


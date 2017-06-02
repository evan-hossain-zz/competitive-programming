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
#define SZ 20010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    int n, g, s, i, num, rem = 0, g_needs = 0, mx = 0, part_g = 0, days = 0, j;
    vector <int> prob;
    cin >> n >> g >> s;
    for(i = 0; i < n; i++)
    {
        cin >> num;
        prob.pub(num);
    }
    sort(prob.begin(), prob.end());
    for(i = 0, j = n - 1; i < n && i <= j; i++, j--)
    {
        rem += (prob[i] % g);
        if(rem >= s)
        {
            rem = rem % s;
            days++;
        }
        days += (prob[j] / g);
    }
//    if(rem)
//        days++;
    cout << days << endl;
    return 0;
}


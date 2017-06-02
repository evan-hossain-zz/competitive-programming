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
#define SZ 1000010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[SZ];

const int divi = 33102;

void calculate(void)
{
    int cur = 46870, i, j, rem;
    for(i = 0; i < SZ; i++)
    {
        arr[i] = cur / divi;
        cur = (cur - (divi * arr[i])) * 10;
    }
}

int main()
{
    int i, test, n;
    calculate();
    cin >> test;
    while(test--)
    {
        cin >> n;
        cout << 3;
        if(n)
            cout << '.';
        for(i = 0; i < n; i++)
            cout << arr[i];
        cout << endl;
    }
    return 0;
}


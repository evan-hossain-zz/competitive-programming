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

int arr[26];

int main()
{
    int ch = 0, bis = 0, bac = 0, i, n, ans;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < n; i += 3)
        ch += arr[i];
    for(i = 1; i < n; i += 3)
        bis += arr[i];
    for(i = 2; i < n; i += 3)
        bac += arr[i];
    ans = max(ch, max(bis, bac));
    if(ans == ch)
        printf("chest");
    else if(ans == bis)
        printf("biceps");
    else if(ans == bac)
        printf("back");
    return 0;
}


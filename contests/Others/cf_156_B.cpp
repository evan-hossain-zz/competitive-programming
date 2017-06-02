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

int main()
{
    int x = 0, y = 0, i;
    char c;
    while(scanf("%c", &c) && c != '\n')
    {
        if(c == 'x')
            x++;
        else if(c == 'y')
            y++;
    }
    int ans = x - y;
    if(ans > 0)
        for(i = 0; i < ans; i++)
            printf("x");
    else
    {
        ans = -ans;
        for(i = 0; i < ans; i++)
            printf("y");
    }
    return 0;
}

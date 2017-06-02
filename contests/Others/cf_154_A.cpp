#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
    in;
    out;
    int i, j, b, g;
    while(scanf("%d %d", &b, &g) == 2)
    {
        if(b > g)
        {
            for(i = g; i < b; i++)
                printf("B");
            for(i = 0; i < g; i++)
                printf("GB");
        }
        else
        {
            for(i = b; i < g; i++)
                printf("G");
            for(i = 0; i < b; i++)
                printf("BG");
        }
        printf("\n");
    }
    return 0;
}


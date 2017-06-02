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
#define Pi 2*acos(0)

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[101][101];

int main()
{
    char str1[101], str2[101];
    int i, j, kase = 0, n, l1, l2;
    while(gets(str1) && strcmp(str1, "#"))
    {
        gets(str2);
        l1 = strlen(str1);
        l2 = strlen(str2);
        for(i = 1; i <= l1; i++)
        {
            for(j = 1; j <= l2; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                else
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", ++kase, arr[i - 1][j - 1]);
        j = max(l1, l2);
        for(i = 0; i <= j; i++)
            arr[i][0] = arr[0][i] = 0;
    }
    return 0;
}


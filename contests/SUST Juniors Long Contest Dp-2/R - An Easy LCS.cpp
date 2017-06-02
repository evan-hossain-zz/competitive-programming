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
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int LCS[110][110];
string path[110][110];
char arr1[110], arr2[110];

int main()
{
    int test, kase, i, j;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        scanf(" %s %s", &arr1, &arr2);
        int len1 = strlen(arr1);
        int len2 = strlen(arr2);
        for(i = 1; i <= len1; i++)
            for(j = 1; j <= len2; j++)
            {
                if(arr1[i - 1] == arr2[j - 1])
                {
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                    path[i][j] = path[i - 1][j - 1] + arr1[i - 1];
                }
                else
                {
                    if(LCS[i - 1][j] > LCS[i][j - 1])
                    {
                        LCS[i][j] = LCS[i - 1][j];
                        path[i][j] = path[i - 1][j];
                    }
                    else if(LCS[i - 1][j] < LCS[i][j - 1])
                    {
                        LCS[i][j] = LCS[i][j - 1];
                        path[i][j] = path[i][j - 1];
                    }
                    else
                    {
                        LCS[i][j] = LCS[i][j - 1];
                        path[i][j] = min(path[i - 1][j], path[i][j - 1]);
                    }
                }
            }
        i--, j--;
        if(LCS[i][j] == 0)
        {
            printf("Case %d: :(\n", kase);
            continue;
        }
        printf("Case %d: %s\n", kase, path[i][j].c_str());
    }
    return 0;
}


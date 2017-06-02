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

int arr[15];

int main()
{
    char str[30];
    int m, sum, n;
    while(scanf("%d", &n) == 1 && n)
        {
            m = sum = 0;
            for(int i = 0; i < n; i++)
                {
                    arr[i] = 0;
                    scanf(" %[^\n]", str);
                    int l = strlen(str);
                    for(int j = 0; j < l; j++)
                        {
                            if(str[j] == 'X')
                                arr[i]++;
                        }
                    m = max(arr[i], m);
                }
            for(int i = 0; i < n; i++)
                sum += (m - arr[i]);
            printf("%d\n", sum);
        }
    return 0;
}

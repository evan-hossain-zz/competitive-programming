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
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[40];

int main()
{
    char ch;
    int i, word = 0, m = 0;
    while(scanf("%c", &ch) == 1)
    {
        if((ch >= 'A' && ch <= 'Z') ||
                (ch>= 'a' && ch <= 'z'))
                word++;
        else if(ch == '-')
        {
            ch = getchar();
            if((ch >= 'A' && ch <= 'Z') ||
                (ch>= 'a' && ch <= 'z'))
                word++;
        }
        else if(ch == '\'')
            continue;
        else if(ch == '#')
        {
            arr[word]++;
            for(i = 1; i <= m; i++)
            {
                if(arr[i])
                {
                    printf("%d %d\n", i, arr[i]);
                    arr[i] = 0;
                }
            }
            printf("\n");
            arr[0] = 0;
            m = 0;
        }
        else
        {
            m = max(word, m);
            arr[word]++;
            word = 0;
        }
    }
    return 0;
}


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
#define Pi acos(-1)
#define SZ 20

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    int i, c, num;
    cin >> num;
    bool flag = false;
    for(i = num + 1;; i++)
    {
        string b;
        int temp = i;
        for(int k = 3; k >= 0; k--)
        {
            b += (temp % 10) + '0';
            temp = temp / 10;
        }
        flag = 0;
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                if(b[j] == b[k] && k != j)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            continue;
        else
        {
            reverse(b.begin(), b.end());
            cout << b << endl;
            return 0;
        }
    }
}

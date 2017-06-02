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
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};

using namespace std;

int res[3][3];

int main()
{
    int i, j, n;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            {
                cin >> n;
                if(n & 1)
                    {
                        res[i][j] = !res[i][j];
                        for(int k = 0; k < 4; k++)
                            {
                                int nr = i + row[k];
                                int nc = j + col[k];
                                if(nr >= 0 && nr < 3 && nc >= 0 && nc < 3)
                                    res[nr][nc] = !res[nr][nc];
                            }
                    }
            }
    for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
                cout << !res[i][j];
            cout << endl;
        }
    return 0;
}


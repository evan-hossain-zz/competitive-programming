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

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

vector <int > folder, v;

int main()
{
    int cnt, i, j, n, neg = 0, num, end = 0;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &num);
        v.pub(num);
    }
    cnt = 0;
    for(i = 0; i < v.size(); i++)
    {
        cnt++;
        if(v[i] < 0)
            neg++;
        if(neg == 3)
        {
            neg = 0;
            folder.pub(cnt - 1);
            end = i;
            cnt = 0;
            i -= 2;
        }
    }
    if(end != i)
        folder.pub(i - end - 1);
    cout << folder.size() << endl;
    for(i = 0; i < folder.size(); i++)
        cout << folder[i] << " ";
    return 0;
}

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

vector <int> v[105];
char lok[105];

int main()
{
//    in;
//    out;
    int t, p, test, i, j, k, pr, hr, cnt;
    scanf("%d", &test);
    char str[10];
    while(test--)
    {
        scanf("%d %d", &p, &t);
        while(getchar() != '\n');
        cnt = 0;
        while(gets(str) && strlen(str))
        {
            int flag = 1;
            sscanf(str, "%d %d ", &pr, &hr);
            for(i = 0; i < v[pr].size(); i++)
            {
                if(v[pr][i] == hr)
                    flag = 0;
            }
            if(flag)
                v[pr].pub(hr);
            if(!lok[pr])
            {
                lok[pr] = 1;
                cnt++;
            }
        }
        if(cnt < p)
            cnt++;
        for(i = 1; i <= p; i++)
            sort(v[i].begin(), v[i].end());
        for(i = 1; i < p; i++)
        {
            if(v[i].size())
            {
                for(j = i + 1; j <= p; j++)
                {
                    if(v[i] == v[j])
                    {
                        v[j].clear();
                        lok[j] = 0;
                        cnt--;
                    }
                }
                v[i].clear();
            }
            lok[i] = 0;
        }
        v[i].clear();
        lok[i] = 0;
        cout << cnt << endl;
        if(test)
            printf("\n");
    }
    return 0;
}

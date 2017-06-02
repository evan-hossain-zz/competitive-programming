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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    int ni, no, i, fault = 0, kase = 0, tem, j;
    string s;
    while(scanf("%d", &ni) == 1 && ni)
    {
        while(getchar() != '\n');
        vector <string> vi, vo;
        string a, b;
        for(i = 0; i < ni; i++)
        {
            getline(cin, s);
            vi.pub(s);
        }
        scanf("%d", &no);
        while(getchar() != '\n');
        for(i = 0; i < no; i++)
        {
            getline(cin, s);
            vo.pub(s);
        }
        if(ni != no)
            fault = 1;
        for(i = 0; i < ni && !fault; i++)
        {
            if(vi[i] != vo[i])
            {
                fault = 1;
                break;
            }
        }
        if(!fault)
            printf("Run #%d: Accepted\n", ++kase);
        else
        {
            for(i = 0; i < ni; i++)
            {
                for(j = 0; j < vi[i].size(); j++)
                {
                    if(vi[i][j] >= '0' && vi[i][j] <= '9')
                        a += vi[i][j];
                }
            }
            for(i = 0; i < no; i++)
            {
                for(j = 0; j < vo[i].size(); j++)
                {
                    if(vo[i][j] >= '0' && vo[i][j] <= '9')
                        b += vo[i][j];
                }
            }
            if(a == b)
                printf("Run #%d: Presentation Error\n", ++kase);
            else
                printf("Run #%d: Wrong Answer\n", ++kase);
            fault =0;
        }
    }
    return 0;
}

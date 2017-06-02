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

/*
vector <int> arr[205][205];

int main()
{
    string s;
    int i, j;
    while(cin >> s)
        {
            vector <string> v1, v2;
            if(s != "#")
                {
                    v1.pub(s);
                    while(cin >> s && s != "#")
                        v1.pub(s);
                }
            while(cin >> s && s != "#")
                v2.pub(s);
            i = j = 1;
            for(i = 1; i <= v1.size(); i++)
                {
                    for(j = 1; j <= v2.size(); j++)
                        {
                            if(v1[i - 1] == v2[j - 1])
                                {
                                    arr[i - 1][j].pub(i - 1);
                                    arr[i][j] = arr[i - 1][j];
                                }
                            else
                                {
                                    if(arr[i - 1][j].size() > arr[i][j - 1].size())
                                        arr[i][j] = arr[i - 1][j];
                                    else
                                        arr[i][j] = arr[i][j - 1];
                                }
                        }
                }
            if(arr[i - 1][j - 1].size())
                {
                    cout << v1[arr[i - 1][j - 1][0]];
                    for(int k = 1; k < arr[i - 1][j - 1].size(); k++)
                        printf(" %s", v1[arr[i - 1][j - 1][k]].c_str());
                    printf("\n");
                }
            else
                printf("\n");
            j = max(v1.size(), v2.size());
            for(i = 0; i <= j; i++)
                arr[i][0].clear(), arr[0][i].clear();
        }
    return 0;
}*/
vector <string> v1, v2;

int arr[205][205], flag;

vector <string> v;

void pri(int i, int j);

int main()
{
    string s;
    int i, j;
    while(cin >> s)
        {
            if(s != "#")
                {
                    v1.pub(s);
                    while(cin >> s && s != "#")
                        v1.pub(s);
                }
            while(cin >> s && s != "#")
                v2.pub(s);
            i = j = 1;
            for(i = 1; i <= v1.size(); i++)
                {
                    for(j = 1; j <= v2.size(); j++)
                        {
                            if(v1[i - 1] == v2[j - 1])
                                arr[i][j] = arr[i - 1][j - 1] + 1;
                            else
                                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                        }
                }
            pri(v1.size(), v2.size());
            printf("\n");
            j = max(v1.size(), v2.size());
            for(i = 0; i <= j; i++)
                arr[i][0] = arr[0][i] = 0;
            v1.clear(), v2.clear();
            flag = 0;
        }
    return 0;
}

void pri(int i,int j)
{
    if (i==0 || j==0)
        return;
    if (v1[i-1]==v2[j-1])
        {
            pri(i-1,j-1);
            if(flag)
                printf(" %s", v1[i - 1].c_str());
            else
                {
                    flag = 1;
                    printf("%s", v1[i - 1].c_str());
                }
        }
    else if (arr[i - 1][j] >arr[i][j - 1])
        pri(i-1,j);
    else
        pri(i,j-1);
}

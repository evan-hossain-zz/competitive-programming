#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#define debug(args...){dbg,args; cerr<<endl;}args
using namespace std;


int rec(int x,int last_first, int last_second, int n,int a[],int ans[][55][55])
{
    // debug("In rec()",x,last_first,last_second);
    if(last_first>=0&&last_second>=0&&ans[x][last_first][last_second]!=-1)
        return ans[x][last_first][last_second];
    if (x>n-1)
    {
        return ans[x][last_first][last_second]=0;
    }

    int MAX=0;
    for (int i = x; i <n; ++i)
    {
        if (last_first==-1)
        {
            MAX=max(MAX,a[i]+rec(i+1,i,last_second,n,a,ans));
        }
        else
        {
            if (last_second==-1)
            {
                MAX=max(MAX,a[i]+rec(i+1,last_first,i,n,a,ans));
            }
            else
            {
                int next=max(5-(last_second-last_first+1),0)+last_second+1;
                if(i>=next)
                {
                    MAX=max(MAX,a[i]+rec(i+1,last_second,i,n,a,ans));
                }
            }
        }
    }
    return ans[x][last_first][last_second]=MAX;
}
int main()
{
    freopen("input.in", "r", stdin);
    int n,x;
    while(cin >> n)
    {
        int a[n];
        for(int i=0;i < n;i++)
        {
            cin>>x;
            a[i]=x;
        }
        int ans[55][55][55];
        memset(ans,-1,sizeof(ans));
        cout<<rec(0,-1,-1,n,a,ans)<<endl;
    }
    return 0;
}
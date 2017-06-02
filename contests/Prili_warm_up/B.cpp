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
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define SZ(v) (int)(v.size())
#define eps 10e-7

#define F(i, n) for(i = 0; i < n; i++)

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;
vector <int> arr[1000010];
int crr[1000010];

int main()
{
_
int i, n, test, m, x, y;
cin >> test;
while(test--)
{
cin >> n >> m;
for(i = 0; i <= n; i++){
arr[i].clear();
crr[i]=0;
}
for(i = 0; i< m; i++)
{
cin >> x >> y;
arr[y].pb(x);
}
if(arr[n].empty())
{
cout << 2 << ' ' << n << endl;
continue;
}
int c=0,b=-1,a=-1;
for(int i=0;i<arr[n].size();i++)
if(arr[n][i]==n-1)
a=n-1;
else if(crr[arr[n][i]]==0&&arr[n][i]==n-2){
crr[n-2]=1;
b=n-2;
c++;
}
else if(crr[arr[n][i]]==0){
crr[arr[n][i]]=1;
c++;
}
if(a!=-1&&arr[a].size()==0)
{
if(arr[n-2].empty())
cout<<1<<endl;
else
cout<<0<<endl;
continue;
}
else if(arr[n-1].empty())
{
cout<<1<<endl;
continue;
}
int f=0;
for(int i=0;i<arr[n-1].size();i++)
if(crr[arr[n-1][i]]==0||c>=2){
f=1;
cout<<0<<endl;
break;
}
if(f)
continue;
if(a==-1)
{
cout<<1<<endl;
continue;
}
if(arr[n-2].empty())
cout<<1<<endl;
else
cout<<0<<endl;
}
return 0;
}

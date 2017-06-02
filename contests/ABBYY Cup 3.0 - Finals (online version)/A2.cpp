#include <iostream>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <climits>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <numeric>
#include <functional>
#include <utility>
#include <iomanip>
#include <iterator>
#include <stack>
#include <limits>
#include <sstream>
#include <fstream>
#include <ostream>
#include <bitset>
#include <queue>
#include <ctime>
#include <utility>

#define fori(i,j,n) for(int i=j;i<n;i++)
#define gint(n) scanf("%d",&n)
#define gint2(a,b) scanf("%d%d",&a,&b)
#define ms(a,n) (memset(a,n,sizeof(a)))
#define msv(a,v,n) for(int _a;_a<=n;_a++) a[_a]=v;
#define all(res) res.begin(),res.end()
#define mp(a,b) (make_pair(a,b))
#define pb(n) push_back(n)
#define forv(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define mod 1000000007

using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

typedef long long ll;
typedef vector< int> VI;
typedef vector< vector<int> > VVI;
typedef pair< int, int> PII;
typedef map< string, int> MSI;

ostream_iterator<int> screen(cout," ");
//copy(res.begin(),res.end(),screen);

const int  sz=3*1000*100+10;
const int inf=INT_MAX>>1;
const ll big=(1<<62);
const double pi =acos(-1.0);
int dx[]={0,0,1,-1,1,1,-1,-1},dy[]={1,-1,0,0,1,-1,1,-1};
VI res;
map<int,int>mpp;
ll arr[sz],csum[sz];

ll powermod(ll n,ll p)
{
    if(p==0)
        return 1;
    ll a=powermod(n,p/2)%mod;
    if(p%2==1)
        return (a*a*n)%mod;
    return (a*a)%mod;
}
int main()
{
    ll n,neg=0,x,y;
    ll mx=-big;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]>=0)
            csum[i]=csum[i-1]+arr[i];
        else
            csum[i]=csum[i-1];
        if(!mpp[arr[i]])
            mpp[arr[i]]=i;
    }
    for(int i=n;i>0;i--)
    {
        int p=mpp[arr[i]];
        if(p!=i)
        {
            //cout<<i<<endl;
            if(mx<csum[i-1]-csum[p]+2*arr[i])
            {
                mx=csum[i-1]-csum[p]+2*arr[i];
                x=p;
                y=i;
            }
        }
    }
    int a=0;
    for(int i=1;i<=n;i++)
    {
        if(i==x or i==y or (i>=x and i<=y and arr[i]>0))
        {

        }
        else
            a++;

    }
    cout<<mx<<' '<<a<<endl;
    for(int i=1;i<=n;i++)
    {
        if(i==x or i==y or (i>=x and i<=y and arr[i]>0))
        {

        }
        else
            cout<<i<<' ';

    }

    return 0;
}

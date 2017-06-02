#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<sstream>

typedef long long ll;
typedef unsigned long long ull; //scanf("%llu",&N);
#define READ(a) freopen("a.txt","r",stdin)
#define WRITE(a) freopen("a.txt","w",stdout)
#define FOR(i,a,b)  for(int i=(a);i<b;i++)
#define REV(i,a,b)  for(int i=a;i>=b;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define clr(a) a.clear()
#define mp make_pair
#define pb push_back
#define SZ(a) (int)a.size()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define fs first
#define sc second
#define PI (2*acos(0.0))
#define ERR (1e-7)
#define EQ(a,b) (fabs(a-b)<ERR)
//#define FOREACH(it,x) for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

using namespace std;
typedef vector<int>     VI;
typedef vector<string>  VS;
typedef pair<int,int>   PII;
typedef pair<int,PII >  DPII;
typedef vector<pair<int,int> >VPII;
typedef vector<pair<int,pair<int,int> > > VDPII;

const int INF=(1<<29);
const int MAX=20000009;

VS V;

int ok(int d)
{
    for(int i=0;i<SZ(V);i++)
    {
        for(int j=0;j<SZ(V[i]);j++)
        {
            if(i==0 || i==d+1 || i==(2*d+2))
            {
               // cout<<"AS--->>> u"<<i<<" "<<j<<endl;
                if(j==0) if(V[i][j]!='.') return 0;
                else if(j==d) if(V[i][j]!='.')  return 0;
                else
                {
                    if(V[i][j]!='-') return 0;
                }
            }
            else
            {
                //cout<<"AS--->>> Two"<<i<<" "<<j<<endl;
                if(j==0) if(V[i][j]!='|') return 0;
                else if(j==d) if(V[i][j]!='|')  return 0;
                else
                {
                    if(V[i][j]!='.') return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        clr(V);
        string s;
        set<int>S;

        while(cin>>s)
        {
            if(s=="*") break;
            V.pb(s);
            S.insert(SZ(s));
        }
        int r=SZ(V);
        r=r-3;

        printf("Case %d: ",++cas);
        if(r%2 || SZ(S)>1|| r<0) puts("Bad");
        else
        {
            int d=r/2;
            if(ok(d)) printf("%d\n",d);
            else puts("Bad");
        }
    }
    return 0;
}


/***


4
.---.
|...|
|...|
|...|
.---.
|...|
|...|
|...|
.---.
*

.---.
|...|
|...|
|...|
.---.
|...|
|...|
.---.
*

..
..
..

*
...
.-.
|.|
.-.
|.|
.-.
*

*/





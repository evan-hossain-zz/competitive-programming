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

const int INF=(1<<30);
const int MAX=200009;

struct abc
{
    int x,y,z;
    abc(){;}
    abc(int xx,int yy,int zz)
    {
        x=xx;y=yy;z=zz;
    }
    void input() { scanf("%d %d %d",&x,&y,&z);}
};

abc arr[MAX];


int ko(int minx,int mxx,int miny,int mxy,int minz,int mxz,int n)
{
    for(int i=0;i<n;i++)
    {
        if( (arr[i].x>=minx && arr[i].x<=mxx && arr[i].y>=miny && arr[i].y<=mxy  && arr[i].z>=minz && arr[i].z<=mxz) &&
           (arr[i].x==mxx || arr[i].x==minx || arr[i].y==mxy || arr[i].y==miny || arr[i].z==mxz ||  arr[i].z==minz))
        {
            ;
        }
        else return 0;

    }
    return 1;
}

bool solve(int mx,int n,int minx, int maxx,int miny, int maxy,int minz, int maxz)
{
    if(ko(minx, minx + mx, miny, miny + mx, minz, minz + mx, n)) return true;
    if(ko(minx, minx + mx, miny, miny + mx, maxz - mx, maxz, n)) return true;
    if(ko(minx, minx + mx, maxy - mx, maxy, minz, minz + mx, n)) return true;
    if(ko(minx, minx + mx, maxy - mx, maxy, maxz - mx, maxz, n)) return true;
    if(ko(maxx - mx, maxx, miny, miny + mx, minz, minz + mx, n)) return true;
    if(ko(maxx - mx, maxx, miny, miny + mx, maxz - mx, maxz, n)) return true;
    if(ko(maxx - mx, maxx, maxy - mx, maxy, minz, minz + mx, n)) return true;
    if(ko(maxx - mx, maxx, maxy - mx, maxy, maxz - mx, maxz, n)) return true;
    return false;
}

int main()
{
    int t,n;
    int cas=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int mxx=-INF,minx=INF;
        int mxy=-INF,miny=INF;
        int mxz=-INF,minz=INF;
        FOR(i,0,n)
        {
            arr[i].input();
            mxx=max(mxx,arr[i].x);
            mxy=max(mxy,arr[i].y);
            mxz=max(mxz,arr[i].z);

            minx=min(minx,arr[i].x);
            miny=min(miny,arr[i].y);
            minz=min(minz,arr[i].z);
        }

        int mx=max(mxx-minx,max(mxy-miny,mxz-minz));
        if(solve(mx,n, minx, mxx,miny, mxy, minz, mxz))
            printf("Case %d: %d\n",++cas,mx);

        else printf("Case %d: -1\n",++cas);
    }

    return 0;
}








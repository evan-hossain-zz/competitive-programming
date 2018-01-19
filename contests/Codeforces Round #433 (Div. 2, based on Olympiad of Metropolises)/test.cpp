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
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> PII;
typedef pair <long long,long long> PLL;

typedef unsigned long long int ULL;
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

#define FRE(i,a,b)      for(i = a; i <= b; i++)
#define FRL(i,a,b)      for(i = a; i < b; i++)
#define mem(t, v)       memset ((t) , v, sizeof(t))
#define un(x)           x.erase(unique(all(x)), x.end())
#define sf(n)           scanf("%d", &n)
#define sff(a,b)        scanf("%d %d", &a, &b)
#define sfff(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define xx              first
#define yy              second

#define si(a)           scanf("%d",&a)
#define sii(a,b)        scanf("%d %d",&a,&b)
#define siii(a,b,c)     scanf("%d %d %d",&a,&b,&c)

#define sl(a)           scanf("%lld",&a)
#define sll(a,b)        scanf("%lld %lld",&a,&b)
#define slll(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)

#define pb              push_back
#define mp              make_pair
#define all(v)          v.begin(),v.end()
#define D(x)            cerr << #x " = " << x << '\n'
#define DBG             cerr << "Hi!" << '\n'

#define CLR(a)          memset(a,0,sizeof(a))
#define SET(a)          memset(a,-1,sizeof(a))

#define eps             1e-9
#define PI              acos(-1.0)

int setBit(int n,int pos){ return n = n | (1 << pos); }
int resetBit(int n,int pos){ return n = n & ~(1 << pos); }
bool checkBit(int n,int pos){ return (bool)(n & (1 << pos)); }

//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction

/******************************************************************************************/
#define MAX     1000000
struct flight{
    int node;
    LL cost;
};
vector<flight>in[MAX+10], out[MAX+10];
LL bestStart[MAX+10], bestEnd[MAX+10];
LL got[MAX+10];
int main()
{
   freopen("input.in","r",stdin);
//    freopen("out.txt","w",stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n, m, k, i, j, d, f, t, c;
    sfff(n,m,k);
    FRE(i,1,m)
    {
        sff(d,f);
        sff(t,c);
        if(f == 0)
        {
            in[d].pb({t,c});
        }
        else
        {
            out[d].pb({f,c});
        }
    }
    int have = 0;
    LL best = 0;
    FRE(i,1,MAX)
    {
        for(int j = 0; j<out[i].size(); j++)
        {
            int node = out[i][j].node;
            LL c = out[i][j].cost;
            if(got[node] == 0)
            {
                have++;
                got[node] = c;
                best += c;
            }
            else if(got[node] > c)
            {
                best -= (got[node] - c);
                got[node] = c;
            }
        }
        if(have == n)
            bestStart[i] = best;
    }

    mem(got,0);
    have = 0;
    best = 0;
    for(int i = MAX; i>=1; i--)
    {
        for(int j = 0; j<in[i].size(); j++)
        {
            int node = in[i][j].node;
            LL c = in[i][j].cost;
            if(got[node] == 0)
            {
                have++;
                got[node] = c;
                best += c;
            }
            else if(got[node] > c)
            {
                best -= (got[node] - c);
                got[node] = c;
            }
        }
        if(have == n)
            bestEnd[i] = best;
    }

    LL ans = 1e18;
    for(int st = 1; st<=MAX; st++)
    {
        int ed = (st+k+1);
        if(ed > MAX)
            break;
        if(bestStart[st] != 0 && bestEnd[ed] != 0)
            ans = min(ans, bestStart[st] + bestEnd[ed]);
    }
    if(ans == 1e18)
        ans = -1;
    cout << ans << endl;
    return 0;
}

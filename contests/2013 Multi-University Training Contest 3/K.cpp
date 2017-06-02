#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <set>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> LL getdist(T a, T b){return sqr(a.first - b.first) + sqr(a.second - b.second);}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);}}cincout;

#define MAX 500010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

set <pair<LL,LL>> ss;
LL X[MAX], Y[MAX];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL test, n, i, ax, bx , cx, ay, by, cy;
    cin >> test;
    while(test--)
    {
        cin >> n >> ax >> bx >> cx >> ay >> by >> cy;
        for(i = 1; i <= n; i++)
            X[i] = (X[i-1]*ax+bx)%cx;
        for(i = 1; i <= n; i++)
            Y[i] = (Y[i-1]*ay+by)%cy;
        LL res = 0;
        ss.clear();
        pair <LL,LL> cur;
        set <pair<LL,LL>> :: iterator pt, C;
        ss.insert(mp(X[1], Y[1]));
        LL mn = 1e18;
        for(i = 2; i <= n; i++)
        {
            cur = mp(X[i], Y[i]);
            if(ss.find(cur) != ss.end())
                break;
            ss.insert(cur);
            C = ss.find(cur);
            pt = C;
            while(++pt != ss.end())
            {
                mn = min(mn, getdist(*pt, *C));
                if(mn < sqr((*pt).first-(*C).first))
                    break;
            }
            pt = C;
            while(pt-- != ss.begin())
            {
                mn = min(mn, getdist(*pt, *C));
                if(mn < sqr((*pt).first-(*C).first))
                    break;
            }
            res += mn;
        }
        cout << res << "\n";
    }
    return 0;
}

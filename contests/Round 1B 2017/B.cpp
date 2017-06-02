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

#define in freopen("input.in", "r", stdin);
#define out freopen("output_small.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
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

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 1010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int R, O, Y, G, B, V;

string com(string s)
{
    string ret = "";
    for(auto x: s)
    {
        if(x != '#')
            ret += x;
    }
    return ret;
}
int main()
{
    in;
    out;
    int test, kase = 1, i, n;
    cin >> test;
    while(test--)
    {
        cin >> n >> R >> O >> Y >> G >> B >> V;
        string s;
        int m = max(R, max(Y, B));
        for(int i = 0; i < n; i++)
            s += '#';
        s += "##";
        if(m == R)
        {
            for(i = 0; i < SZ(s) && R--; i += 3)
                s[i] = 'R';
            int m2 = max(Y, B);
            if(m2 == 'Y')
            {
                for(i = 1; i < SZ(s) && Y--; i += 3)
                    s[i] = 'Y';
                for(i = SZ(s)-1; i >= 0 && B--; i -= 3)
                    s[i] = 'B';
            }
            else
            {
                for(i = 1; i < SZ(s) && B--; i += 3)
                    s[i] = 'B';
                for(i = SZ(s)-1; i >= 0 && Y--; i -= 3)
                    s[i] = 'Y';
            }
        }
        if(m == Y)
        {
            for(i = 0; i < SZ(s) && Y--; i += 3)
                s[i] = 'Y';
            int m2 = max(R, B);
            if(m2 == 'R')
            {
                for(i = 1; i < SZ(s) && R--; i += 3)
                    s[i] = 'R';
                for(i = SZ(s)-1; i >= 0 && B--; i -= 3)
                    s[i] = 'B';
            }
            else
            {
                for(i = 1; i < SZ(s) && B--; i += 3)
                    s[i] = 'B';
                for(i = SZ(s)-1; i >= 0 && R--; i -= 3)
                    s[i] = 'R';
            }
        }
        if(m == B)
        {
            for(i = 0; i < SZ(s) && B--; i += 3)
                s[i] = 'B';
            int m2 = max(Y, R);
            if(m2 == 'R')
            {
                for(i = 1; i < SZ(s) && R--; i += 3)
                    s[i] = 'R';
                for(i = SZ(s)-1; i >= 0 && B--; i -= 3)
                    s[i] = 'B';
            }
            else
            {
                for(i = 1; i < SZ(s) && B--; i += 3)
                    s[i] = 'B';
                for(i = SZ(s)-1; i >= 0 && R--; i -= 3)
                    s[i] = 'R';
            }
        }
        cout << s << endl;
        string r = com(s);
        for(i = 0; i < SZ(r); i++)
        {
            int nx = (i+1)%SZ(r);
            if(r[i] == r[nx])
            {
                r = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << kase++ << ": " << r << "\n";
        cerr << "Case #" << kase-1 << ": " << r << "\n";
    }
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 
















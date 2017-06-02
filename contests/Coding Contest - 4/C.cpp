#include <bits/stdc++.h>

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
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL nand(LL a, LL b)
{
    int len = log2(max(a, b))+1;
    if(max(a, b) == 0)
        len = 1;
    LL ret = 0;
    for(int i = 0; i < len; i++)
    {
        int abit = ((1LL<<i) & a) != 0;
        int bbit = ((1LL<<i) & b) != 0;
        if(!(abit&bbit))
            ret |= (1LL<<i);
    }
    return ret;
}
LL nor(LL a, LL b)
{
    int len = log2(max(a, b))+1;
    if(max(a, b) == 0)
        len = 1;
    LL ret = 0;
    for(int i = 0; i < len; i++)
    {
        int abit = ((1LL<<i) & a) != 0;
        int bbit = ((1LL<<i) & b) != 0;
        if(!(abit|bbit))
            ret |= (1LL<<i);
    }
    return ret;
}
LL xnor(LL a, LL b)
{
    int len = log2(max(a, b))+1;
    if(max(a, b) == 0)
        len = 1;
    LL ret = 0;
    for(int i = 0; i < len; i++)
    {
        int abit = ((1LL<<i) & a) != 0;
        int bbit = ((1LL<<i) & b) != 0;
        if(!(abit^bbit))
            ret |= (1LL<<i);
    }
    return ret;
}
LL _xor(LL a, LL b)
{
    int len = log2(max(a, b))+1;
    if(max(a, b) == 0)
        len = 1;
    LL ret = 0;
    for(int i = 0; i < len; i++)
    {
        int abit = ((1LL<<i) & a) != 0;
        int bbit = ((1LL<<i) & b) != 0;
        if(abit^bbit)
            ret |= (1LL<<i);
    }
    return ret;
}
LL _and(LL a, LL b)
{
    int len = log2(max(a, b))+1;
    if(max(a, b) == 0)
        len = 1;
    LL ret = 0;
    for(int i = 0; i < len; i++)
    {
        int abit = ((1LL<<i) & a) != 0;
        int bbit = ((1LL<<i) & b) != 0;
        if(abit&bbit)
            ret |= (1LL<<i);
    }
    return ret;
}
LL _or(LL a, LL b)
{
    int len = log2(max(a, b))+1;
    if(max(a, b) == 0)
        len = 1;
    LL ret = 0;
    for(int i = 0; i < len; i++)
    {
        int abit = ((1LL<<i) & a) != 0;
        int bbit = ((1LL<<i) & b) != 0;
        if(abit|bbit)
            ret |= (1LL<<i);
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    cout <<nand(1, 2);
    LL a, b, r;
    vector <string> res;
    int test, kase = 1;
    cin >> test;
    while(test--)
    {
        res.clear();
        cin >> a >> b >> r;
        assert(a >= 0);
        assert(b >= 0);
        assert(r >= 0);
        if(_and(a, b) == r)
            res.pb("AND");
        if(_or(a, b) == r)
            res.pb("OR");
        if(_xor(a, b) == r)
            res.pb("XOR");
        if(nand(a, b) == r)
            res.pb("NAND");
        if(nor(a, b) == r)
            res.pb("NOR");
        if(xnor(a, b) == r)
            res.pb("XNOR");
        sort(all(res));
        cout << "Case " << kase++ << ":";
        for(int i = 0; i < SZ(res); i++)
        {
            if(i)
                cout << ",";
            cout << " " << res[i];
        }
        cout << "\n";
    }
    return 0;
}


#include <bits/stdc++.h>

#define in freopen("A-small-attempt1.in", "r", stdin);
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

LL n;

LL call(LL n)
{
    if(n < 21)
        return n;
    LL ret = 0;
    string s = tostring(n);
    if(s[SZ(s)-1] == '0')
        return call(n-9)+9;
    string tem = s;
    reverse(all(tem));
    if(s[0] > '1' && n%10 != 1)
    {
        tem[0] = '1';
        LL diff = (s[SZ(s)-1] - '1');
        return call(extract(tem, 1LL)) + diff+1;
    }
    LL a = extract(s, 1LL);
    LL b = extract(tem, 1LL);
    if(SZ(tostring(b)) == SZ(tostring(a)) && b < a)
        return call(extract(tem, 1LL)) + 1LL;
    int i = 0;
    LL num = 1;
    for(i = 0; i < SZ(s)-1; i++)
        num*=9;
    return call(num) + n - num;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, kase = 1;
    cin >> test;
    while(test--)
    {
        cin >> n;
        cout << "Case #" << kase++ << ": " << call(n) << "\n";
    }
    return 0;
}


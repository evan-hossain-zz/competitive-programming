#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

string remExtra(string s)
{
    int dpoint = -1, i;
    for(i = 0; i < SZ(s); i++)
    {
        if(s[i] == '.')
        {
            dpoint = i;
            break;
        }
    }
    if(dpoint == -1)
        return s;
    string tem = s.substr(dpoint+1);
    while(!tem.empty() && tem[SZ(tem)-1] == '0')
        tem.resize(SZ(tem)-1);
    if(!tem.empty())
        return s = s.substr(0, dpoint) + "." + tem;
    return s = s.substr(0, dpoint);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    string s, res;
    cin >> s;
    reverse(all(s));
    while(SZ(s) > 1 && s[SZ(s)-1] == '0')
        s.resize(SZ(s)-1);
    reverse(all(s));
    if(s[0] == '.')
    {
        int cnt = 1, i;
        for(i = 1; i < SZ(s) && s[i] == '0'; i++, cnt++);
//        if(i+1 < SZ(s) && s[i+1] != '0')
            cout << remExtra(tostring(s[i]) + "." + s.substr(i+1)) << "E-" << tostring(cnt);
//        else
//            cout << s[i] << "E-" << tostring(cnt);
        return 0;
    }
    if(s[1] == '.' || SZ(s) == 1)
    {
        cout << remExtra(s);
        return 0;
    }
    int cnt = 0, i = 1, found = 0;
    string tem = tostring(s[0]) + ".";
    for(i = 1; i < SZ(s); i++)
    {
        if(s[i] == '.')
        {
            found = 1;
            continue;
        }
        tem+=s[i];
        if(!found)
            cnt++;
    }
    cout << remExtra(tem) << "E" << cnt;
    return 0;
}

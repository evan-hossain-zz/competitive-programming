#include <bits/stdc++.h>

#define in freopen("B-small-attempt0.in", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
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

bool eq(string &a, string &b)
{
    for(int i = 0; i < SZ(a); i++)
    {
        if(a[i] != '?' && b[i] != '?' && a[i] != b[i])
            return false;
    }
    for(int i = 0; i < SZ(a); i++)
    {
        if(a[i] == '?' && b[i] == '?')
            a[i] = b[i] = '0';
        else if(a[i] == '?')
            a[i] = b[i];
        else if(b[i] == '?')
            b[i] = a[i];
    }
    return true;
}

string s;
int dp[20][5];

/// max num smaller than s
int callBig(int indx, int chhoto, string &given)
{
    if(indx == SZ(s))
        return chhoto;
    int &ret = dp[indx][chhoto];
    if(ret != -1)
        return ret;
    if(given[indx] != '?')
    {
        if(chhoto || (s[indx] > given[indx]))
            return ret = callBig(indx+1, chhoto || (s[indx] > given[indx]), given);
        else
            return ret = 0;
    }
    if(chhoto)
        return ret = callBig(indx+1, chhoto, given);
    for(char ch = '9'; ch >= '0'; ch--)
    {
        if(ch <= s[indx])
            ret = max(ret, callBig(indx+1, ch < s[indx], given));
    }
    return ret;
}

string getBig(int indx, int chhoto, string &given)
{
    if(indx == SZ(s))
        return "";
    if(given[indx] != '?')
        return given[indx] + getBig(indx+1, chhoto || (s[indx] > given[indx]), given);
    if(chhoto)
        return "9" + getBig(indx+1, chhoto, given);
    for(char ch = '9'; ch >= '0'; ch--)
    {
        if(ch <= s[indx] && callBig(indx+1, chhoto || (ch < s[indx]), given))
            return ch + getBig(indx+1, (ch < s[indx]), given);
    }
    return "";
}

/// smallest num greater than s
int callSmall(int indx, int boro, string &given)
{
    if(indx == SZ(s))
        return boro;
    int &ret = dp[indx][boro];
    if(ret != -1)
        return ret;
    if(given[indx] != '?')
    {
        if(boro || (s[indx] < given[indx]))
            return ret = callSmall(indx+1, boro || (s[indx] < given[indx]), given);
        return ret = 0;
    }
    if(boro)
        return ret = callSmall(indx+1, boro, given);
    for(char ch = '0'; ch <= '9'; ch++)
    {
        if(ch >= s[indx])
            ret = max(ret, callSmall(indx+1, (ch > s[indx]), given));
    }
    return ret;
}

string getSmall(int indx, int boro, string &given)
{
    if(indx == SZ(s))
        return "";
    if(given[indx] != '?')
        return given[indx] + getSmall(indx+1, boro || (s[indx] < given[indx]), given);
    if(boro)
        return "0" + getSmall(indx+1, boro, given);
    for(char ch = '0'; ch <= '9'; ch++)
    {
        if(ch >= s[indx] && callSmall(indx+1, (ch > s[indx]), given))
        {
            return ch + getSmall(indx+1, (ch > s[indx]), given);
        }
    }
    return "";
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    string aa, bb, resa, resb;
    LL test, kase = 1, i, j;
    cin >> test;
    while(test--)
    {
        cin >> aa >> bb;
        if(eq(aa, bb))
        {
            cout << "Case #" << kase++ << ": " << aa << ' ' << bb << "\n";
            cerr << "Case #" << kase-1 << ": " << aa << ' ' << bb << "\n";
            continue;
        }
        s = aa;
        for(auto &x: s)
        {
            if(x == '?')
                x = '0';
        }
        set <string> alla, allb;
        clr(dp, -1);
        callSmall(0, 0, bb);
        allb.insert(getSmall(0,0,bb));
        cerr << "b1 = " << getSmall(0, 0, bb) << "\n";
        clr(dp, -1);
        callBig(0, 0, bb);
        allb.insert(getBig(0,0,bb));
        cerr << "b2 = " << getBig(0, 0, bb) << "\n";

        s = bb;
        for(auto &x: s)
        {
            if(x == '?')
                x = '0';
        }
        clr(dp, -1);
        callSmall(0, 0, aa);
        alla.insert(getSmall(0,0,aa));
        cerr << "a1 = " << getSmall(0, 0, aa) << "\n";
        clr(dp, -1);
        callBig(0, 0, aa);
        alla.insert(getBig(0,0,aa));
        cerr << "a2 = " << getBig(0, 0, aa) << "\n";
        LL diff = 2e18, a, b;
        for(auto x: alla)
        {
            for(auto y: allb)
            {
                if(SZ(x) != SZ(y)) continue;
                LL vala = extract(x, 1LL);
                LL valb = extract(y, 1LL);
//                cout << vala << ' ' << valb << endl;
                if(abs(vala-valb) < diff)
                {
                    diff = abs(vala-valb);
                    a = vala;
                    b = valb;
                }
                else if(abs(vala-valb) == diff && vala < a)
                {
                    a = vala;
                    b = valb;
                }
                else if(abs(vala-valb) == diff && vala == a && valb < b)
                {
                    b = valb;
                }
            }
        }
        string resa = tostring(a), resb = tostring(b);
        while(SZ(resa) < SZ(aa))
            resa = "0" + resa;
        while(SZ(resb) < SZ(aa))
            resb = "0" + resb;

        cout << "Case #" << kase++ << ": " << resa << ' ' << resb << "\n";
        cerr << "Case #" << kase-1 << ": " << resa << ' ' << resb << "\n";
    }
    return 0;
}

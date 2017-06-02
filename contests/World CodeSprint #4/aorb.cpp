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

int get(char ch)
{
    if(isdigit(ch))
        return ch-'0';
    if(ch == 'A')
        return 10;
    if(ch == 'B')
        return 11;
    if(ch == 'C')
        return 12;
    if(ch == 'D')
        return 13;
    if(ch == 'E')
        return 14;
    return 15;
}

char get(int n)
{
    if(n < 10)
        return n+'0';
    if(n == 10)
        return 'A';
    if(n == 11)
        return 'B';
    if(n == 12)
        return 'C';
    if(n == 13)
        return 'D';
    if(n == 14)
        return 'E';
    return 'F';
}

int change(char &a, char &b, char c)
{
    int aint = get(a), ret = 0, bint = get(b), cint = get(c);
    for(int i = 0; i < 4; i++)
    {
        int abit = aint & (1<<i);
        int bbit = bint & (1<<i);
        int cbit = cint & (1<<i);
        if((abit | bbit) != cbit)
        {
            if(cbit == 0)
            {
                ret += (abit > 0);
                ret += (bbit > 0);
                aint &= ~(1<<i);
                bint &= ~(1<<i);
            }
            else
            {
                bint |= 1<<i;
                ret++;
            }
        }
    }
    a = get(aint);
    b = get(bint);
    return ret;
}

void cut_leading_zero(string &a)
{
    reverse(all(a));
    while(SZ(a) > 1 && a[SZ(a)-1] == '0')
        a.resize(SZ(a)-1);
    reverse(all(a));
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, i, k;
    string a, b, c;
    cin >> test;
    while(test--)
    {
        cin >> k >> a >> b >> c;
//        cout << k << ' ' << a << ' ' << b << ' ' << c << ' ';
        reverse(all(a));
        reverse(all(b));
        reverse(all(c));
        int mxlen = max(SZ(a), max(SZ(b), SZ(c)));
        while(SZ(a) < mxlen)
            a += "0";
        while(SZ(b) < mxlen)
            b += "0";
        while(SZ(c) < mxlen)
            c += "0";
        reverse(all(a));
        reverse(all(b));
        reverse(all(c));
        for(i = 0; i < mxlen; i++)
            k -= change(a[i], b[i], c[i]);
//        cout << k << ' ' << a << "\n" << b << "\n";
        if(k < 0)
        {
            cout << -1 << "\n";
            continue;
        }
        for(i = 0; i < mxlen && k>0; i++)
        {
            int j, aint = get(a[i]), bint = get(b[i]), cint = get(c[i]);
            assert((aint|bint) == cint);
            for(j = 3; j >= 0; j--)
            {
                int abit = aint & (1<<j);
                int bbit = bint & (1<<j);
                int cbit = cint & (1<<j);
                if(abit != 0 && bbit != 0 && k>0)
                {
                    k--;
                    aint &= ~(1<<j);
                }
                else if(abit != 0 && bbit == 0 && k >= 2)
                {
                    k -= 2;
                    aint &= ~(1<<j);
                    bint |= 1<<j;
                }
            }
            a[i] = get(aint);
            b[i] = get(bint);
            assert((aint|bint) == cint);
        }
        cut_leading_zero(a);
        cut_leading_zero(b);
        cout << a << "\n" << b << "\n";
    }
    return 0;
}

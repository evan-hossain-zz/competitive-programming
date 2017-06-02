#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output2.txt", "w", stdout);
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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    LL test, z, l, r, b, n, m, res, mn, baki, tot, takeL, takeR, takeB, takeZ;
    cin >> test;
    while(test--)
    {
        cin >> n >> m >> z >> l >> r >> b;
        cout << n << ' ' << m << ' ' << z << ' ' << l << ' ' << r << ' ' << b << ' ';
        if(m==1)
        {
            cout << min(n*m, z+l+r+b) << "\n";
            continue;
        }
        baki = tot = n*m;
        res = 0;
        if(baki <= l+r+z)
        {
            cout << baki << "\n";
            continue;
        }
        takeB = m/2+m%2;
        takeZ = m/2;
        mn = min(n, min(b/takeB, z/takeZ));
        n -= mn;
        res += mn*m;
        baki -= mn*m;
        b -= mn*(m/2+m%2), z -= mn*(m/2);
        if(baki <= l+r+z)
        {
            res += baki;
            cout << res << "\n";
            continue;
        }
        takeL = m-1;
        takeB = 1;
        mn = min(n, min(l/takeL, b/takeB));
        n -= mn;
        l -= takeL * mn;
        b -= takeB * mn;
        res += mn*m;
        baki -= mn*m;
        if(baki <= l+r+z)
        {
            res += baki;
            cout << res << "\n";
            continue;
        }
        takeR = m-1;
        takeB = 1;
        mn = min(n, min(r/takeR, b/takeB));
        n -= mn;
        r -= takeR * mn;
        b -= takeB * mn;
        res += mn*m;
        baki -= mn*m;
        if(baki <= l+r+z)
        {
            res += baki;
            cout << res << "\n";
            continue;
        }
        if(b==0)
        {
            res += l+r+z;
            cout << min(tot, res) << "\n";
            continue;
        }
        mn = min(z, b);
        res += 2*mn;
        z -= mn, b -= mn;
        if(b==0)
        {
            res += l+r+z;
            cout << min(tot, res) << "\n";
            continue;
        }
        l += r;
        mn = min(m-(res%m), l);
        res += mn;
        l -= mn;
        if(res%m)
        {
            mn = m-(res%m);
            res += min(mn/2+mn%2, b);
            cout << min(tot, res) << "\n";
            continue;
        }
        mn = min(n, l/m);
        res += mn*m;
        n -= mn;
        l -= n*mn;
        if(m%2)
        {
            mn = min(b/ (m/2+1), n);
            n -= mn;
            res += mn*(m/2+1);
            b -= mn * (m/2+1);
        }
        else
        {
            mn = min(n, min(b / (m/2), l));
            n -= mn;
            res += mn*(m/2+1);
            b -= mn * (m/2);
            l -= mn;
        }
        if(n==0)
        {
            cout << min(tot, res) << "\n";
            continue;
        }
        res += l;
        res += min((m-(res%m))/2, b);
        cout << res << "\n";
    }
    return 0;
}

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

string s;

int test, i, k, mzero, mone, rzero, rone, len;
int mpl, mpr, rpl, rpr;

void update()
{
    if(rpr == SZ(s)-1)
    {
        rpr++;
        return;
    }
    mzero -= s[mpl] == '0';
    mone -= s[mpl] == '1';
    rzero -= s[rpl] == '0';
    rone -= s[rpl] == '1';

    mpl++, rpl++;
    mpr++, rpr++;

    mzero += s[mpr] == '0';
    mone += s[mpr] == '1';

    rzero += s[rpr] == '0';
    rone += s[rpr] == '1';
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    cin >> test;
    while(test--)
    {
        int res = 0;
        cin >> s >> k >> s;
        len = SZ(s);
        if(k == 1)
        {
            int a = 0, b = 0;
            string tema, temb;
            for(i = 0; i < SZ(s); i++)
            {
                if(i % 2 == 0)
                    a += s[i] == '1', tema += '0';
                else
                    a += s[i] == '0', tema += '1';
            }
            for(i = 0; i < SZ(s); i++)
            {
                if(i % 2 == 1)
                    b += s[i] == '1', temb += '0';
                else
                    b += s[i] == '0', temb += '1';
            }
            res = min(a, b);
            if(res == a)
                cout << res << "\n" << tema << "\n";
            else
                cout << res << "\n" << temb << "\n";
            continue;
        }
        string filler;
        for(i = 0; i < 3*max(k, SZ(s)); i++)
            filler += "#";
        s = filler + s + filler;
        mzero = mone = rzero = rone = 0;
        k++;
        mpl = k-1, mpr = 2*k-2, rpl = mpr+1, rpr = 3*k-3;

        while(rpr < SZ(s))
        {
            if(mzero != k && mone != k)
            {
                update();
                continue;
            }
            if(max(rone, rzero) != k-1)
            {
                if(mone == k)
                    s[mpr] = '0', mzero++, mone--;
                else
                    s[mpr] = '1', mone++, mzero--;
                res++;
                update();
                continue;
            }
            if(mone == k && rzero == k-1)///10
            {
                s[mpr-1] = '0';
                mone--, mzero++;
                res++;
                update();
                continue;
            }
            if(mzero == k && rone == k-1)///01
            {
                s[mpr-1] = '1';
                mone++, mzero--;
                res++;
                update();
                continue;
            }
            if(mzero == k && rzero == k-1)///00
            {
                s[mpr] = '1';
                mone++, mzero--;
                update();
                res++;
                continue;
            }
            if(mone == k && rone == k-1)///11
            {
                s[mpr] = '0';
                mone--, mzero++;
                res++;
                update();
                continue;
            }
        }
        cout << res << "\n" << s.substr(SZ(filler), len) << "\n";
    }
    return 0;
}


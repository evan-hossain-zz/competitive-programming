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

int one[MAX], op;
string s;

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, k;
    cin >> s >> k >> op;
    cin >> s;
    for(i = SZ(s)-1; i >=0; i--)
    {
        if(i+k < SZ(s))
        {
            if(s[i+k] == '1')
                one[i] = i+k;
            else
                one[i] = one[i+k];
        }
        else
            one[i] = SZ(s);
    }
//    for(i = 0; i < SZ(s); i++)
//        cout << i << ' ' << one[i] << endl;
    for(i = 0; i < SZ(s); i++)
    {
        if(s[i] == '0')
        {
            if(one[i] == SZ(s))
                continue;
            int need = (one[i]-i)/k;
            if(need <= op)
            {
                op -= need;
                s[i] = '1';
                s[one[i]] = '0';
                int a = i+k, b = one[i];
                if(one[i]+k < SZ(s))
                    one[one[i]] = one[one[i]+k];
                else
                    one[one[i]] = SZ(s);
                while(a < b)
                    one[a] = one[b], a += k;
            }
        }
    }
    cout << s;
    return 0;
}

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

double get(double t, double T)
{
    double terms = t/0.00001;
    double sum = terms*(.00001+t)/2;
    return 1-(sum/T)*terms;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    cout << setprecision(3) << fixed;
    int test;
    double T1, T2, t1, t2, cmiss, hit, a, b;
    cin >> test;
    while(test--)
    {
        cin >> T1 >> T2 >> t1 >> t2;
        if(T1 > T2)
        {
            a = (1-((T1-T2)/T1)) * get(t1, T2);
        }
        else
            a = get(t1, min(T1+t1, T2));
        if(T2 > T1)
        {
            b = (1-((T2-T1)/T2)) * get(t2, T1);
        }
        else
            b = get(t2, min(T2+t2, T1));
        a = min(1., a);
        a = max(0., a);
        b = min(1., b);
        b = max(0., b);
        cout << a << ' ' << b << endl;
        cout << (a+b)/2 << "\n";
    }
    return 0;
}

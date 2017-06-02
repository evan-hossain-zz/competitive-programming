#include <bits/stdc++.h>

#define in freopen("C-small-attempt0.in", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
#define LL unsigned long long
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

bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=bigmod(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=bigmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

LL getDiv(LL n)
{
    LL i;
    for(i = 3; i * i <= n; i++)
    {
        if(n % i == 0)
            return i;
    }
    return 0;
}

LL n;

LL toBase(LL cur, LL base)
{
    LL ret = 0, i, p = 1;
    for(i = 0; i < n; i++)
    {
        if(cur & (1LL<<i))
            ret += p;
        p *= base;
    }
    return ret;
}

void print(LL cur)
{
    LL i;
    for(i = n-1; i >= 0; i--)
        cout << ((cur & (1LL<<i)) != 0);
}

int main()
{
    #ifdef Evan
//        in;
        out;
    #endif
    LL test, j, i;
    cin >> test;
    while(test--)
    {
        cin >> n >> j;
        LL base = 1<<(n-1)|1, cur, div, val;
        vector <LL> res(10), got;
        cout << "Case #1:\n";
        for(i = 0; j && i < (1LL << (n-2)); i++)
        {
            res.clear();
            cur = base | (i << 1) | 1;
            for(LL b = 2; b <= 10; b++)
            {
                val = toBase(cur, b);
                if(Miller(cur, 20))
                    continue;
                div = getDiv(val);
                if(!div)
                    break;
                res.pb(div);
            }
            if(SZ(res) < 9)
                continue;
            print(cur);
            for(auto x: res)
                cout << ' ' << x;
            cout << "\n";
            j--;
            cerr << j << endl;
        }
    }
    return 0;
}

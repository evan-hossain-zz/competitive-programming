#include <bits/stdc++.h>

#define in freopen("nice.in", "r", stdin);
#define out freopen("nice.out", "w", stdout);
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

struct matrix
{
    LL x[1<<5][1<<5];
};
int mod;

string cut_leading_zero(string a)
{
    string s;
    int i;
    if(a[0]!='0')   return a;
    for(i = 0; i < SZ(a)-1; i++)  if(a[i]!='0')   break;
    for(;i < SZ(a); i++)  s+=a[i];
    return s;
}
string substract(string a,string b)
{
    int borrow=0,i,sub;
    string ans;
    if(SZ(b)<SZ(a)) b=string(SZ(a)-SZ(b),'0')+b;
    for(i = SZ(a)-1; i >= 0; i--)
    {
        sub=a[i]-b[i]-borrow;
        if(sub<0)
        {
            sub+=10;
            borrow=1;
        }
        else borrow=0;
        ans+=sub+'0';
    }
    reverse(all(ans));
    ans=cut_leading_zero(ans);
    return ans;
}
string divide(string a,int k)
{
    int i,sum=0;
    string ans="0";

    for(i = 0; i < SZ(a); i++)
    {
        sum=(sum*10+(a[i]-'0'));
        ans+=(sum/k)+'0';
        sum=sum%k;
    }
    ans=cut_leading_zero(ans);
    return ans;
}

matrix base, zero;

matrix matmult(matrix &a, matrix &b, int n)//m*n and n*r matrix  //1 based
{
    matrix ret;
    int i,j,k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            ret.x[i][j]=0;
            for(k = 0; k < n; k++)
                ret.x[i][j] = (ret.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
            ret.x[i][j]%=mod;
        }
    return ret;
}

matrix mat_expo(matrix b, string p, int n) //have to pass dimension - n
{
    matrix xx = zero;
    int i;
    for(i = 0; i < n; i++)  xx.x[i][i] = 1;
    matrix power = b;
    while(p != "0")
    {
        if((p[SZ(p)-1]-'0')%2) xx = matmult(xx, power, n);
        power = matmult(power, power, n);
        p = divide(p, 2);
    }
    return xx;
}

int main()
{
//    #ifdef Evan
        in;
        out;
//    #endif
    int m, i, j, k;
    string n;
    cin >> n >> m >> mod;
    for(i = 0; i < (1<<m); i++)
    {
        for(j = 0; j < (1<<m); j++)
        {
            for(k = 1; k < m; k++)
            {
                if((((i & (1<<k)) && (i & (1<<(k-1)))) && ((j & (1<<k)) && (j & (1<<(k-1))))) ||
                (!((i & (1<<k)) || (i & (1<<(k-1)))) && !((j & (1<<k)) || (j & (1<<(k-1))))))
                    break;
            }
            base.x[i][j] = k == m;
        }
    }
    base = mat_expo(base, substract(n, "1"), 1<<m);
    int res = 0;
    for(i = 0; i < (1<<m); i++)
        for(j = 0; j < (1<<m); j++)
            res += base.x[i][j];
    cout << res%mod;
    return 0;
}

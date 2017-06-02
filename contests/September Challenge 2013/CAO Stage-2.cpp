
#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define F(i, n) for(i = 0; i < n; i++)

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str;}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define SZ 510
/*************************************************HABIJABI ENDS HERE******************************************************/

bool isprime(int n)
{
    if(n <= 1)
        return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}

int L[SZ][SZ], R[SZ][SZ], U[SZ][SZ], D[SZ][SZ], primes[SZ];

int main()
{
    _
    char arr[SZ][SZ];
    int n, m, i, j, k, tem, test, l;
    for(i = 2; i < SZ; i++)
    {
        if(isprime(i))
            primes[i] = primes[i - 1] + 1;
        else
            primes[i] = primes[i - 1];
    }
    cin >> test;
    while(test--)
    {
        LL cnt = 0;
        clr(L, 0), clr(R, 0), clr(U, 0), clr(D, 0);
        cin >> n >> m;
        F(i, n)
            F(j, m)
            {
                cin >> arr[i][j];
                if(arr[i][j] == '^')
                    L[i][j] = R[i][j] = U[i][j] = D[i][j] = 1;
            }
        F(i, n)
            for(j = 1; j < m; j++)
                if(L[i][j])
                    L[i][j] += L[i][j - 1];
        F(i, n)
            for(j = m - 2; j >= 0; j--)
                if(R[i][j])
                    R[i][j] += R[i][j + 1];
        for(i = 1; i < n; i++)
            F(j, m)
                if(U[i][j])
                    U[i][j] += U[i - 1][j];
        for(i = n - 2; i >= 0; i--)
            F(j, m)
                if(D[i][j])
                    D[i][j] += D[i + 1][j];
        F(i, n)
        {
            F(j, m)
            {
                if(arr[i][j] == '^')
                {
                    k = L[i][j] - 1;
                    k = min(R[i][j] - 1, k);
                    k = min(U[i][j] - 1, k);
                    k = min(D[i][j] - 1, k);
                    cnt += primes[k];
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

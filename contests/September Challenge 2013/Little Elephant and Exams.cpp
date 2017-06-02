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

#define SZ 55
/*************************************************HABIJABI ENDS HERE******************************************************/

struct info
{
    int a, b, probA, probB;
};
info arr[SZ];
double A, B, total;
int n;

bool taken[SZ];

void func(int indx, double prob)
{
    if(prob == 0)
        return;
    if(indx == n)
    {
        total += prob;
        return;
    }
    if(taken[arr[indx].a] == false)
    {
        taken[arr[indx].a] = true;
        func(indx + 1, prob * (arr[indx].probA / 100.0));
        taken[arr[indx].a] = false;
    }
    if(taken[arr[indx].b] == false)
    {
        taken[arr[indx].b] = true;
        func(indx + 1, prob * (arr[indx].probB / 100.0));
        taken[arr[indx].b] = false;
    }
}

int main()
{
    _
    int i, j, test;
    cin >> test;
    while(test--)
    {
        cin >> n;
        clr(taken, 0);
        total = 0;
        F(i, n)
        {
            cin >> arr[i].probA >> arr[i].a >> arr[i].b;
            arr[i].probB = 100 - arr[i].probA;
        }
        func(0, 1);
        printf("%.8lf\n", total);
    }
    return 0;
}


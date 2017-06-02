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

#define SZ 1000010
/*************************************************HABIJABI ENDS HERE******************************************************/

int A, B, C;
int inda = 1, indb = 2, indc = 3;

void print(int ab, int bc, int ca)
{
    int arr[3] = {ab, bc, ca};
    sort(arr, arr + 3);
    /*if(A < B)
    {
        if(B < C)//ABC
            cout << arr[0] << ' ' << arr[2] << ' ' << arr[1] << endl;
        else if(C > A)//ACB
            cout << arr[0] << ' ' << arr[2] << ' ' << arr[1] << endl;
    }
    else if(B < A)
    {
        if(A < C)//BAC
            cout << arr[1] << ' ' << arr[0] << ' ' << arr[2] << endl;
        else if(B < C)//BCA
            cout << arr[1] << ' ' << arr[2] << ' ' << arr[0] << endl;
    }
    else if(C < A)
    {
        if(A < B)//CAB
            cout << arr[2] << ' ' << arr[0] << ' ' << arr[1] << endl;
        else if(C < B)//CBA
            cout << arr[2] << ' ' << arr[1] << ' ' << arr[0] << endl;
    }*/
    if(A == max(A, max(B, C)))
    {
        if(B > C)
            cout << arr[2] << " " << arr[0] << ' ' << arr[1] << endl;
        else
            cout << arr[1] << ' ' << arr[0] << ' ' << arr[2] << endl;
    }
    else if(B == max(A, max(B, C)))
    {
        if(A > C)
            cout << arr[2] << ' ' << arr[1] << ' ' << arr[0] << endl;
        else
            cout << arr[1] << ' ' << arr[2] << ' ' << arr[0] << endl;
    }
    else
    {
        if(A > B)
            cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
        else
            cout << arr[0] << ' ' << arr[2] << ' ' << arr[1] << endl;
    }
}


int main()
{
    _
    int a, b, c, ab, bc, ca, tem;
    cin >> A >> B >> C;
    a = A, b = B, c = C;
    ab = bc = ca = 0;
    if(b < a)
    {
        swap(a, b);
        swap(inda, indb);
    }
    if(b < c)
    {
        swap(b, c);
        swap(indb, indc);
    }
    ab = bc = 1;
    a--, b-= 2, c--;
    if(b < 0)
    {
        cout << "Impossible\n";
        return 0;
    }
    if(c > a)
    {
        tem = (b + c - a) / 2;
        if(tem * 2 != (b + c - a))
        {
        cout << "Impossible\n";
        return 0;
        }
        bc += tem;
        b -= tem, c -= tem;
        ab += b;
        a -= b;
        ca += c;
        a -= c;
        if(a == 0 && b >= 0 && c >= 0)
            print(ab, bc, ca);
        else
            cout << "Impossible\n";
    }
    else
    {
        tem = (b + a - c) / 2;
        if(tem * 2 != b + a - c)
        {
        cout << "Impossible\n";
        return 0;
        }
        ab += tem;
        b -= tem, a-= tem;
        ca += a;
        c -= a;
        bc += b;
        c -= b;
        if(c == 0 && a >= 0 && b >= 0)
            print(ca, bc, ab);
        else
            cout << "Impossible\n";
    }
    return 0;
}


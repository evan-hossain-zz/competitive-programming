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
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; char c;};    // for coordinates;

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

#define SZ 20
/*************************************************HABIJABI ENDS HERE******************************************************/

int triangle_area(point &a, point &b, point &c)
{
    return abs((c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x));
}
bool check(const point &O, const point &A, const point &B)
{
        return ((A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x)) >= 0;
}
point P;
bool comp_angle(const point &a, const point &b)
{
    if(check(P, a, b))
        return true;
    return false;
}
int main()
{
    _
    int n, i, j, k, l, A, B, C, tem, area, p;
    point arr[SZ];
    string ans;
    while(cin >> n && n)
    {
        ans.clear();
        area = 0;
        p = 0;
        F(i, n)
            cin >> arr[i].c >> arr[i].x >> arr[i].y;
        for(i = 1; i < n; i++)
        {
            if((arr[p].y > arr[i].y) || (arr[p].y == arr[i].y && arr[p].x > arr[i].x))
                p = i;
        }
        swap(arr[0], arr[p]);
        P = arr[0];
        sort(arr + 1, arr + n, comp_angle);
        for(i = 0; i < n; i++)
        {
            for(j = i + 1; j < n; j++)
            {
                for(k = j + 1; k < n; k++)
                {
                    for(l = 0; l < n; l++)
                    {
                        if(l == i || l == j || l == k) continue;
                        A = check(arr[i], arr[j], arr[l]);
                        B = check(arr[j], arr[k], arr[l]);
                        C = check(arr[k], arr[i], arr[l]);
//                        if(A == 0 && in_line(arr[l], arr[i], arr[j]))
//                            break;
//                        if(B == 0 && in_line(arr[l], arr[j], arr[k]))
//                            break;
//                        if(C == 0 && in_line(arr[l], arr[k], arr[i]))
//                            break;
                        if(A == B && B == C)
                            break;
                    }
                    if(l == n)
                    {
                        tem = triangle_area(arr[i], arr[j], arr[k]);
                        if(tem > area)
                        {
                            ans.clear();
                            ans += arr[i].c;
                            ans += arr[j].c;
                            ans += arr[k].c;
                            area = tem;
                        }
                    }
                }
            }
        }
        sort(all(ans));
        cout << ans << "\n";
    }
    return 0;
}


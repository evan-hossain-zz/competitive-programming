#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define VI vector <int>
#define all(v) v.begin(), v.end()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};
#define SZ 100010
using namespace std;

struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;}
//LL Pow(LL B,LL P){  LL R = 1; while(P > 0)  {if(P % 2 == 1) R = (R*B);P /= 2;B = (B*B); } return R;}
//LL bigmod(LL n,LL p){ if(p == 0) return 1; LL a = bigmod(n, p / 2) % mod; if(p % 2 == 1) return (a*a*n) % mod; return (a*a) % mod;}

struct info
{
    LL month, plan_no;
    double rate, cost;
};
int main()
{
    _
    LL test, add_ons, i, total_months, plan, total_minutes, last_month_minute, d, c;
    double months_this_plan, default_call_rate, tem, default_cost, current_cost;
    cin >> test;
    while(test--)
    {
        info arr[110];
        total_months = 1;
        plan = 0;
        cin >> default_call_rate >> last_month_minute >> add_ons;
        for(i = 0; i < add_ons; i++)
        {
            cin >> arr[i].month >> arr[i].rate >> arr[i].cost;
            arr[i].plan_no = i + 1;
            total_months = lcm(arr[i].month, total_months);
        }
        total_minutes = total_months * last_month_minute;
        default_cost = (double) total_minutes * default_call_rate;
//        cout << default_cost << endl;
        for(i = 0; i < add_ons; i++)
        {
            current_cost = ((double) total_minutes * arr[i].rate) + ((double) ((LL) total_months / arr[i].month) * arr[i].cost);
//            cout << current_cost << endl;
            if(default_cost - current_cost > 10e-3)
            {
                default_cost = current_cost;
                plan = arr[i].plan_no;
            }
        }
        cout << plan << endl;
    }
    return 0;
}

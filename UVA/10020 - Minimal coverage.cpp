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
template <class T> T GCD(T a, T b) {if(b == 0) return a; return GCD(b, a % b);}
template <class T> T LCM(T a, T b) {return (a * b) / GCD(a, b);}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;}
//LL Pow(LL B,LL P){  LL R = 1; while(P > 0)  {if(P % 2 == 1) R = (R*B);P /= 2;B = (B*B); } return R;}
//LL bigmod(LL n,LL p){ if(p == 0) return 1; LL a = bigmod(n, p / 2) % mod; if(p % 2 == 1) return (a*a*n) % mod; return (a*a) % mod;}

struct segment{
    int starting_point, ending_point, indx;
}arr[SZ];

bool col[SZ];

bool comp(const segment &a, const segment &b){
    if(a.ending_point != b.ending_point)
        return a.ending_point > b.ending_point;
    return a.starting_point > b.starting_point;
}

bool rescomp(const segment &a, const segment &b){
    return a.starting_point < b.starting_point;
}

int main()
{
    _
    int test, s, e, i, j, m, have_to_cover;
    cin >> test;
    while(test--){
        clr(col, 0);
        vector <segment> res;
        have_to_cover = 0;
        cin >> m;
        i = 0;
        while(cin >> s >> e && (s | e))
        {
            if(e < 0 || s > m)
                continue;
            arr[i].starting_point = s, arr[i].ending_point = e;
            arr[i].indx = i;
            i++;
        }
        int segments = i;
        sort(arr, arr + segments, comp);
        while(have_to_cover < m){
            for(i = 0; i < segments; i++){
                if(col[i]) continue;
                if(arr[i].starting_point <= have_to_cover){
                    res.pb(arr[i]);
                    col[i] = 1;
                    have_to_cover = arr[i].ending_point;
                    break;
                }
            }
            if(i == segments)
                break;
        }
        if(have_to_cover < m)
            cout << 0 << endl;
        else{
            sort(res.begin(), res.end(), rescomp);
            cout << res.size() << endl;
            for(i = 0; i < res.size(); i++)
                cout << res[i].starting_point << ' ' << res[i].ending_point << endl;
        }
        if(test)
            cout << endl;
    }
    return 0;
}

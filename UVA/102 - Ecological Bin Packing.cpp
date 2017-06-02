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

int main()
{
    int i, j;
    long long arr[3][3], res, moves;
    while(scanf("%lld", &arr[0][0]) == 1){
        cin >> arr[0][1] >> arr[0][2];
        for(i = 1; i < 3; i++)
                for(j = 0; j < 3; j++)
                    cin >> arr[i][j];
        LL totalblue = arr[0][0] + arr[1][0] + arr[2][0];
        LL totalgreen = arr[0][1] + arr[1][1] + arr[2][1];
        LL totalclear = arr[0][2] + arr[1][2] + arr[2][2];
        string s = "BCG", ret;
        res = infinity;
        do{
            moves = 0;
            for(i = 0; i < 3; i++){
                if(s[i] == 'B')
                    moves += totalblue - arr[i][0];
                else if(s[i] == 'G')
                    moves += totalgreen - arr[i][1];
                else
                    moves += totalclear - arr[i][2];
            }
            if(moves < res){
                ret = s;
                res = moves;
            }
        }while(next_permutation(s.begin(), s.end()));
        cout << ret + " " << res << endl;
    }
    return 0;
}


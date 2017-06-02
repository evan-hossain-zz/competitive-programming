#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 10010
#define VI vector <int>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};
///int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
template <class T> T GCD(T a, T b) {if(b == 0) return a; return GCD(b, a % b);}
template <class T> T LCM(T a, T b) {return (a * b) / GCD(a, b);}

using namespace std;
int N, arr[SZ], D;

bool recur(int indx, int res, int op)
{
//    cout << indx << ' ' << res << ' ' << D << endl;
    if(indx == N)
    {
//        cout << indx << endl;
//        cout << res << endl;
        if(res % D == 0)
            return true;
        return false;
    }
    if(op == 0)
        return recur(indx + 1, res + arr[indx], 0) || recur(indx + 1, res + arr[indx], 1);
    return recur(indx + 1, res - arr[indx], 0) || recur(indx + 1, res - arr[indx], 1);
}

int main()
{
    _
    int n, k, t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        D = k;
        N = n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
//        if(n == 1){
//            if(arr[0] % k == 0)
//                cout << "Divisible\n";
//            else
//                cout << "Not divisible\n";
//            continue;
//        }
        if(recur(0, 0, 0))
            cout << "Divisible\n";
        else
            cout << "Not divisible\n";
    }
    return 0;
}


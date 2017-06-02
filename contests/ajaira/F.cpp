#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
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

#define MAX 1000010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int A, B, M, arr[222], has[MAX];

int get(int i, int j, int k)
{
    int ret = 0, n = arr[i]+arr[j]+arr[k];
    if(n > B) return 0;
    int low, high;
    if(n >= A)
        low = 0;
    else
    {
        if(A-n >= MAX)
            return 0;
        low = A-n;
    }
    high = min(MAX-1, B-n);
    while(low > high);
    if(arr[i]>= low && arr[i] <= high) ret--;
    if(arr[j]>= low && arr[j] <= high) ret--;
    if(arr[k]>= low && arr[k] <= high) ret--;
    if(low == 0)
        return ret += has[high];
    return ret += has[high] - has[low-1];
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, kase = 1, i, j, k, l, m;
    cin >> test;
    while(test--)
    {
        clr(has, 0);
        cin >> M;
        LL res = 0;
        for(i = 0; i < M; i++)
            cin >> arr[i], has[arr[i]]=1;
        for(i = 1; i < MAX; i++)
            has[i] += has[i-1];
        cin >> A >> B;
        int tem;
        for(i = 0; i < M; i++)
        {
            tem = arr[i]*4;
            if(tem >= A && tem <= B)
                res++;
        }
        for(i = 0; i < M; i++)
            for(j = i+1; j < M; j++)
            {
                for(k = 1; k < 4; k++)
                {
                    tem = arr[i]*k;
                    tem += arr[j]*(4-k);
                    if(tem >= A && tem <= B)
                        res++;
                }
            }
        for(i = 0; i < M; i++)
            for(j = i+1; j < M; j++)
                for(k = j+1; k < M; k++)
                {
                    tem = 2*arr[i] + arr[j] + arr[k];
                    if(tem >= A && tem <= B)
                        res++;
                    tem = arr[i] + 2*arr[j] + arr[k];
                    if(tem >= A && tem <= B)
                        res++;
                    tem = arr[i] + arr[j] + 2*arr[k];
                    if(tem >= A && tem <= B)
                        res++;

                    res += get(i, j, k);
                }
        cout << "Case " << kase++ << ": " << res << "\n";
    }
    return 0;
}
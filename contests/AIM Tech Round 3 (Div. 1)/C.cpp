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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 1000010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL adj[MAX];

LL get(LL n)
{
    LL low = 1, high = 2e9, mid;
    while(low <= high)
    {
        mid = (low+high) / 2;
        if(mid*(mid-1)/2 < n)
            low = mid+1;
        else if(mid*(mid-1)/2 > n)
            high = mid-1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL arr[4];
    for(int i = 0; i < 4; i++)
        cin >> arr[i];
    LL zero = get(arr[0]), one = get(arr[3]);
    if(arr[1]+arr[2]+arr[3] == 0)
    {
        while(zero--)
            putchar('0');
        return 0;
    }
    if(arr[1]+arr[2]+arr[0] == 0)
    {
        while(one--)
            putchar('1');
        return 0;
    }
    if(zero == -1 || one == -1 || (arr[1] + arr[2]) != zero*one)
    {
        cout << "Impossible";
        return 0;
    }
    if(arr[1] < arr[2])
    {
        LL oz = zero*one, zo = 0;
        while(zero)
        {
            if((zo==arr[1] && oz == arr[2]))
                break;
            LL low = 1, high = one, mid, res;
            while(low <= high)
            {
                mid = (low+high) / 2;
                LL zogot = one - mid;
                if(zo+zogot <= arr[1] && oz-zogot >= arr[2])
                {
                    high = mid-1;
                    res = mid;
                }
                else
                    low = mid+1;
            }
            adj[res]++;
            zero--;
            zo += one-res;
            oz -= one-res;
        }
        if(!((zo==arr[1] && oz == arr[2])))
        {
            cout << "Impossible";
            return 0;
        }
        for(int i = 1; i <= one; i++)
        {
            putchar('1');
            while(adj[i]--)
                putchar('0');
        }
        while(zero--)
            putchar('0');
    }
    else
    {
        swap(zero, one);
        swap(arr[1], arr[2]);
        LL oz = zero*one, zo = 0;
        while(zero)
        {
            if((zo==arr[1] && oz == arr[2]))
                break;
            LL low = 1, high = one, mid, res;
            while(low <= high)
            {
                mid = (low+high) / 2;
                LL zogot = one - mid;
                if(zo+zogot <= arr[1] && oz-zogot >= arr[2])
                {
                    high = mid-1;
                    res = mid;
                }
                else
                    low = mid+1;
            }
            adj[res]++;
            zero--;
            zo += one-res;
            oz -= one-res;
        }
        if(!((zo==arr[1] && oz == arr[2])))
        {
            cout << "Impossible";
            return 0;
        }
        for(int i = 1; i <= one; i++)
        {
            putchar('0');
            while(adj[i]--)
                putchar('1');
        }
        while(zero--)
            putchar('1');
    }
    return 0;
}

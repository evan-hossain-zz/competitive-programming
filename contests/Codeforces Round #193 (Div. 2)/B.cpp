#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 200010
#define VI vector <int>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};
///int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

struct point
{
    int x, y;
};

template <class T> T sqr(T a)
{
    return a * a;
};
template <class T> double getdist(T a, T b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

using namespace std;

LL input[SZ], arr[SZ], mx;

int main()
{
    _
    int n, k, i, j, a, b;
    LL mx = 0;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> input[i];
    for(i = 1; i <= n; i++)
        arr[i] += arr[i - 1] + input[i];
    for(i = 1; i <= n; i++)
    {
        if(i + k - 1 <= n)
        {
            if(arr[i + k - 1] - arr[i - 1] > mx)
            {
                mx = arr[i + k - 1] - arr[i - 1];
                a = i;
            }
        }
    }
    for(i = a; i <= a + k - 1; i++)
        input[i] = 0;
    clr(arr, 0);
    for(i = 1; i <= n; i++)
        arr[i] += arr[i - 1] + input[i];
    mx = 0;
    for(i = 1; i <= n; i++)
    {
        if(i + k - 1 <= n && input[i] && input[i + k - 1])
        {
            if(arr[i + k - 1] - arr[i - 1] > mx)
            {
                mx = arr[i + k - 1] - arr[i - 1];
                b = i;
            }
        }
    }
    cout << min(a, b) << ' ' << max(a, b) << endl;
    return 0;
}


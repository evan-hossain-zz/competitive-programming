#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010
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
LL a[SZ], sp[SZ], sk[SZ], ind, indd, smx, ind1, ind2, res;
LL s[SZ], sum[SZ], f[SZ];

int main()
{
    _
    int i, k, n;
    cin >> n >> k;
    f[0] = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> f[i];
        f[i] += f[i - 1];
    }
    int a = k, b = k * 2, c = k;
    for(i = 2 * k; i <= n; i++)
    {
        if(f[i - k] - f[i - 2*k] > f[c] - f[c - k]) c = i - k;
        if(f[i] - f[i - k] + f[c] - f[c  - k] > f[b] - f[b - k] + f[a] - f[a - k])
        {
            b = i;
            a = c;
        }
    }
    a = a - k + 1;
    b = b - k + 1;
    cout << a << ' ' << b;
    return 0;
}


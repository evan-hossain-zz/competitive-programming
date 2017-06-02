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
LL ans;



int main()
{
    string s;
    int mx, i, j;
    cin >> s;
    if(s == "0")
    {
        cout << 0 << endl;
        return 0;
    }
    while(s.size() > 1)
    {
//        cout << s << endl;
        int mx = 0;
        for(int i = 0; i < s.size(); i++)
            mx = max(s[i] - '0', mx);
//    cout << mx << endl;
        int num = 0, mul = 1;
        for(int i = 0; i < s.size(); i++)
            num = (num * 10) + (s[i] - '0');
//    cout << num << endl;
        num -= mx;
//    cout << num << endl;
        string tem;
        do
        {
            tem += ((num % 10) + '0');
            num /= 10;
        }
        while(num);
        ans++;
        reverse(tem.begin(), tem.end());
        s = tem;
//    cout << tem << endl;
//    return;
    }
    cout << ans + 1 << endl;
    return 0;
}


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

struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}

using namespace std;

int main()
{
    _
    LL a, b, c, jog = 0, biog = 0, gun = 0, bhag = 0, cnt = 0;
    cin >> a >> b >> c;
    if(a + b == c)
    {
        cnt++;
        jog++;
    }
    if(a - b == c)
    {
        cnt++;
        biog++;
    }
    if(a * b == c)
    {
        cnt++;
        gun++;
    }
    if(b && a % b == 0)
    {
        if(a / b == c)
        {
            cnt++;
            bhag++;
        }
    }
    if(cnt != 1)
    {
        cout << "Invalid\n";
        return 0;
    }
    if(jog)
        cout << "+";
    else if(biog)
        cout << "-";
    else if(gun)
        cout << "*";
    else if(bhag)
        cout << "/";
    else
        cout << "Invalid";
    cout << endl;
    return 0;
}


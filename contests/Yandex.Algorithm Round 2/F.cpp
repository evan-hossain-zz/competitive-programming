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

vector <int> v;
int O, T, P, mx;

void recur(string cur, string need, int o, int t, int p, int cost)
{
    if(cost > 5)
        return;
    string tem;
    tem = cur;
    cout << cur << endl;
    if(cur == need)
    {
        if(cost < mx)
        {
            mx = cost;
            v.clear();
            v.pub(o), v.pub(t), v.pub(p);
        }
        return;
    }
    if(cur == "RGB")
        return;
    if(o < O)
    {
        tem = cur;
        swap(tem[0], tem[1]);
        recur(tem, need, o + 1, t, p, cost + 1);
    }
    if(t < T)
    {
        tem = cur;
        swap(tem[1], tem[2]);
        recur(tem, need, o, t + 1, p, cost + 1);
    }
    if(p < P)
    {
        tem = cur;
        swap(tem[0], tem[2]);
        recur(tem, need, o, t, p + 1, cost + 1);
    }
}

int main()
{
    _
    cin >> O >> T >> P;
    string s;
    cin >> s;
    recur("GRB", s, 1, 0, 0, 1);
    recur("RBG", s, 0, 1, 0, 1);
    recur("BRG", s, 0, 0, 1, 1);
    cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    return 0;
}


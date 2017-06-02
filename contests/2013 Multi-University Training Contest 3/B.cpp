#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include <iostream>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 2010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

struct info
{
    int tup[2], indx; //tup[0] = prev rank, tup[1] = new rank
}arr[MAX];

int sorted[18][MAX], step, common[MAX][MAX];
string text;

bool comp(const info &a, const info &b)
{
    return a.tup[0] != b.tup[0]? a.tup[0] < b.tup[0] : a.tup[1] < b.tup[1];
}

void build_suffix_array(void)
{
    int i, n = SZ(text), jump;
    for(i = 0; i < n; i++)
    {
        sorted[0][i] = text[i] - 'a'; //rank suffixes according to 1st char
//        clr(arr[i].tup, 0);
    }
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1)
    {
        for(i = 0; i <=n; i++)
        {
            arr[i].indx = i;
            arr[i].tup[0] = sorted[step - 1][i]; // what i was in prev step
            arr[i].tup[1] = i + jump < n? sorted[step - 1][i + jump] : -1;
        }
        sort(arr, arr + n, comp);
        sorted[step][arr[0].indx] = 0;
        for(i = 1; i < n; i++)
            sorted[step][arr[i].indx] = arr[i].tup[0] == arr[i - 1].tup[0] &&
            arr[i].tup[1] == arr[i - 1].tup[1] ? sorted[step][arr[i - 1].indx] : i;
    }
}

int LCP(int id1, int id2)
{
    int ret = 0, i, j;
    for(j = step - 1; j >= 0; j--)
        if(sorted[j][id1] == sorted[j][id2])
        {
            ret += (1 << j);
            id1 += (1 << j);
            id2 += (1 << j);
        }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, i, l, r, q, res, j;
    char str[MAX];
    string s;
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", str);
        text = str;
        build_suffix_array();
        for(i = 0; i < SZ(text); i++)
            for(j = 0; j < SZ(text); j++)
            {
//                if(j)
//                    common[i][j] = max(common[i][j-1], LCP(i, j));
//                else
                    common[i][j] = LCP(i, j);
            }
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d", &l, &r);
//            cout << text << ' ' << l << ' ' << r << ' ';
            l--, r--;
            int pre = -1;
            res = 0;
            for(i = 0; i < SZ(text); i++)
            {
                j = arr[i].indx;
                if(j < l || j > r)
                {
                    continue;
                }
                if(pre == -1)
                    res += r-j+1;
                else
                    res += max(r - j + 1 - common[pre][j], 0);
                cout << pre << ' ' << j << ' ' << common[pre][j] << ' ' << r << ' ' << res << endl;
                pre = j;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
/*
1
jicdeacdbjijijbd
1
1 12
*/


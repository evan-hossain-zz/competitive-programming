#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str;}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define SZ 210
/*************************************************HABIJABI ENDS HERE******************************************************/

point convex[SZ], O;

int check(const point &O, const point &A, const point &B)
{
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool comp_angle(const point &a, const point &b)
{
    if(check(O, a, b) > 0)
        return true;
    else if(check(O, a, b) == 0)
        return getdist(O, a) < getdist(O, b);
    return false;
}
int next_to_top(stack <int> &S)
{
    int p = S.top();
    S.pop();
    int ret = S.top();
    S.push(p);
    return ret;
}
bool in_same_line(point arr[], int n, int situation_of_citizens[], int cit, point citizens[], int mark)
{
    int i;
    for(i = 1; i < n; i++)
    {
        if(arr[0].y > arr[i].y)
            swap(arr[0], arr[i]);
        else if(arr[0].y == arr[i].y && arr[0].x > arr[i].x)
            swap(arr[0], arr[i]);
    }
    O = arr[0];
    sort(arr + 1, arr + n, comp_angle);
    for(i = 0; i < n - 2; i++)
    {
        if(check(arr[i], arr[i + 1], arr[i + 2]) != 0)
            break;
    }
    if(i != n - 2)
        return false;
    for(i = 0; i < cit; i++)
    {
        if(situation_of_citizens[i] != 0)
            continue;
        if(check(arr[0], arr[1], citizens[i]) == 0 && (citizens[i].x >= arr[0].x && citizens[i].y >= arr[0].y && citizens[i].x <= arr[n -1].x && citizens[i].y <= arr[n - 1].y))
            situation_of_citizens[i] = mark;
    }
    return true;
}
int make_hull(point arr[], int n)
{
    stack <int> S;
    int i, c = 0;
    for(i = 1; i < n; i++)
    {
        if(arr[0].y > arr[i].y)
            swap(arr[0], arr[i]);
        else if(arr[0].y == arr[i].y && arr[0].x > arr[i].x)
            swap(arr[0], arr[i]);
    }
    O = convex[0] = arr[0];
    for(i = 1; i < n; i++)
    {
        if(convex[c].x == arr[i].x && convex[c].y == arr[i].y)
            continue;
        convex[++c] = arr[i];
    }
    c++;
    if(c < 3)
        return 0;
    sort(convex + 1, convex + c, comp_angle);
    S.push(0), S.push(1), S.push(2);
    for(i = 3; i < c; i++)
    {
        while(check(convex[next_to_top(S)], convex[S.top()], convex[i]) < 0)
            S.pop();
        S.push(i);
    }
    c = S.size();
    for(i = S.size() - 1; i >= 0; i--)
    {
        arr[i] = convex[S.top()];
        S.pop();
    }
    return c;
}

int main()
{
    _
    point cops[SZ], robbers[SZ], citizens[SZ];
    int situation_of_citizens[SZ];
    int cop, rob, cit, i, n, a, b, I, kase = 1, j, flag, same_line;
    while(cin >> cop >> rob >> cit && (cop || rob || cit))
    {
        clr(situation_of_citizens, 0);
        flag = same_line = 0;
        for(i = 0; i < cop; i++)
            cin >> cops[i].x >> cops[i].y;
        for(i = 0; i < rob; i++)
            cin >> robbers[i].x >> robbers[i].y;
        for(i = 0; i < cit; i++)
            cin >> citizens[i].x >> citizens[i].y;
        n = 0;
        if(cop < 3)
            flag = true;
        if(!flag && in_same_line(cops, cop, situation_of_citizens, cit, citizens, 1) == false)
            n = make_hull(cops, cop);
        if(n > 2)
        {
            for(i = 0; i < cit; i++)
            {
                if(situation_of_citizens[i] != 0)
                    continue;
                for(I = 0; I < n; I++)
                {
                    a = I % n;
                    b = (I + 1) % n;
                    if(check(cops[a], cops[b], citizens[i]) < 0)
                        break;
                }
                if(I == n)
                    situation_of_citizens[i] = 1;
            }
        }
        flag = false;
        n = 0;
        if(rob < 3)
            flag = true;
        if(!flag && in_same_line(robbers, rob, situation_of_citizens, cit, citizens, -1) == 0)
            n = make_hull(robbers, rob);
        if(n > 2)
        {
            for(i = 0; i < cit; i++)
            {
                if(situation_of_citizens[i] != 0)
                    continue;
                for(I = 0; I < n; I++)
                {
                    a = I % n;
                    b = (I + 1) % n;
                    if(check(robbers[a], robbers[b], citizens[i]) < 0)
                        break;
                }
                if(I == n)
                    situation_of_citizens[i] = -1;
            }
        }
        printf("Data set %d:\n", kase++);
        for(i = 0; i < cit; i++)
        {
            printf("     ");
            if(situation_of_citizens[i] == 1)
                printf("Citizen at (%d,%d) is safe.\n", citizens[i].x, citizens[i].y);
            else if(situation_of_citizens[i] == -1)
                printf("Citizen at (%d,%d) is robbed.\n", citizens[i].x, citizens[i].y);
            else
                printf("Citizen at (%d,%d) is neither.\n", citizens[i].x, citizens[i].y);
        }
        printf("\n");
    }
    return 0;
}


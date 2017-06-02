#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 2000
/*************************************************HABIJABI ENDS HERE******************************************************/

struct customer
{
    string name, will;
    char product;
    int id, dam;
}arr[MAX];

pair <int, int> price[26], total[26];
int recieved[MAX], paid[MAX];
map <string, int> mpp;

void find_match(int n, int buy)
{
    int i, mx_suitable, indx = -1, mean;
    if(buy)
    {
        mx_suitable = infinity;
        for(i = 0; i < n; i++)
        {
            if(arr[i].product != arr[n].product || arr[i].id == arr[n].id || arr[i].will == "BUY" || arr[i].dam == -1 || arr[i].dam > arr[n].dam) continue;
            if(arr[i].dam < mx_suitable)
            {
                mx_suitable = arr[i].dam;
                indx = i;
            }
        }
        if(indx == -1) return;
        mean = (arr[indx].dam + arr[n].dam) / 2;
        price[arr[indx].product - 'A'].first = min(price[arr[indx].product - 'A'].first, mean);
        price[arr[indx].product - 'A'].second = max(price[arr[indx].product - 'A'].second, mean);
        recieved[arr[indx].id] += mean;
        paid[arr[n].id] += mean;
        total[arr[indx].product - 'A'].first += mean;
        total[arr[indx].product - 'A'].second++;
        arr[indx].dam = arr[n].dam = -1;
        return;
    }

    mx_suitable = -1;
    for(i = 0; i < n; i++)
    {
        if(arr[i].product != arr[n].product || arr[i].id == arr[n].id || arr[i].will == "SELL" || arr[i].dam == -1 || arr[i].dam < arr[n].dam) continue;
        if(arr[i].dam > mx_suitable)
        {
            mx_suitable = arr[i].dam;
            indx = i;
        }
    }
    if(indx == -1) return;
    mean = (arr[indx].dam + arr[n].dam) / 2;
    price[arr[indx].product - 'A'].first = min(price[arr[indx].product - 'A'].first, mean);
    price[arr[indx].product - 'A'].second = max(price[arr[indx].product - 'A'].second, mean);
    paid[arr[indx].id] += mean;
    recieved[arr[n].id] += mean;
    total[arr[indx].product - 'A'].first += mean;
    total[arr[indx].product - 'A'].second++;
    arr[indx].dam = arr[n].dam = -1;
}

string to_upper(string s)
{
    string ret;
    for(int i = 0; i < SZ(s); i++)
        ret += toupper(s[i]);
    return ret;
}

int main()
{
    CF
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, i, id;
    while(cin >> n && n)
    {
        mpp.clear();
        clr(price, -1);
        clr(recieved, 0);
        clr(paid, 0);
        clr(total, 0);
        id = 1;
        for(i = 0; i < n; i++)
        {
            cin >> arr[i].name >> arr[i].will >> arr[i].product >> arr[i].dam;
            if(mpp.find(arr[i].name) == mpp.end())
                mpp[arr[i].name] = id++;
            arr[i].id = mpp[arr[i].name];
            arr[i].will = to_upper(arr[i].will);
            if(price[arr[i].product - 'A'].first == -1)
                price[arr[i].product - 'A'] = make_pair(infinity, 0);
            find_match(i, arr[i].will == "BUY");
        }
        for(i = 0; i < 26; i++)
        {
            if(!total[i].second) continue;
            cout << (char) ('A' + i) << ' ' << price[i].first << ' ' << total[i].first / total[i].second << ' ' << price[i].second << "\n";
        }
        cout << "--\n";
        for(map <string, int> :: iterator it = mpp.begin(); it != mpp.end(); it++)
            cout << it->first << ' ' << paid[it->second] << ' ' << recieved[it->second] << "\n";
        cout << "----------\n";
    }
    return 0;
}




#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 300010


///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};
///int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}

using namespace std;

struct number
{
    int num, indx;
};
number arr[3 * SZ];

bool comp(const number &a, const number &b)
{
    if(a.num != b.num)
        return a.num < b.num;
    return a.indx < b.indx;
}

int main()
{
    map <int, int> mp;
    int n, i, j, low, high;
    bool col[SZ];
    LL input[SZ];
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> input[i];
        if(mp.find(input[i]) == mp.end())
            mp[input[i]] = 1;
        else
            mp[input[i]]++;
    }
    LL fmx = - infinity;
    int fl = 0, fh = 0;
    vector <int> ftaken;
    vector <int> taken;
    vector <int> canceled;
    for(i = 0; i < n; i++)
    {
        int tot = mp[input[i]] - 1;
        mp[input[i]]--;
        if(tot <= 0)
            continue;
        LL sum = input[i];
        low = i;
        int thigh = i;
        int fhigh = i;
        taken.clear();
        taken.pub(i);
        for(j = i + 1; j < n && tot > 0; j++)
        {
//            cout << sum << ' ';
            LL tem = sum + input[j];
//            cout << tem << endl;
            if(tem < sum)
            {
                if(input[j] == input[i] && tot - 1 == 0);
                else
                {
                    if(input[j] == input[i])
                        tot--;
                    continue;
                }
            }
            taken.pub(j);
            sum = tem;
            if(input[low] == input[j])
                thigh = j, tot--;
        }
        if(sum > fmx)
        {
            fmx = sum;
            ftaken = taken;
        }
    }
    for(i = 0; i < ftaken.size(); i++)
        col[ftaken[i]] = 1;
    cout << fmx << ' ' << n - ftaken.size() << endl;
    for(i = 0; i < n; i++)
        if(col[i] == 0) cout << i + 1 << ' ';
    return 0;
}


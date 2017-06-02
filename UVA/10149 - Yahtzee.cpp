#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define VI vector <int>
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

#define SZ 1000010
using namespace std;

struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;}
//LL Pow(LL B,LL P){  LL R = 1; while(P > 0)  {if(P % 2 == 1) R = (R*B);P /= 2;B = (B*B); } return R;}
//LL bigmod(LL n,LL p){ if(p == 0) return 1; LL a = bigmod(n, p / 2) % mod; if(p % 2 == 1) return (a*a*n) % mod; return (a*a) % mod;}

/*
    ones - sum of all ones thrown
    twos - sum of all twos thrown
    threes - sum of all threes thrown
    fours - sum of all fours thrown
    fives - sum of all fives thrown
    sixes - sum of all sixes thrown

    chance - sum of all dice

    three of a kind - sum of all dice, provided at least three have same value
    four of a kind - sum of all dice, provided at least four have same value
    five of a kind - 50 points, provided all five dice have same value
    short straight - 25 points, provided four of the dice form a sequence (that is, 1,2,3,4 or 2,3,4,5 or 3,4,5,6)
    long straight - 35 points, provided all dice form a sequence (1,2,3,4,5 or 2,3,4,5,6)
    full house - 40 points, provided three of the dice are equal and the other two dice are also equal. (for example, 2,2,5,5,5)*/

LL dp[1LL << 13][1LL << 13], special[7], arr[15][15], ans;
vector <LL> best;

bool check(LL n, LL pos)
{
    return n & (1LL << pos);
}
LL set_bit(LL n, LL pos)
{
    return n = n | (1LL << pos);
}

LL call(LL round_no, LL mask)
{
//    cout << ans++ << ' ';
    LL &ret = dp[round_no][mask], res, i, j;
    LL tem_array[5], cnt, tem;
    if(mask == (1LL << 13) - 1LL) return 0;
    if(round_no == (1LL << 13) - 1LL) return 0;
    if(ret != -1) return ret;
    cout << round_no << ' ' << mask << ' ';
    for(LL r = 0; r < 13; r++)
    {
        if(check(round_no, r) == 0)
        {
            for(i = 0; i < 13; i++)
            {
                res = 0;
                if(check(mask, i) == 0)
                {
                    clr(special, 0);
                    for(j = 0; j < 7; j++)
                        special[arr[round_no][j]]++;
                    switch(i)
                    {
                    case 0:
                        for(j = 0; j < 5; j++)
                            res = (arr[round_no][j] == 1);
                        break;
                    case 1:
                        for(j = 0; j < 5; j++)
                            res = arr[round_no][j] == 2 ? 2 : 0;
                        break;
                    case 2:
                        for(j = 0; j < 5; j++)
                            res = arr[round_no][j] == 3 ? 3 : 0;
                        break;
                    case 3:
                        for(j = 0; j < 5; j++)
                            res = arr[round_no][j] == 4 ? 4 : 0;
                        break;
                    case 4:
                        for(j = 0; j < 5; j++)
                            res = arr[round_no][j] == 5 ? 5 : 0;
                        break;
                    case 5:
                        for(j = 0; j < 5; j++)
                            res = arr[round_no][j] == 6 ? 6 : 0;
                        break;
                    case 6:
                        for(j = 0; j < 5; j++)
                            res = arr[round_no][j];
                        break;
                    case 7:
                        for(j = 0; j < 7; j++)
                        {
                            if(special[j] >= 3)
                                break;
                        }
                        if(j < 7)
                            for(j = 0; j < 5; j++)
                                res = arr[round_no][j];
                        break;
                    case 8:
                        for(j = 0; j < 7; j++)
                        {
                            if(special[j] >= 4)
                                break;
                        }
                        if(j < 7)
                            for(j = 0; j < 5; j++)
                                res = arr[round_no][j];
                        break;
                    case 9:
                        for(j = 0; j < 7; j++)
                        {
                            if(special[j] >= 5)
                                break;
                        }
                        if(j < 7)
                            res = 50;
                        break;
                    case 10:
                        for(j = 0; j < 5; j++)
                            tem_array[j] = arr[round_no][j];
                        sort(tem_array, tem_array + 5);
                        cnt = 1;
                        for(j = 1; j < 5; j++)
                            if(tem_array[j] > tem_array[j - 1])
                                cnt++;
                        if(cnt >= 4)
                            res = 25;
                        break;
                    case 11:
                        for(j = 0; j < 5; j++)
                            tem_array[j] = arr[round_no][j];
                        sort(tem_array, tem_array + 5);
                        cnt = 1;
                        for(j = 1; j < 5; j++)
                            if(tem_array[j] > tem_array[j - 1])
                                cnt++;
                        if(cnt == 5)
                            res = 35;
                        break;
                    case 12:
                        cnt = 0;
                        for(j = 0; j < 7; j++)
                        {
                            if(special[j] == 2 || special[j] == 3)
                                cnt += special[j];
                        }
                        if(cnt == 5)
                            res = 50;
                        break;
                    default:
                        break;
                    }
                    res += call(set_bit(round_no, r), set_bit(mask, i));
                    ret = max(res, ret);
                }
            }
        }
    }
    return ret;
}
    int main()
    {
//    _
        int i, j;
    while(cin >> arr[0][0])
    {
        ans = 0;
        clr(dp, -1);
        for(i = 1; i < 5; i++)
            cin >> arr[0][i];
        for(i = 1; i < 13; i++)
            for(j = 0; j < 5; j++)
                cin >> arr[i][j];
        cout << call(0, 0) << endl;
    }
    return 0;
}

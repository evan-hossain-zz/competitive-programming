#include <bits/stdc++.h>

#define in freopen("ranking.in", "r", stdin);
#define out freopen("ranking.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 1010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

string teamNames[MAX];
struct team{
    int teamNo, solved, penalty;
    team(){
        teamNo = solved = penalty = 0;
    }
};
int n, participatedIn[MAX];
double score[MAX], RScore;

bool comp(const team &a, const team &b)
{
    if(a.solved == b.solved)
        return a.penalty < b.penalty;
    return a.solved > b.solved;
}

vector <team> readyStandings()
{
    int totProbs, totSubs, teamNo, timeCnt;
    char prob, status;
    cin >> totProbs >> totSubs;
    vector <team> ret;
    int penalty[MAX][30] = {0}, solved[MAX][30], i, j;
    clr(solved, -1);
    while(totSubs--)
    {
        cin >> teamNo >> prob >> timeCnt >> status;
        if(solved[teamNo][prob-'A'] != -1)
            continue;
        if(status == '-')
            penalty[teamNo][prob-'A']++;
        else
            solved[teamNo][prob-'A'] = penalty[teamNo][prob-'A']*20 + timeCnt;

    }
    for(i = 1; i <= n; i++)
    {
        team temp;
        for(j = 0; j < totProbs; j++)
        {
            if(solved[i][j] != -1)
            {
                temp.solved++;
                temp.penalty += solved[i][j];
            }
        }
        if(temp.solved)
        {
            temp.teamNo = i;
            ret.pb(temp);
        }
    }
    sort(all(ret), comp);
    return ret;
}

int main()
{
        in;
        out;
    int i, contest, len = 0;
    cin >> n;
    cin.ignore();
    for(i = 1; i <= n; i++)
    {
        getline(cin, teamNames[i]);
        len = max(len, SZ(teamNames[i]));
    }
    cin >> contest;
    while(contest--)
    {
        int k, x;
        cin >> k;
        for(i = 0; i < k; i++)
        {
            cin >> x;
            participatedIn[x]++;
        }
        auto standings = readyStandings();
        if(standings.empty()) continue;
        double Bi = k - 2, Ai = 2*Bi + 2;
        auto champ = standings.front();
        int pos = 0, same = 1;
        for(i = 0; i < SZ(standings); i++)
        {
            team T = standings[i];
            if(champ.solved)
                RScore = T.solved/(1.0*champ.solved);
            else
                RScore = 0;
            if(i && standings[i-1].solved == T.solved && standings[i-1].penalty == T.penalty)
                same++;
            else
            {
                pos += same;
                same = 1;
            }
            score[T.teamNo] += RScore * (Ai/(pos+Bi));
        }
    }
    vector <pair<double,int>> res;
    for(i = 1; i <= n; i++)
    {
        if(participatedIn[i])
            res.pb(mp(score[i]/participatedIn[i], i));
        else
            res.pb(mp(0, i));
    }
    sort(res.rbegin(), res.rend());
    for(auto r: res)
    {
        cout << teamNames[r.second];
        int extra = len - SZ(teamNames[r.second]);
        while(extra--)
            cout << ' ';
        cout << setprecision(4) << fixed << ' ' << r.first << "\n";
    }
    return 0;
}

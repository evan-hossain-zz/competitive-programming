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

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi 2*acos(0)

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct team_info
{
    string team_name;
    int total_points_earned;
    int games_played;
    int wins;
    int ties;
    int losses;
    int goals_scored;
    int goals_against;
};

bool comp(const team_info &a, const team_info &b);

int main()
{
    //out;
    string tournament_name, team1, team2;
    char t1[35], t2[35];
    int number_of_tournaments, game_played, teams, i, m, score1, score2;
    scanf("%d", &number_of_tournaments);
    while(getchar() != '\n');
    while(number_of_tournaments--)
    {
        map <string, int> mp;
        vector <team_info> v;
        team_info t;
        m = 0;
        getline(cin, tournament_name);
        scanf("%d", &teams);
        while(getchar() != '\n');
        while(teams--)
        {
            getline(cin, t.team_name);
            t.games_played = t.goals_scored = t.goals_against =\
            t.losses = t.ties = t.total_points_earned = t.wins = 0;
            mp[t.team_name] = m++;
            v.pub(t);
        }
        scanf("%d", &game_played);
        while(getchar() != '\n');
        while(game_played--)
        {
            scanf("%[^#]#%d@%d#%[^\n]", t1, &score1, &score2, t2);
            getchar();
            team1 = t1, team2 = t2;
            int m1 = mp[team1];
            int m2 = mp[team2];
            v[m1].games_played++;
            v[m1].goals_scored += score1;
            v[m1].goals_against += score2;
            v[m2].games_played++;
            v[m2].goals_scored += score2;
            v[m2].goals_against += score1;
            if(score1 > score2)
            {
                v[m1].wins++;
                v[m1].total_points_earned += 3;
                v[m2].losses++;
            }
            else if(score2 > score1)
            {
                v[m2].wins++;
                v[m2].total_points_earned += 3;
                v[m1].losses++;
            }
            else
            {
                v[m1].ties++;
                v[m2].ties++;
                v[m1].total_points_earned++;
                v[m2].total_points_earned++;
            }
        }
        sort(v.begin(), v.end(), comp);
        printf("%s\n", tournament_name.c_str());
        for(i = 0; i < v.size(); i++)
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i + 1, v[i].team_name.c_str(),\
                v[i].total_points_earned, v[i].games_played, v[i].wins , v[i].ties, v[i].losses,\
                v[i].goals_scored - v[i].goals_against, v[i].goals_scored, v[i].goals_against);
        if(number_of_tournaments)
            printf("\n");
    }
    return 0;
}

bool comp(const team_info &a, const team_info &b)
{
    if(a.total_points_earned != b.total_points_earned)
        return a.total_points_earned > b.total_points_earned;
    if(a.wins != b.wins)
        return a.wins > b.wins;
    if((a.goals_scored - a.goals_against) != (b.goals_scored - b.goals_against))
        return (a.goals_scored - a.goals_against) > (b.goals_scored - b.goals_against);
    if(a.goals_scored != b.goals_scored)
        return a.goals_scored > b.goals_scored;
    if(a.games_played != b.games_played)
        return a.games_played < b.games_played;
    string x, y;
    for(int i = 0; i < a.team_name.size(); i++)
        x += toupper(a.team_name[i]);
    for(int i = 0; i < b.team_name.size(); i++)
        y += toupper(b.team_name[i]);
    return x < y;
}

#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main()
{
    string tm, cn;
    map <string, string> team;
    map <string, int> candi;
    int test, n, m, max, tie;
    cin >> test;
    while(getchar() != '\n');
    while(test--)
    {
        max = tie = 0;
        cin >> n;
        while(getchar() != '\n');
        while(n--)
        {
            getline(cin, cn);
            getline(cin, tm);
            team[cn] = tm;
        }
        cin >> m;
        while(getchar() != '\n');
        while(m--)
        {
            getline(cin, cn);
            if(team.find(cn) == team.end())
                continue;
            else
            {
                candi[cn]++;
                if(candi[cn] > max)
                    max = candi[cn];
                else if(candi[cn] == max)
                    tie = max;
            }
        }
        if(tie == max)
            cout << "tie\n";
        else
        {
            for(map <string, int> :: iterator it = candi.begin();\
            it != candi.end(); it++)
            {
                if(it ->second == max)
                {
                    cout << team[it ->first] << endl;
                    break;
                }
            }
        }
        if(test)
        {
            team.clear();
            candi.clear();
            printf("\n");
        }
    }
}

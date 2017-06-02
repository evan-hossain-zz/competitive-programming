#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>

#define pub push_back
#define SZ 105

using namespace std;

int main()
{
    string a, b;
    queue <int> q;
    vector <int> adj[SZ];
    map <string, int> string_to_int;
    map <int, string> int_to_string;
    int n, m, i, j, indeg[SZ], kase = 1;
    while(scanf("%d", &n) == 1)
    {
        string_to_int.clear();
        int_to_string.clear();
        i = 1;
        while(n--)
        {
            cin >> a;
            string_to_int[a] = i;
            int_to_string[i] = a;
            indeg[i] = 0;
            i++;
        }
        n = i;
        scanf("%d", &m);
        while(m--)
        {
            cin >> a >> b;
            adj[string_to_int[a]].pub(string_to_int[b]);
            indeg[string_to_int[b]]++;
        }
        a = " Dilbert should drink beverages in this order:";
        bool flag = true;
        while(flag)
        {
            flag = false;
            for(i = 1; i < n; i++)
            {
                if(indeg[i] == 0)
                {
                    flag = true;
                    a += " " + int_to_string[i];
                    indeg[i]--;
                    for(j = 0; j < adj[i].size(); j++)
                        indeg[adj[i][j]]--;
                    adj[i].clear();
                }
                if(flag)
                    break;
            }
        }
        cout << "Case #" << kase++ << ":" << a << '.' << endl << endl;
    }
}

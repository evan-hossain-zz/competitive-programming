#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    map <string, int> m;
    string s;
    int i = 0, kase, cnt = 1;
    double val, total, res;
    cin >> kase;
    getchar();
    getchar();
    while(i < kase)
    {
        total = 0;
        if(i)
            cout << endl;
        while(getline(cin, s) && s.size())
        {
            m[s]++;
            total++;
        }
        for(map < string, int > ::\
        iterator it = m.begin(); it != m.end(); it++)
        {
            res = it -> second / total;
            cout << it -> first;
            printf(" %.4lf\n", res * 100);
        }
        i++;
        m.clear();
    }
    return 0;
}

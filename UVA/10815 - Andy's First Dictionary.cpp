#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    char c, s[300];
    string temp;
    map <string, int> m;
    int i = 0;
    while(scanf("%c", &c) == 1)
    {
        if((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z'))
            s[i++] = tolower(c);
        else
        {
            s[i] = 0;
            if(strlen(s))
            {
                temp = s;
                m[temp];
                i = 0;
            }
        }
    }
    s[i] = 0;
    if(strlen(s))
    {
        temp = s;
        m[temp];
    }
    for(map <string, int> :: iterator it = m.begin();
            it != m.end(); it++)
        cout << it ->first << endl;
    return 0;
}

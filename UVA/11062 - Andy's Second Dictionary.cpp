#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;
char s[2500000];
int main()
{
    char c;
    string temp;
    map <string, int> m;
    int i = 0;
    while(scanf("%c", &c) == 1)
    {
        if((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z'))
            s[i++] = tolower(c);
        else if(c == '-')
        {
            scanf("%c", &c);
            if((c >= 'A' && c <= 'Z') ||
                    (c >= 'a' && c <= 'z'))
            {
                s[i++] = '-';
                s[i++] = tolower(c);
            }
            continue;
        }
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


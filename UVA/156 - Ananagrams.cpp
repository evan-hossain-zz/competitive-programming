#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    map <string, string> str;
    vector <string> v;
    int i, l;
    map <string, int> freq;
    string s, temp;
    while(cin >> s && s != "#")
    {
        l = s.size();
        for(i = 0; i < l; i++)
            temp += tolower(s[i]);
        sort(temp.begin(), temp.end());
        str[temp] = s;
        freq[temp]++;
        temp.clear();
    }
    map <string, string> :: iterator it;
    for(it = str.begin(); it != str.end(); it++)
    {
        if(freq[it ->first] == 1)
            v.push_back(it ->second);
    }
    sort(v.rbegin(), v.rend());
    i = v.size();
    while(i--)
        cout << v[i] << endl;
    return 0;
}

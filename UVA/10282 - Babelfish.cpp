#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string a, b, tem;
    int i;
    map <string, string> m;
    while(getline(cin, tem) && tem.size())
    {
        istringstream iss(tem);
        iss >> a >> b;
        m[b] = a;
    }
    while(cin >> tem)
    {
        if(m.find(tem) == m.end())
            cout << "eh\n";
        else
            cout << m[tem] << endl;
    }
    return 0;
}

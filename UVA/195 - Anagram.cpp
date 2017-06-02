#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>


using namespace std;
char str[6000];
bool comp(const char &a, const char &b)
{
    int ganja = tolower(a) - tolower(b);
    return ganja?ganja < 0 : a < b;
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf(" %s", str);
        sort(&str[0], &str[strlen(str)], comp);
        do{
            printf("%s\n", str);
        }while(next_permutation(&str[0], &str[strlen(str)]\
                                , comp));
    }
    return 0;
}

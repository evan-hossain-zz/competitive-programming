#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/
    unsigned long long n, input;
    int kase = 0, paisi;
    while(cin >> n)
    {
        input = n;
        paisi = 0;
        printf("%4d. ", ++kase);
        while(n / 100000000000000)
        {
            cout << n / 100000000000000 << " kuti";
            n = n % 100000000000000;
            paisi = 1;
        }
        while(n / 1000000000000)
        {
            if(paisi) cout << " ";
            cout << n / 1000000000000 << " lakh";
            n = n % 1000000000000;
            paisi = 1;
        }
        if(input >= 1000000000000)
            cout << " lakh";
        while(n / 10000000000)
        {
            if(paisi) cout << " ";
            cout << n / 10000000000 << " hajar";
            n = n % 10000000000;
            paisi = 1;
        }
        if(input >= 10000000000)
            cout << " hajar";
        while(n / 1000000000)
        {
            if(paisi) cout << " ";
            cout << n / 1000000000 << " shata";
            n = n % 1000000000;
            paisi = 1;
        }
        if(input >= 1000000000)
            cout << " shata";
        while(n / 10000000)
        {
            if(paisi) cout << " ";
            cout << n / 10000000 << " kuti";
            n = n % 10000000;
            paisi = 1;
        }
        if(input >= 10000000)
            cout << " kuti";
        while(n / 100000)
        {
            if(paisi) cout << " ";
            cout << n / 100000 << " lakh";
            n = n % 100000;
            paisi = 1;
        }
        while(n / 1000)
        {
            if(paisi) cout << " ";
            cout << n / 1000 << " hajar";
            n = n % 1000;
            paisi = 1;
        }
        while(n / 100)
        {
            if(paisi) cout << " ";
            cout << n / 100 << " shata";
            n = n % 100;
            paisi = 1;
        }
        if(input == 0)
            cout << "0\n";
        else if(n != 0)
            cout << " " << n << endl;
        else
            cout << endl;
    }
    return 0;
}

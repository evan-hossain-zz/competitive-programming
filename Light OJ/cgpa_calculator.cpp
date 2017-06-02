#include <bits/stdc++.h>

using namespace std;

int main()
{
    double credit, point, cgpa = 0, total_credit = 0;;
    string s;
    while(cin >> credit && credit)
    {
        cin >> s;
        if(s == "A+")
            cgpa += (credit * 4.0);
        else if(s == "A")
            cgpa += (credit * 3.75);
        else if(s == "A-")
            cgpa += (credit * 3.5);
        else if(s == "B+")
            cgpa += (credit * 3.25);
        else if(s == "B")
            cgpa += (credit * 3.0);
        else if(s == "B-")
            cgpa += (credit * 2.75);
        else if(s == "C+")
            cgpa += (credit * 2.5);
        else if(s == "C")
            cgpa += (credit * 2.25);
        else if(s == "C-")
            cgpa += (credit * 2.0);
        total_credit += credit;
    }
    printf("CGPA = %lf\n", cgpa / total_credit);
}

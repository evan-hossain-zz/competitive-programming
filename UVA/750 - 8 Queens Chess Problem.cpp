#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define pub push_back
#define pob pop_back

using namespace std;

void func(void);
void call(void);
int check_corner(int rw, int cl);

int col[9], cnt, r, color[9][9], store[95][9][9], rr, cc;
vector <int> res;

int main()
{
    //freopen("out.txt", "w", stdout);
    int test, findc, findr;
    scanf("%d", &test);
    func();
    while(test--)
    {
        cnt = 0;
        scanf("%d %d", &rr, &cc);
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        for(int p = 0; p < 93; p++)
        {
            if(store[p][rr][cc] == 1)
            {
                printf("%2d     ", ++cnt);
                for(findc = 1; findc < 9; findc++)
                    for(findr = 1; findr < 9; findr++)
                    {
                        if(store[p][findr][findc] == 1)
                        {
                            cout << " " << findr;
                            break;
                        }
                    }
                printf("\n");
            }
        }
        if(test)
            printf("\n");
    }
    return 0;
}

void func(void)
{
    int i, j;
    for(int ic = 1; ic < 9; ic++)
    {
        res.pub(ic);
        res.pub(1);
        color[1][ic] = col[ic] = 1;
        r = 2;
        call();
        col[ic] = 0, color[1][ic] = 0;
        res.clear();
    }
}

void call(void)
{
    if(res.size() == 16)
    {
        for(int p = 0; p < 16; p++)
            store[cnt][res[p]][res[++p]] = 1;
        cnt++;
        return;
    }
    for(int j = 1; j < 9; j++)
    {
        if(col[j] == 0 && check_corner(r, j))
        {
            col[j] = color[r][j] = 1;
            res.pub(j);
            res.pub(r);
            r++;
            call();
            r--, res.pob(), res.pob(), col[j] = color[r][j] = 0;
        }
    }
}

int check_corner(int rw, int cl)
{
    int m, n;
    for(m = rw + 1, n = cl + 1; m < 9 && n < 9; m++, n++)
    {
        if(color[m][n])
            return 0;
    }
    for(m = rw - 1, n = cl - 1; m > 0 && n > 0; m--, n--)
    {
        if(color[m][n])
            return 0;
    }
    for(m = rw - 1, n = cl + 1; m > 0 && n < 9; m--, n++)
    {
        if(color[m][n])
            return 0;
    }
    for(m = rw + 1, n = cl - 1; m < 9 && n > 0; m++, n--)
    {
        if(color[m][n])
            return 0;
    }
    return 1;
}

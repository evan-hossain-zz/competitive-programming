#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

string arr[502];
int digits[502];
int indx = 2;

void creat_series(string a, string b);
int bsrch(int n);

int main()
{
    arr[1] = "1", arr[2] = "2";
    digits[1] = digits[2] = 1;
    creat_series(arr[1], arr[2]);
    int c, i, cnt, kom;
    string a, b;
    while(cin >> a >> b)
    {
        if(a == "0" && b == "0")
            break;
        cnt = 0;
        kom = 1;
        c = bsrch(a.size());
        while(1)
        {
            if(arr[c].size() == a.size())
            {
                for(i = 0; i < a.size(); i++)
                {
                    if((a[i] - '0') == (arr[c][i] - '0'))
                        continue;
                    if((a[i] - '0') > (arr[c][i] - '0'))
                    {
                        kom = 0;
                        break;
                    }
                    else
                        break;
                }
            }
            if(kom == 0)
            {
                kom = 1;
                c++;
                continue;
            }
           if(arr[c].size() == b.size())
            {
                for(i = 0; i < b.size(); i++)
                {
                    if((b[i] - '0') == (arr[c][i] - '0'))
                        continue;
                    if((b[i] - '0') < (arr[c][i] - '0'))
                    {
                        kom = 0;
                        break;
                    }
                    else
                        break;
                }
            }
            if(!kom || (arr[c].size() > b.size()))
                break;
            c++;
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

void creat_series(string a, string b)
{
    indx++;
    int carry = 0, ac, bc, t;
    string tem;
    for(ac = a.size() - 1, bc = b.size() - 1; bc >= 0; ac--, bc--)
        {
            if(ac < 0)
                t = (b[bc] - '0') + carry;
            else
                t = (a[ac] - '0') + (b[bc] - '0') + carry;
            carry = 0;
            if(t < 10)
                tem += (t + '0');
            else
                {
                    carry = 1;
                    tem += ((t % 10) + '0');
                }
        }
    if(carry)
        tem += '1';
    for(ac = tem.size() - 1; ac >= 0; ac--)
        arr[indx] += tem[ac];
    digits[indx] = tem.size();
    if(indx < 500)
        creat_series(b, arr[indx]);
    return;
}

int bsrch(int n)
{
    int low = 0, high = 500, mid, ret;
    while(low <= high)
    {
        mid = low + high >> 1;
        if(digits[mid] > n)
            high = mid - 1;
        else if(digits[mid] < n)
            low = mid + 1;
        else
        {
            ret = mid;
            high = mid - 1;
        }
    }
    return ret;
}

/*#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

string arr[502];
int digits[502];
int indx = 2;

void creat_series(string a, string b);
int bsrch(int n);

int main()
{
    arr[1] = "1", arr[2] = "2";
    digits[1] = digits[2] = 1;
    creat_series(arr[1], arr[2]);
    int c, st, en, i;
    bool kom, beshi;
    string a, b;
    while(cin >> a >> b)
    {
        if(a == "0" && b == "0")
            break;
        kom = beshi = 1;
        c = bsrch(a.size());
        while(1)
        {
            if(arr[c].size() > a.size())
            {
                st = c;
                break;
            }
            if(arr[c].size() == a.size())
            {
                for(i = 0; i < a.size(); i++)
                {
                    if((a[i] - '0') == (arr[c][i] - '0'))
                        continue;
                    if((a[i] - '0') > (arr[c][i] - '0'))
                    {
                        kom = 0;
                        break;
                    }
                    else
                    {
                        beshi = 0;
                        st = c;
                        break;
                    }
                }
                if(i == a.size())
                {
                    st = c;
                    break;
                }
            }
            if(kom == 0)
            {
                kom = 1;
                c++;
                continue;
            }
            if(beshi == 0)
                break;
        }
        c = bsrch(b.size());
        beshi = kom = 1;
        while(1)
        {
            if(arr[c].size() > b.size())
                break;
            if(arr[c].size() < b.size())
            {
                en = c;
                break;
            }
            if(arr[c].size() == b.size())
            {
                for(i = 0; i < b.size(); i++)
                {
                    if((b[i] - '0') == (arr[c][i] - '0'))
                        continue;
                    if((b[i] - '0') < (arr[c][i] - '0'))
                    {
                        beshi = 0;
                        break;
                    }
                    else
                    {
                        en = c;
                        kom = 0;
                        break;
                    }
                }
                if(i == b.size())
                {
                    en = c;
                    break;
                }
            }
            if(kom == 0)
            {
                c++;
                kom = 1;
                continue;
            }
            if(beshi == 0)
            {
                en = c - 1;
                break;
            }
        }
        printf("%d\n", en - st + 1);
    }
    return 0;
}

void creat_series(string a, string b)
{
    indx++;
    int carry = 0, ac, bc, t;
    string tem;
    for(ac = a.size() - 1, bc = b.size() - 1; bc >= 0; ac--, bc--)
        {
            if(ac < 0)
                t = (b[bc] - '0') + carry;
            else
                t = (a[ac] - '0') + (b[bc] - '0') + carry;
            carry = 0;
            if(t < 10)
                tem += (t + '0');
            else
                {
                    carry = 1;
                    tem += ((t % 10) + '0');
                }
        }
    if(carry)
        tem += '1';
    for(ac = tem.size() - 1; ac >= 0; ac--)
        arr[indx] += tem[ac];
    digits[indx] = tem.size();
    if(indx < 500)
        creat_series(b, arr[indx]);
    return;
}

int bsrch(int n)
{
    int low = 0, high = 500, mid, ret;
    while(low <= high)
    {
        mid = low + high >> 1;
        if(digits[mid] > n)
            high = mid - 1;
        else if(digits[mid] < n)
            low = mid + 1;
        else
        {
            ret = mid;
            high = mid - 1;
        }
    }
    return ret;
}
*/

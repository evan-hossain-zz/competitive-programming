#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
char str[N];
int *rnk, r[N], sa[N], height[N];
int wa[N], wb[N], wm[N];
bool comp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}
void get_sa(int *r, int *sa, int n, int m)
{
    int *x = wa, *y = wb, *t, i, j, p;
    for(i = 0; i < m; ++i) wm[i] = 0;
    for(i = 0; i < n; ++i) wm[x[i] = r[i]]++;
    for(i = 1; i < m; ++i) wm[i] += wm[i-1];
    for(i = n-1; i >= 0; --i) sa[--wm[x[i]]] = i;
    for(i = 0, j = 1, p = 0; p < n; j <<= 1, m = p) {
        for(p = 0, i = n - j; i < n; ++i) y[p++] = i;
        for(i = 0; i < n; ++i) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < m; ++i) wm[i] = 0;
        for(i = 0; i < n; ++i) wm[x[y[i]]]++;
        for(i = 1; i < m; ++i) wm[i] += wm[i-1];
        for(i = n-1; i >= 0; --i) sa[--wm[x[y[i]]]] = y[i];
        for(t = x, x = y, y = t, i = p = 1, x[sa[0]] = 0; i < n; ++i) {
            x[sa[i]] = comp(y, sa[i], sa[i-1], j) ? p-1 : p++;
        }
    }
    rnk = x;
}
void get_height(int *r, int *sa, int n)
{
    for(int i = 0, j = 0, k = 0; i < n; height[rnk[i++]] = k) {
        for(k ? --k : 0, j = sa[rnk[i]-1]; r[i+k] == r[j+k]; ++k);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    while(~scanf("%s",str)) {
        if(str[0] == '#') break;
        int len = strlen(str);
        for(int i = 0; i < len; i++)
            r[i] = str[i];
        r[len] = 0; //要比可能出现的所有值都要小
        get_sa(r, sa, len+1, 256);
        get_height(r, sa, len);
        int ans = 0, minid, maxid;
        for(int i = 1; i <= (len+1)/2; ++i) { //查一半就好了，长度大于（len+1）/2的子串不可能重复两次
            minid = 1010, maxid = -1;
            for(int j = 1; j <= len; ++j) {
                if(height[j] >= i) {
                    if(sa[j-1] < minid) minid = sa[j-1];
                    if(sa[j-1] > maxid) maxid = sa[j-1];
                    if(sa[j] < minid) minid = sa[j];
                    if(sa[j] > maxid) maxid = sa[j];
                }
                else {
                    if(maxid != -1 && minid + i <= maxid) ans++;
                    minid = 1010, maxid = -1;
                }
            }
            if(maxid != -1 && minid + i <= maxid) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

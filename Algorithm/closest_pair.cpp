
point arr[MAX], sortedY[MAX];
bool flag[MAX];

bool compareX(const point &a, const point &b){
    return a.x < b.x;
}
bool compareY(const point &a, const point &b){
    return a.y < b.y;
}

double closest_pair(point X[], point Y[], int n)
{
    double left_call, right_call, mindist;
    if(n == 1) return infinity;
    if(n == 2)
        return getdist(X[0], X[1]);
    int n1, n2, ns, j, m = n / 2, i;
    point xL[m + 1], xR[m + 1], yL[m + 1], yR[m + 1], Xm = X[m - 1], yS[n];
    for(i = 0; i < m; i++)
    {
        xL[i] = X[i];
        flag[X[i].i] = 0;
    }
    for(; i < n; i++)
    {
        xR[i - m] = X[i];
        flag[X[i].i] = 1;
    }
    for(i = n2 = n1 = 0; i < n; i++)
    {
        if(!flag[Y[i].i]) yL[n1++] = Y[i];
        else yR[n2++] = Y[i];
    }
    left_call = closest_pair(xL, yL, n1);
    right_call = closest_pair(xR, yR, n2);
    mindist = min(left_call, right_call);
    for(i = ns = 0; i < n; i++)
        if(sqr(Y[i].x - Xm.x) < mindist)
            yS[ns++] = Y[i];
    for(i = 0; i < ns; i++)
        for(j = i + 1; j < ns && sqr(yS[j].y - yS[i].y) < mindist; j++)
            mindist = min(mindist, getdist(yS[i], yS[j]));
    return mindist;
}

int main()
{
    int n, i;
    double ans;
    while(scanf("%d", &n) == 1 && n)
    {
        ans = infinity;
        for(i = 0; i < n; i++)
        {
            scanf("%lf %lf", &arr[i].x, &arr[i].y);
            arr[i].i = i;
            sortedY[i] = arr[i];
        }
        sort(arr, arr + n, compareX);
        sort(sortedY, sortedY + n, compareY);
        ans = closest_pair(arr, sortedY, n);
        ans = sqrt(ans);
        if(ans - 10000.0 > 1e-7)
            printf("INFINITY\n");
        else
            printf("%.4lf\n", ans);
    }
    return 0;
}

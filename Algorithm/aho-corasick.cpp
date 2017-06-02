struct tt
{
    int par, child[26], dep;
    vector<int>str;
};

tt T[250010]; /// size = total number of pattern strings * length per string
char words[502][502];
int sz1;
char str[1000010]; /// main string

void init(int lim)
{
    for(int i=0;i<=lim;i++)
    {
        T[i].par=0;
        T[i].dep=0;
        memset(T[i].child, 0, sizeof T[i].child);
        T[i].str.clear();
    }
    sz1=1;
    return;
}

void build(int n)
{
    int i, j, last, len;
    char ch;
    for(i=0;i<n;i++)
    {
        last=0;
        len = strlen(words[i]);
        for(j=0;j<len;j++)
        {
            ch = words[i][j] - 'a';
            if(T[last].child[ch]==0)
                T[last].child[ch]=sz1++;
            T[T[last].child[ch]].dep = T[last].dep + 1;
            last = T[last].child[ch];
        }
        T[last].str.pb(i);
    }

    queue<int>Q;
    for(i=0;i<26;i++)
    {
        if(T[0].child[i])
        {
            Q.push(T[0].child[i]);
            T[T[0].child[i]].par = 0;
        }
    }
    int u, v, k;
    while(!Q.empty())  /// implementing kmp in the trie tree with kind of bfs
    {
        u = Q.front(); Q.pop();
        for(i=0;i<26;i++)
        {
            if(T[u].child[i])
            {
                v = T[u].child[i];
                k = T[u].par;
                while(k>0 && T[k].child[i]==0)
                    k = T[k].par;
                T[v].par = T[k].child[i];
                Q.push(v);
            }
        }
    }
    return;
}

int freq[250000], ans[505];

void search() /// this function will take a string as main input and find the frequency of pattern strings in this string
{
    int i, j, k, len, u, v;
    char ch;
    len = strlen(str);
    int cur=0;
    memset(freq, 0, sizeof freq);
    for(i=0;i<len;i++)
    {
        ch = str[i] - 'a';
        if(T[cur].child[ch]==0)
        {
            k = T[cur].par;
            while(k>0 && T[k].child[ch]==0)
                k = T[k].par;
            cur = T[k].child[ch];
        }
        else
            cur = T[cur].child[ch];
        freq[cur]++; /// ei node ei frequency pabe
    }
    vector<pii>store;
    for(i=0;i<sz1;i++)
        store.pb(MP(T[i].dep, i));
    sort(store.rbegin(), store.rend());
    for(i=0;i<sz1;i++)
    {
        v = store[i].second;
        freq[T[v].par]+=freq[v]; /// parent gulake cummulatively frequency gula die dea
    }

    for(i=1;i<sz1;i++)
    {
        if(SZ(T[i].str))
        {
            for(j=0;j<SZ(T[i].str);j++)
            {
                ans[T[i].str[j]] = freq[i];
            }
        }
    }
}

int main()
{
    int t, cas=1;
    scanf("%d", &t);
    sz1=1;
    while(t--)
    {
        init(sz1);
        int n, i, j;
        scanf("%d", &n);
        scanf(" %s", &str);
        for(i=0;i<n;i++)
            scanf(" %s", &words[i]); /// input of pattern strings

        build(n); ///building trie with kmp idea (this function deals with only the patterns)
        search();
        csprnt;
        for(i=0;i<n;i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}

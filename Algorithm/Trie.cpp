int trie[MAX][52], cnt[MAX], last;
char str[10001];

void add(char *str)
{
    int i, id, cur = 0;
    for(i = 0; str[i]; i++)
    {
        if(islower(str[i]))
            id = str[i] - 'a' + 26;
        else
            id = str[i] - 'A';
        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;
            clr(trie[last], -1);
            cnt[last] = 0;
        }
        cur = trie[cur][id];
    }
    cnt[cur]++;
}
/// do clr(trie[0], -1) and last = 0 for every case

int get(char *str)
{
    int id, i, cur = 0;
    for(i = 0; str[i]; i++)
    {
        if(islower(str[i]))
            id = str[i] - 'a' + 26;
        else
            id = str[i] - 'A';
        if(trie[cur][id] == -1)
            return 0;
        cur = trie[cur][id];
    }
    return cnt[cur];
}

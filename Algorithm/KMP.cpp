int match[MAX];

void compute_match_array(string &pat)
{
    int m = SZ(pat);
    int len = 0;
    int i;
    match[0] = 0, i = 1;
    // calculate match[i] for i = 1 to m - 1
    while(i < m)
    {
        if(pat[i] == pat[len])
        {
            len++;
            match[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
                len = match[len - 1];
            else
            {
                match[i] = 0;
                i++;
            }
        }
    }
}

vector <int> kmp_match(string pat, string text)
{
    vector <int> v;
    int m = SZ(pat), n = SZ(text);
    clr(match, 0);
    compute_match_array(pat);
    int j = 0, i = 0;
    while(i < n)
    {
        if(pat[j] == text[i])
            i++, j++;
        if(j == m)
        {
            v.pb(i - m + 1); // starting index in text of a match
            j = match[j - 1];
        }
        else if(pat[j] != text[i])
        {
            if(j != 0)
                j = match[j - 1];
            else
                i++;
        }
    }
    return v;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    vector <int> ans = kmp_match(pat, text);
    print_all(ans);
    return 0;
}


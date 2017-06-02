int hist[MAX];
stack <int> st;
int get_max_rec(int n)
{
    int i = 0, res = 0, tem, top;
    while(i < n)
    {
        if(st.empty() || hist[st.top()] <= hist[i])
            st.push(i++);
        else
        {
            top = st.top();
            st.pop();
            tem = hist[top] * (st.empty() ? i : i - st.top() - 1);
            res = max(tem, res);
        }
    }
    while(!st.empty())
    {
        top = st.top();
        st.pop();
        tem = hist[top] * (st.empty()? i : i - st.top() - 1);
        res = max(tem, res);
    }
    return res;
}

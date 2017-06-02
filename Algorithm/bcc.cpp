stack <pair <int, int> > s;
vector <int> adj[MAX];
int discover[MAX], bedge[MAX], discovery_time, bcc;
void dfs(int node, int from)
{
    discover[node] = bedge[node] = discovery_time++;
    int i, connected = adj[node].size(), to;
    pair <int, int> e, cur;
    for(i = 0; i < connected; i++)
    {
        to = adj[node][i];
        if(to == from) continue;
        if(!discover[to])
        {
            s.push(make_pair(node, to));
            dfs(to, node);
            bedge[node] = min(bedge[node], bedge[to]);
            if(bedge[to] >= discover[node])
            {
                bcc++;
                cur = make_pair(node, to);
                do {
                    e = s.top(); s.pop();
                } while(e != cur);
            }
        }
        else if(discover[node] > discover[to])
        {
            s.push(make_pair(node, to));
            bedge[node] = min(discover[to], bedge[node]);
        }
    }
}

int root(int v)
{
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}
void merge(int x,int y) 	//	x and y are some tools (vertices)
{
    x = root(x), y = root(y);
    if(par[y] < par[x])	// balancing the height of the tree
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

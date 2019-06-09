struct DSU{
    int size;
    vector<int> id;
    vector<int> si;
    vector< vector < int > > adj;
    DSU(int x)
    {
        size = x;
        id.resize(x + 1);
        si.resize(x + 1);
        adj.resize(x + 1);
        for (int i = 1 ; i <= x ; i++)
        {
            id[i] = i , si[i] = 1;
            adj[i].pb(i);
        }
    }
    
    int getRoot(int a)
    {
        while(a != id[a])
            a = id[a];
        return a;
    }
    void merge(int a , int b)
    {
        if (si[a] < si[b])
        {
            swap(a , b);
        }
        si[a] += si[b];
        id[b] = id[a];
        for (int i = 0 ; i < adj[b].size() ; i++)
            adj[a].pb(adj[b][i]);
    }
    
    void fun(int a , int b)
    {
        int x = getRoot(a);
        int y = getRoot(b);
        if (x == y)
            return;
        merge(x , y);
    }
};
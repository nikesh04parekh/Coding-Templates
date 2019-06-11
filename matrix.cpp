struct matrix
{
    vector<vector<int> > arr;
    int SZ;
    matrix()
    {
        
    }
    matrix(int x)
    {
        arr.resize(x);
        for (int i = 0 ; i < x ; i++)
            for (int j = 0 ; j < x ; j++)
                arr[i].pb(0);
    }

    void makeiden(int x)
    {
        for(int i = 0 ; i < x ;i++)
        {
            arr[i][i] = 1;
        }
    }
    
    void print(int x)
    {
        for (int i = 0 ; i < x ; i++)
            for (int j = 0 ; j < x ; j++)
                cout << arr[i][j] << " \n"[j == x - 1];
    }
    matrix operator + (const matrix &o) const 
    {
        matrix res;
        for(int i=0;i<SZ;i++)
        {
            for(int j=0;j<SZ;j++)
            {
                res.arr[i][j] = add(arr[i][j], o.arr[i][j] , mod);
            }
        }
        return res;
    }
    matrix multi(matrix b , int x)
    {
        struct matrix res(x);
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<x;j++)
            {
                res.arr[i][j] = 0;
                for(int k = 0 ; k < x ; k++)
                {
                    res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , b.arr[k][j] , mod) , mod);
                }
            }
        }
        return res;
    }
};

matrix power(matrix a , int b , int x)
{
    struct matrix res(x);
    for (int i = 0 ; i < x ; i++)
    {
            res.arr[i][i] = 1;
    }
    while(b)
    {
        if(b & 1)
        {
            res = res.multi(a , x);
        }
        a = a.multi(a , x);
        b = b / 2;
    }
    return res;
}
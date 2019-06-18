struct node {
    long long sum;
    node * left;
    node * right;
    node(int val = 0) 
    {
        sum = val;
        left = right = nullptr;
    }
};

node * trees[500000 + 5];

node * build(int l, int r) {
    if (l == r) {
        node * nn = new node();
        return nn;
    } else {
        int mid = (l + r) / 2;
        node * nn = new node();
        nn->left = build(l, mid);
        nn->right = build(mid+1, r);
        nn->sum = nn->left->sum + nn->right->sum;
        return nn;
    }
}

node * upd(node * rt, int l, int r, int pos, int val) {
    if (l == r)
    {
        node * nn = new node(val);
        return nn;
    }
    node * nn = new node();
    int md = (l + r) / 2;
    if (pos <= md) 
    {
        nn->left = upd(rt->left , l, md, pos, val);
        nn->right = rt->right;
    }
    else 
    {
        nn->left = rt->left;
        nn->right = upd(rt->right, md+1, r, pos, val);
    }
    nn->sum = nn->left->sum + nn->right->sum;
    return nn;
}

long long get(node * v , int l , int r , int k)
{
    //cout << l << " " << r << " " << v->sum << endl;
    if (l == r)
        return l;
    int md = (l + r) >> 1;
    int leftvalue = v->left->sum;
    if (leftvalue >= k)
        return get(v->left , l , md , k);
    else
        return get(v->right , md + 1 , r , k - leftvalue);
}

void print(node* v , int l , int r)
{
    cout << l << " " << r << " " << v->sum << endl;
    if (l == r)
        return;
    int m = (l + r) / 2;
    print(v->left , l , m);
    print(v->right , m + 1 , r);
}
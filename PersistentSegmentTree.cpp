int n;
int a[500001];

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
node * trees[500001];

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
    int mid = (l + r) / 2;
    if (pos <= mid) {
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

long long get(node * v, int l, int r, int tl, int tr)
{
    if (l == tl && r == tr)
        return v->sum;
    int md = (l + r) >> 1;
    if (tr <= md) {
        return get(v->left, l, md, tl, tr);
    } else if (tl > md) {
        return get(v->right, md+1, r, tl, tr);
    } else {
        return get(v->left, l, md, tl, md) + get(v->right, md+1, r, md+1, tr);
    }
}

void prepare()
{
    trees[0] = build(1, n);
    for(int i = 1; i <= n; ++i) 
    {
        int id = i;
        trees[i] = upd(trees[i-1], 1, n, id, a[id]);
    }
}
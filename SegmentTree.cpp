//Use MAXN

struct Node{
    int val;
    void no_use()
    {
        val = 0;
    }

    void merge(Node l , Node r)
    {
        val = l.val + r.val;
    }

    void init(int x)
    {
        val = x;
    }
};

vector<Node> seg(4 * MAXN);
vector<int> arr(MAXN);

void build(int index , int l , int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        seg[index].init(arr[l]);
        return;
    }

    int m = (l + r) >> 1;
    int left = 2 * index + 1;
    int right = left + 1;
    build(2 * index + 1 , l , m);
    build(2 * index + 2 , m + 1 , r);
    seg[index].merge(seg[left] , seg[right]);
    //cout << l << " " << r << " " << seg[index].val << endl;
}

Node query(int index , int l , int r , int ql , int qr)
{
    //cout << l << " " << r << endl;
    if (l > r || l > qr || r < ql)
    {
        struct Node temp;
        temp.no_use();
        return temp;
    }
    if (ql <= l && r <= qr)
        return seg[index];
    int m = (l + r) >> 1;
    struct Node temp;
    Node left = query(2*index + 1 , l , m , ql , qr);
    Node right = query(2*index + 2 , m + 1 , r , ql , qr);
    temp.merge(left , right);
    return temp;
}

void update(int index , int l , int r , int ind , int val)
{
    //trace2(l , r);
    if (l > r)
        return;
    if (l == r)
    {
        arr[ind] = val;
        seg[index].init(val);
        return;
    }
    int m = (l + r) >> 1;
    if (ind >= l && ind <= m)
        update(2*index + 1 , l , m , ind , val);
    else
        update(2*index + 2 , m + 1 , r , ind , val);
    seg[index].merge(seg[2*index + 1] , seg[2*index + 2]);
}
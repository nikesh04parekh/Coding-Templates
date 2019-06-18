
int n , q , k;

vector<int> arr;
bool comp(pair < pair < int , int > , int > a , pair < pair < int , int > , int > b)
{
    if (a.ff.ff / k == b.ff.ff / k)
        return a.ff.ss < b.ff.ss;
    return (a.ff.ff / k < b.ff.ff / k);
}

int freq[1000005];
ll ans = 0;

void add(int x)
{
    ans -= freq[x] * freq[x] * x;
    freq[x]++;
    ans += freq[x] * freq[x] * x;
}

void remove(int x)
{
    ans -= freq[x] * freq[x] * x;
    freq[x]--;
    ans += freq[x] * freq[x] * x; 
}
signed main()
{
    FAST;
    cin >> n >> q;
    arr.resize(n);
    k = sqrt(n);
    for (int i = 0 ; i < n ; i++)
        cin >> arr[i];
    vector < pair < pair < int , int > , int > > queries(q);
    rep(i , 0 , q)
    {
        cin >> queries[i].ff.ff >> queries[i].ff.ss;
        --queries[i].ff.ff;
        --queries[i].ff.ss;
        queries[i].ss = i;
    }
    sort(all(queries) , comp);
    int cl = 0 , cr = 0;
    int foo[q];
    memset(foo , 0 , sizeof foo);
    for (int i = 0 ; i < q ; i++)
    {
        int l = queries[i].ff.ff;
        int r = queries[i].ff.ss;
        //trace4(cl , l , cr , r);
        while(cl < l)
        {
            remove(arr[cl]);
            cl++;
        }
        while(cl > l) 
        {
            add(arr[cl - 1]);
            cl--;
        }
        while(cr > r + 1)
        {
            remove(arr[cr - 1]);
            cr--;
        }
        while(cr <= r)
        {
            add(arr[cr]);
            //cout << ans << endl;
            cr++;
        }
        foo[queries[i].ss] = ans;
    }
    for (int i = 0 ; i < q ; i++)
        cout << foo[i] << endl;
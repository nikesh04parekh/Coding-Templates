#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
#define mod1 998244353
#define timepass 1073741824
#define MAXN 100000 + 5
#define LOGN 20
using namespace std;
#define N 505

/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/*template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;*/

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(arr) arr.begin() , arr.end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i , a , n) for(int i = a ; i < n ; i++)
#define rrep(i , n , a) for (int i = n - 1 ; i >= a ; i--)
#define ms(arr , val) memset(arr , val , sizeof(arr))
#define sp(a , x) cout << fixed << setprecision(a) << x << endl; 
#define siz(temp) (ll)temp.size()
#define len(temp) (ll)temp.length()
#define int ll
#define s(arr) sort(all(arr))
#define r(arr) reverse(all(arr))
#define rs(arr) s(arr) ; r(arr)
#define pi acos(-1)
#define con continue
#define endl "\n"
#define w(q) while(q--)

//debug
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define trace7(a, b, c, d, e, f , g) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<< f << " | "<< #g <<": "<<g<<endl
#define trace8(a, b, c, d, e, f , g , h) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<< f << " | " << #g <<": "<< g <<" | "<<#h<< ": " << h << endl

typedef pair<int , int> pii;
typedef pair<int , pii> piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<piii> vpiii;

vector< vector < int > > adj(MAXN);
int parent[MAXN];
int depth[MAXN];
int par[LOGN][MAXN];

void dfs(int x , int p , int _depth = 0)
{
    depth[x] = _depth;
    for (auto it : adj[x])
    {
        if (it == p) continue;
        parent[it] = x;
        dfs(it , x , _depth + 1);
    }
}

void preprocess(int n)
{
    memset(par , -1 , sizeof(par));
    for (int i = 0 ; i < LOGN ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (i == 0)
                par[i][j] = parent[j];
            else if (par[i - 1][j] != -1)
                par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

ll findLCA(int a , int b)
{
    if (depth[a] < depth[b])
        swap(a , b);
    int diff = depth[a] - depth[b];
    for (int i = LOGN - 1 ; i >= 0 ; i--)
    {
        if (diff & (1 << i))
            a = par[i][a];
    }
    if (a == b)
        return a;
    for (int i = 0 ; i < LOGN ; i++)
    {
        if (par[i][a] != par[i][b])
        {
            a = par[i][a];
            b = par[i][b];
        }
    }
    return par[0][a];
}
ll LCAhelper(int a , int b)
{
    return (depth[a] + depth[b] - 2 * depth[findLCA(a , b)]);
}

signed main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0 ; i < n - 1 ; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    parent[1] = 0;
    dfs(1 , -1);
    preprocess(n);
    int q;
    cin >> q;
    // for (int i = 1 ; i <= n ; i++)
    //     trace3(i , parent[i] , depth[i]);
    w(q)
    {
        int a , b;
        cin >> a >> b;
        cout << findLCA(a , b) << endl;
    }
    return 0;
}
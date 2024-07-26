#include <bits/stdc++.h>

using namespace std;
#define int ull
typedef unsigned long long ull;

const int mod=1e9+7,N=5e5+10,M=1e6+10;

int n;

struct BIT
{
    ull tr[M];

    int lowbit(int x)
    {
        return x&-x;
    }

    void add(int x,ull c)
    {
        for(int i=x;i<M;i+=lowbit(i)) tr[i]+=c;
    }

    ull sum(int x)
    {
        ull res=0;
        for(int i=x;i;i-=lowbit(i)) res+=tr[i];
        return res;
    }
}tr1,tr2;

vector<int> e[N];
int A[N];
int son[N],siz[N];
int l[N],r[N],id[N],tot;
ull ans[N];
ull sum=0;

void dfs1(int u,int fa)
{
    l[u]=++tot;
    id[tot]=u;
    siz[u]=1;
    for(auto x : e[u])
    {
        if(x==fa) continue;
        dfs1(x,u);
        siz[u]+=siz[x];
        if(siz[x]>siz[son[u]]) son[u]=x;
    }
    r[u]=tot;
}

void dfs2(int u,int fa,bool keep)
{
    for(auto x: e[u])
    {
        if(x==fa||x==son[u]) continue;
        dfs2(x,u,0);
    }
    if(son[u]) dfs2(son[u],u,1),ans[u]+=ans[son[u]];
    for(auto x: e[u])
    {
        if(x==fa||x==son[u]) continue;
        for(int k=l[x];k<=r[x];k++)
        {
            ull xx=A[id[k]];
            ans[u]+=tr2.sum(M-1)-tr2.sum(xx-1);
            ans[u]+=tr1.sum(xx-1)*xx*xx;
            ans[u]-=xx*sum;
            tr1.add(xx,1);
            tr2.add(xx,xx*xx);
            sum+=xx;
        }
    }

    ull xx=A[u];
    ans[u]+=tr2.sum(M-1)-tr2.sum(xx-1);
    ans[u]+=tr1.sum(xx-1)*xx*xx;
    ans[u]-=xx*sum;

    tr1.add(xx,1);
    tr2.add(xx,xx*xx);
    sum+=xx;

    if(!keep)
    {
        for(int i=l[u];i<=r[u];i++)
        {
            ull xx=A[id[i]];
            sum-=xx;
            tr1.add(xx,-1);
            tr2.add(xx,-xx*xx);
        }
    }
}

void solve()
{
    cin >> n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin >> A[i];
    dfs1(1,0);dfs2(1,0,1);

    ull res=0;
    for(int i=1;i<=n;i++)
    {
        ans[i]*=2;
        res^=ans[i];
    }
    cout << res << "\n";
}

signed main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
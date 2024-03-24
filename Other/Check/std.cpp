// duziteng ^ ^
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const int M = 998244353;
const int mod = 1e9+7;
#define db double
#define int long long
int up(int a,int b){return a<0?a/b:(a+b-1)/b;}
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
#define pi acos(-1)
#define INF 0x3f3f3f3f3f3f3f3f
#define PII pair<int,int>
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
int n,m,color[1000010],flag;
vector<PII>g[1000010];
void dfs(int u,int st){
    if(flag)return;
    color[u]=st;
    for(auto [v,w]:g[u]){
        if(color[v]==-1)dfs(v,(st+w)%2);
        else{
            if(color[v]!=(st+w)%2){
                cout<<0<<endl;
                flag=1;
                return;
            }
        }
        if(flag)return;
    }
}
void solve(){
    flag=0;
    cin>>n>>m;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++){
        g[i].clear();
        color[i]=-1;
        for(int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='1');
        }
    }
    for(int i=1,j=m;i<=j;i++,j--){
        vector<int>l,r;
        for(int k=1;k<=n;k++)if(a[k][i])l.push_back(k);
        for(int k=1;k<=n;k++)if(a[k][j])r.push_back(k);
        if(l.size()+r.size()>=3){
            cout<<0<<endl;
            return;
        }
        if(l.size()==2){
            g[l[0]].push_back({l[1],1});
            g[l[1]].push_back({l[0],1});
        }
        if(r.size()==2){
            g[r[0]].push_back({r[1],1});
            g[r[1]].push_back({r[0],1});
        }
        if(l.size()==1&&r.size()==1){
            g[r[0]].push_back({l[0],0});
            g[l[0]].push_back({r[0],0});
        }
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            dfs(i,0);
            if(flag)return;
            (ans*=2)%=mod;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    fast
    int t;t=1;cin>>t;
    while(t--) {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll a[N];
void init(){
    a[0] = 1;
    for(int i = 1;i < 64;i++){
        a[i] = a[i - 1] * 2;
    }
}
void solve(){
    ll x;
    cin >> x;
    vector<ll>v;
    ll ans = 1;
    ll cnt = 0;
    v.push_back(ans);
    bool flag = 0;
    while(ans != x){
        if(ans + a[cnt] <= x){
            ans += a[cnt];
            v.push_back(ans);
        }
        if(flag){
            cnt--;
        }else{
            cnt++;
        }
        if(ans + a[cnt] > x){
            if(!flag)flag = 1;
        }
    }
    cout << v.size() << "\n";
    for(int i = v.size() - 1;i >= 0;i--){
        if(i)cout << v[i] << " ";
        else cout << v[i] << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}

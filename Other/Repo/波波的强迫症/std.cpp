#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll lca(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll x, y;
    exgcd(a, b, x, y);
    //cout << x << ' ' << y << "\n";
    ll gg = __gcd(a, b);
    ll bei = c / gg;
    ll xx = x * bei;
    ll yy = y * bei;
    ll kx = b / gg;
    ll ky = a / gg;
    //ll k = 1;
    // //cout << x << " " << y << "\n";
     ll k = -xx * 1.0 / (b / __gcd(a, b));
    xx = xx + k * kx;
    yy = yy - k * ky;
    //cout << xx << " " << yy << "\n";
    ll mod = a / __gcd(a, b);
    ll ans;
    yy = (yy % mod + mod) % mod;
    // if(yy % mod == 0) ans = 0;
    // else ans = mod - yy % mod;
    ans = (mod - yy % mod) % mod;
    cout << ans << " ";
    cout << ans * b + c << "\n";
    //cout << xx * a + b * yy << "\n";


    
}
int main()
{
    // freopen("5.in", "r" ,stdin );
    // freopen(" 5.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;

    cin >> t;

    while (t --)
    {
        solve();
    }
    return 0;
}
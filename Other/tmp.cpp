#include <bits/stdc++.h>
#define debug(a) cerr << #a << "=" << a << '\n';
#define pque priority_queue
#define ef emplace_front
#define eb emplace_back
#define pf push_front
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define arr(x) x.begin() + 1, x.end()
#define lb0(x, y) lower_bound(x.begin(), x.end(), y) - x.begin();
#define lb1(x, y) lower_bound(x.begin() + 1, x.end(), y) - x.begin();
#define rev(x) reverse(all(x))
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define rep(i, a, b) for(int i = a; i <= b; i++) 
#define per(i, a, b) for(int i = a; i >= b; i--) 
#define repp(i, a, b) for(int i = a; i < b; i++) 
#define perr(i, a, b) for(int i = a - 1; i >= b; i--) 
using namespace std;
using ll = long long;
using tpi = tuple<int, int, int>;
using tpl = tuple<ll, ll, ll>;
using tpd = tuple<double, double, double>;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using pll = pair<ll, ll>;
const int N = 2e6 + 10;
const int mod = 998244353;
void solve() {
    int n, m, L;
    cin >> n >> m;
    string s;
    cin >> s;
    auto manacher = [&](string s) -> vector<int> {
        string t = "$#";
        for (auto c : s) t += c, t += '#';
        t += '&';
        L = t.size();
        int R = 0, C;
        vector<int> r(L);//半径-1
        for (int i = 1; i < L - 1; i++) {
            if (i < R) r[i] = min(r[(C << 1) - i], r[C] + C - r[i]);//在边界内，说明对称位置可能合适
            else r[i] = 1;//不在边界内，重开
            while (i + r[i] >= 0 && i + r[i] < L && t[i + r[i]] == t[i - r[i]]) r[i]++;//扩展半径
            if (r[i] + i > R) {//更新右界和对应中心
                R = r[i] + i;
                C = i;
            }
        }
        return r;
    };
    auto res = manacher(s);
    vector<int> f1(n), f2(n);
    for (int i = n - 1; i >= 0; i--) {
        f1[i] = (i + 1 < n && s[i] == s[i + 1] ? f1[i + 1] : i + 1);//向右找到第一个不相等的字符
        f2[i] = (i + 2 < n && s[i] == s[i + 2] ? f2[i + 1] : i + 2);//向右找到第一个奇偶性相同且不相等的字符
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = 0;
        int l, r;
        cin >> l >> r;
        l--;
        int len = r - l;//询问区间长度
        if (f1[l] < r) {//[l, r]有不相等的字符
            int t = len - 1 - (len - 1) % 2;//<len的最长偶数
            if (t >= 2) ans += (t / 2) * (2 + t) / 2;  
        }
        if (f2[l] < r || f2[l + 1] < r) {
            int t = len - 1 - len % 2;//<len的最长奇数
            if (t >= 3) ans += (t / 2) * (3 + t) / 2;//1肯定是了，不用判
        }
        //长度=n:不和其它情况一样，只要有一处不合条件就可以判ans有值，而是需要判断整段是否是回文串
        //如果以字符串中心的回文半径>=字符串长度，那么该子串就是一个回文串
        if (res[l + r + 1] < len) ans += len;
        cout << ans << '\n';
    }
}  
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}
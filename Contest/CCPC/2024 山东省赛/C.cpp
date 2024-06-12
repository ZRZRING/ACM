#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define PII std::pair<i64, i64>

const i64 mod = 998244353;

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    #define l first
    #define r second
    std::vector<PII> a(n + 1);
	std::set<i64> s;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].l >> a[i].r;
		s.insert(a[i].l);
		s.insert(a[i].r);
    }
	std::vector<i64> S(1);
	for (auto x : s) {
		S.push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		a[i].l = std::lower_bound(S.begin(), S.end(), a[i].l) - S.begin();
		a[i].r = std::lower_bound(S.begin(), S.end(), a[i].r) - S.begin();
	}
	std::sort(a.begin() + 1, a.end(), [](PII a, PII b) {
		return a.l < b.l;
	});
	std::vector<i64> f(n + 1);
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		while (!q.empty() && q.top() < a[i].l) q.pop();
		i64 t = m - q.size();
		q.push(a[i].r);
		f[i] = f[i - 1] * t % mod;
	}
	std::cout << f[n] << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
#include <bits/stdc++.h>

using i64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<i64, i64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const i64 mod = 998244353;

int solve() {
	i64 n, c;
	std::cin >> n >> c;
	std::vector<i64> a(n + 1);
	i64 ans = (c + 1) * (c + 2) / 2;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		ans -= a[i] / 2 + 1 + c - a[i] + 1;
	}
	i64 odd = 0, even = 0;
	for (int i = 1; i <= n; i++) {
		odd += (a[i] % 2 == 1);
		even += (a[i] % 2 == 0);
		if (a[i] % 2 == 0) ans += even;
		else ans += odd;
	}
	std::cout << ans << endl;
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}
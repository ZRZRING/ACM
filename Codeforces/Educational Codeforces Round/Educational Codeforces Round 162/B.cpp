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
	i64 n, k;
	std::cin >> n >> k;
	std::vector<i64> t(n + 1), hp(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> t[i];
	}
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		hp[abs(x)] += t[i];
	}
	for (int i = 1; i <= n; i++) {
		hp[i] += hp[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		if (hp[i] > i * k) {
			return NO;
		}
	}
	return YES;
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
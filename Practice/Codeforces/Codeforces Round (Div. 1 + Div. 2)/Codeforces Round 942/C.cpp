#include <bits/stdc++.h>

using i64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<i64, i64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const i64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	i64 n, m;
	std::cin >> n >> m;
	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	auto check = [&](i64 x) {
		i64 ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += std::max(0ll, x - a[i]);
		}
		return ans <= m;
	};
	i64 l = 0, r = 1e12, ans = 0;
	while (l <= r) {
		i64 mid = l + r >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	i64 cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > ans) cnt++;
		m -= std::max(0ll, ans - a[i]);
		a[i] = std::max(a[i], ans);
	}
	cnt += m;
	std::cout << ans * n - n + 1 + cnt << endl;
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
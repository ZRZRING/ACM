#include <bits/stdc++.h>

using i64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<i64, i64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const i64 mod = 998244353;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> i64 lg(T x) {return (int)log10(x);}
template <class T> i64 log(T x) {return (int)log2(x);}
template <class T> i64 abs(T x) {return x < 0 ? -x : x;}
template <class T> i64 mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), pre(n + 2), suf(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] ^ a[i];
	}
	std::vector<std::vector<i64>> pre0(n + 2, std::vector<i64>(32));
	std::vector<std::vector<i64>> pre1(n + 2, std::vector<i64>(32));
	for (int i = 0; i <= 30; i++) {
		pre0[0][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 30; j++) {
			if (pre[i] >> j & 1) {
				pre0[i][j] = pre0[i - 1][j];
				pre1[i][j] = pre1[i - 1][j] + 1;
			} else {
				pre0[i][j] = pre0[i - 1][j] + 1;
				pre1[i][j] = pre1[i - 1][j];
			}
		}
	}
	std::vector<std::vector<i64>> suf0(n + 2, std::vector<i64>(32));
	std::vector<std::vector<i64>> suf1(n + 2, std::vector<i64>(32));
	for (int i = 0; i < 30; i++) {
		suf0[n + 1][i] = 1;
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j <= 30; j++) {
			if (suf[i] >> j & 1) {
				suf0[i][j] = suf0[i + 1][j];
				suf1[i][j] = suf1[i + 1][j] + 1;
			} else {
				suf0[i][j] = suf0[i + 1][j] + 1;
				suf1[i][j] = suf1[i + 1][j];
			}
		}
	}
	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = a[i], t = -1;
		while (x) {
			t++;
			x >>= 1;
		}
		if ((pre[i] >> t & 1) ^ (suf[i] >> t & 1)) {
			ans += pre0[i - 1][t] * suf0[i + 1][t] + pre1[i - 1][t] * suf1[i + 1][t];
		} else {
			ans += pre0[i - 1][t] * suf1[i + 1][t] + pre1[i - 1][t] * suf0[i + 1][t];
		}
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
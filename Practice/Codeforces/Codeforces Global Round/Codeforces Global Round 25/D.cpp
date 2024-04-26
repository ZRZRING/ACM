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
template <class T> i64 abs(T x) {return x < 0 ? -x : x;}
template <class T> i64 lg(T x) {return (int)log10(x);}
template <class T> i64 log(T x) {return (int)log2(x);}

int solve() {
	i64 n, k;
	std::vector<i64> ans;
	std::cin >> n >> k;
	if (n < 2ll * k - 1 && n != k) {
		std::cout << "NO" << endl;
		return 0;
	}
	std::cout << "YES\n2\n" << n - k + 1ll << ' ' << 1ll << endl;
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
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
	int n;
	std::cin >> n;
	std::vector<int> x(n + 1), y(n + 1);
	int c0 = 0, c1 = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> x[i] >> y[i];
		c0 = std::max(c0, x[i] - y[i]);
		c1 = std::max(c1, y[i]);
	}
	std::cout << c0 + c1 << endl;
	for (int i = 1; i <= c1; i++) putchar('1');
	for (int i = 1; i <= c0; i++) putchar('0');
	std::cout << endl;
	for (int i = 1; i <= n; i++) {
		std::cout << c1 - y[i] << endl;
	}
	return 0;
}

int main() {
	// Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}
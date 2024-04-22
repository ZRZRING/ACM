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
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int r = 0;
	std::vector<PII> ans;
	for (int i = 1; i <= n; i++) {
		r = std::max(r, i);
		for (int j = n; j > r; j--) {
			if (a[i] > a[j]) {
				ans.push_back({i, j});
				std::sort(a.begin() + i, a.begin() + j + 1);
				r = j;
			}
		}
	}
	std::cout << ans.size() << endl;
	for (auto [x, y] : ans) {
		std::cout << x << ' ' << y << endl;
	}
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
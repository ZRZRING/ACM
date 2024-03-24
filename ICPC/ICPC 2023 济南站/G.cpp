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

i64 qpow(i64 a, i64 x) {
	i64 res = 1;
	while (x) {
		if (x & 1) res = res * a % mod;
		a = a * a % mod;
		x >>= 1;
	}
	return res;
}

struct DSU {
	int n;

	std::vector<int> fa, size;

	DSU(int n) : n(n) {
		fa.resize(n + 1);
		size.resize(n + 1);
		std::iota(fa.begin(), fa.end(), 0);
		std::fill(size.begin(), size.end(), 1);
	}

	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}

	void merge(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (size[x] < size[y]) {
			fa[x] = y;
			size[y] += size[x];
		} else {
			fa[y] = x;
			size[x] += size[y];
		}
	}
};

int solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(2 * n + 1, std::vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		for (int j = 1; j <= m; j++) {
			a[i][j] = s[j - 1] - '0';
			a[i + n][j] = s[m - j] - '0';
		}
	}
	for (int j = 1; j <= m; j++) {
		std::vector<int> t;
		for (int i = 1; i <= n; i++) {
			if (a[i][j] || a[i][m - j + 1]) {
				t.push_back(i);
			}
		}
		for (int i = 1; i < t.size(); i++) {
			int x = find(t[i]), y = find(t[i - 1]);
			if (x != y) fa[x] = y;
		}
	}
	i64 cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i == find(i)) cnt++;
	}
	std::cout << qpow(2, cnt) << endl;
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
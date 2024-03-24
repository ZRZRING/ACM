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
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> e(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	std::vector<int> col(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> col[i];
	}
	std::vector<int> size(n + 1), son(n + 1);
	auto dfs1 = [&](auto self, int u, int last) -> void {
		size[u] = 1;
		for (auto v : e[u]) {
			if (v == last) continue;
			self(self, v, u);
			size[u] += size[v];
			if (size[v] > size[son[u]]) son[u] = v;
		}
	};
	dfs1(dfs1, 1, 1);
	auto dfs2 = [&](auto self, int u, int last, int keep) -> void {
		if (son[u]) {
			self(self, son[u], u, 1);
		}
	};
	dfs2(dfs2, 1, 1, 1);
	return 0;
}

int main() {
	Fast_IOS;
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
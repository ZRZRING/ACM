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

struct TREE {
	int n, flag = 0;

	std::vector<std::vector<int>> e, fa;
	
	std::vector<int> dep;
	
	TREE(int n) : n(n) {
		e.resize(n);
		fa.resize(n);
		dep.resize(n);
		for (int i = 0; i < n; i++) {
			fa[i].resize(21);
		}
	}

	void add(int u, int v) {
		e[u].push_back(v);
		e[v].push_back(u);
	}

	void dfs(int u, int last) {
		dep[u] = dep[last] + 1;
		for (int i = 1; i <= 20; i++) {
			if (!fa[u][i - 1]) break;
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
		}
		for (auto v : e[u]) {
			if (v == fa[u][0]) continue;
			fa[v][0] = u;
			dfs(v, u);
		}
	}

	int lca(int x, int y) {
		for (int i = dep[x] - dep[y], j = 0; i > 0; i >>= 1, j++) {
			if (i & 1) x = fa[x][j];
		}
		for (int i = dep[y] - dep[x], j = 0; i > 0; i >>= 1, j++) {
			if (i & 1) y = fa[y][j];
		}
		if (x != y) {
			for (int i = 20; i >= 0; i--) {
				if (fa[x][i] == fa[y][i]) continue;
				x = fa[x][i];
				y = fa[y][i];
			}
			x = fa[x][0];
		}
		return x;
	};
};

int solve() {
	int n, m, s;
	std::cin >> n >> m >> s;
	TREE t1(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		t1.add(u, v);
	}
	t1.dfs(s, s);
	
	for (int i = 1; i <= m; i++) {
		int x, y;
		std::cin >> x >> y;
		std::cout << t1.lca(x, y) << endl;
	}
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
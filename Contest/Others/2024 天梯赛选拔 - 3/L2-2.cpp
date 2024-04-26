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
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> e(n + 1);
	for (int i = 1; i <= m; i++) {
		int x, y;
		std::cin >> x >> y;
		e[x].push_back(y);
	}
	int dfn_cnt = 0, scc_cnt = 0;
	std::stack<int> s;
	std::vector<int> dfn(n + 1), low(n + 1), col(n + 1);
	auto dfs = [&](auto self, int u) -> void {
		s.push(u);
		dfn[u] = low[u] = ++dfn_cnt;
		for (auto v : e[u]) {
			if (!dfn[v]) {
				self(self, v);
				low[u] = std::min(low[u], low[v]);
			} else if (!col[v]) {
				low[u] = std::min(low[u], dfn[v]);
			}
		}
		if (dfn[u] == low[u]) {
			col[u] = ++scc_cnt;
			while (s.top() != u) {
				col[s.top()] = scc_cnt;
				s.pop();
			}
			s.pop();
		}
	};
	for (int i = 1; i <= n; i++) {
		if (!col[i]) dfs(dfs, i);
	}
	std::vector<int> d(n + 1);
	for (int u = 1; u <= n; u++) {
		// std::cout << col[u] << ' ';
		for (auto v : e[u]) {
			if (col[u] != col[v]) {
				d[col[v]]++;
			}
		}
	}
	// std::cout << endl;
	int ans = 0;
	for (int i = 1; i <= scc_cnt; i++) {
		if (!d[i]) ans++;
	}
	std::cout << ans;
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
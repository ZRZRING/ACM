#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

struct EDGE {
	int v; i64 t;
};

void solve() {
	int n = read(), m = read(), Q = read();
	std::vector<int> col(n + 1);
	for (int i = 1; i <= m; i++) col[read()] = 1;
	std::vector<EDGE> edge[n + 1];
	for (int i = 1; i < n; i++) {
		int u = read(), v = read(); i64 t = read();
		edge[u].push_back({v, t});
		edge[v].push_back({u, t});
	}
	while (Q--) {
		m = read();
		std::vector<bool> vis(n + 1);
		std::function<i64(int, int, i64)> dfs = [&](int u, int last, i64 c) -> i64 {
			if (col[u]) c = 0; i64 max = 0;
			for (auto [v, t] : edge[u]) {
				if (v == last) continue; max = std::max(max, dfs(v, u, c + t));
			}
			if (vis[u]) max = std::max(max, c);
			return max;
		};
		for (int i = 1; i <= m; i++) vis[read()] = 1;
		i64 ans = dfs(1, 0, 0);
		for (int i = 1; i <= n; i++) {
			if (col[i] == 1) continue;
			col[i] = 1; ans = std::min(ans, dfs(1, 0, 0)); col[i] = 0;
		}
		printf("%lld\n", ans);
	}
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}
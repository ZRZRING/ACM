#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))
#define count(x) __builtin_popcount(x)

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const i64 mod = 998244353;

void solve() {
	int n = read(), m = read();
	std::vector<std::vector<PII> > edge(n + 1);
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), t = read();
		edge[u].push_back({v, t});
		edge[v].push_back({u, t});
	}
	int cnt = 0;
	std::vector<bool> vis(n + 1, 0);
	auto dfs = [&](auto self, int u) -> void {
		vis[u] = 1; cnt++;
		for (auto [v, t] : edge[u]) if (!vis[v]) self(self, v);
	};
	dfs(dfs, 1);
	if (cnt != n) {printf("-1"); return;}
	std::vector<int> f(1 << n, 1e9);
	for (int S = 1; S < 1 << n; S++) {
		if (count(S) == 1) {
			f[S] = 1; continue;
		}
		for (int T = S; T; T = T - 1 & S) {
			for (int u = 1; u <= n; u++) {
				if ((T >> u - 1 & 1) == 0) continue;
				for (auto [v, t] : edge[u]) {
					if (((S ^ T) >> v - 1 & 1) == 0) continue;
					f[S] = std::min(f[S], f[T] + f[S ^ T] + count(T) * count(S ^ T) * t);
				}
			}
		}
	}
	printf("%d\n", f[(1 << n) - 1]);
}

int main() {
	for (int i = 1; i <= 10; i++) {
		freopen((std::to_string(i) + ".in").c_str(), "r", stdin);
		freopen((std::to_string(i) + ".out").c_str(), "w", stdout);
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>

using i64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<i64, i64>
#define ctz(x) __builtin_ctz(x)
#define count(x) __builtin_popcount(x)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const i64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<i64>> dis(n, std::vector<i64>(n, 1e9));
	for (int i = 1; i <= m; i++) {
		i64 u, v, t;
		std::cin >> u >> v >> t;
		u--;
		v--;
		dis[u][v] = std::min(dis[u][v], t);
		dis[v][u] = std::min(dis[v][u], t);
	}
	std::vector<std::vector<i64>> f(n, std::vector<i64>(1 << n, 1e9));
	std::vector<std::vector<i64>> g(n, std::vector<i64>(1 << n, 1e9));
	for (int S = 1; S < 1 << n; S++) {
		int c = count(S);
		if (c == 1) {
			int u = ctz(S);
			f[u][S] = 0;
		} else {
			for (int u = 0; u < n; u++) {
				if ((S >> u & 1) == 0) continue;
				for (int T = S - 1 & S; T; T = T - 1 & S) {
					if ((T >> u & 1) == 0) continue;
					f[u][S] = std::min(f[u][S], f[u][T] + g[u][S ^ T]);
				}
			}
		}
		for (int u = 0; u < n; u++) {
			if ((S >> u & 1) == 0) continue;
			for (int v = 0; v < n; v++) {
				if ((S >> v & 1) == 1) continue;
				g[v][S] = std::min(g[v][S], f[u][S] + dis[u][v] * (n - c) * c);
			}
		}
	}
	if (f[0][(1 << n) - 1] == 1e9) {
		std::cout << -1 << endl;
		return 0;
	}
	std::cout << f[0][(1 << n) - 1] << endl;
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
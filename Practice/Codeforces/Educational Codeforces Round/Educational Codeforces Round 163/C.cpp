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
	std::vector<std::string> s(2);
	std::vector<std::vector<int>> vis(2, std::vector<int>(n));
	std::cin >> s[0] >> s[1];
	std::queue<PII> q;
	q.push({0, 0});
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (vis[x][y]) continue;
		vis[x][y] = 1;
		if (x > 0 && s[x][y - 1] == '<') q.push({x, y - 2});
		if (x < n && s[x][y + 1] == '>') q.push({x, y + 2});
		q.push({x ^ 1, s[x ^ 1][y] == '<' ? y - 1 : y + 1});
	}
	return vis[1][n - 1] ? YES : NO;
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
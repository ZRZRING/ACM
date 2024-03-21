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

int main() {
	int T = read();
	while (T--) {
		i64 n = read();
		std::unordered_map<i64, i64> ans;
		std::function<i64(i64)> dfs = [&](i64 x) -> i64 {
			if (x == 1) return ans[x] = 0ll;
			if (x <= 3) return ans[x] = 1ll;
			if (ans.count(x)) return ans[x];
			return ans[x] = std::min(dfs(x / 2ll) + x % 2ll, dfs(x / 3ll) + x % 3ll) + 1ll;
		};
		dfs(n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}
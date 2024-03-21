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
		int n = read(), m = read();
		i64 d = read();
		std::vector<i64> a(n + 1);
		for (int i = 1; i <= n; i++) a[i] = read();
		std::priority_queue<i64, std::vector<i64>, std::greater<i64> > q;
		i64 ans = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] <= 0) continue;
			q.push(a[i]), sum += a[i];
			if (q.size() > m) sum -= q.top(), q.pop();
			ans = std::max(ans, sum - d * i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
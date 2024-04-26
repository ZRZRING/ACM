#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define PII std::pair<i64, i64>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const i64 N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		i64 n = read();
		int ans = 0;
		for (i64 i = 1; i <= 1e4; i++) {
			int cnt = 0;
			while (n % i == 0) cnt++, i++; ans = std::max(cnt, ans);
		}
		for (int j = 2; j <= 4; j++) {
			i64 c = pow(n, 1.0 / j);
			for (int i = c; i <= c + 1e3; i++) {
				int cnt = 0;
				while (n % i == 0) cnt++, i++; ans = std::max(cnt, ans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}